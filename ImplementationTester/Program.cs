using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Xml;

namespace ImplementationTester
{
    class Program
    {
        static Dictionary<string, bool> CompiledTests = new Dictionary<string, bool>();

        static void Main(string[] args)
        {
            while (System.IO.Directory.Exists("tmp"))
            {
                System.IO.Directory.Delete("tmp", true);
                Thread.Sleep(100);
            }
            System.IO.Directory.CreateDirectory("tmp");

            InitializeEnvironment();

            XmlDocument testdef = new XmlDocument();
            testdef.LoadXml(File.ReadAllText(@"Tests\definitions.xml"));

            Console.WriteLine("Test                Result\n==========================");

            foreach (XmlElement elem in testdef.DocumentElement.ChildNodes)
            {
                string filename = elem.GetAttribute("filename");
                FileInfo fi = new FileInfo(filename);

                string parameters = "";
                if (elem.HasAttribute("parameters")) parameters = elem.GetAttribute("parameters");

                string basename = fi.Name.Substring(0, fi.Name.LastIndexOf("."));
                string displayname = basename + "." + parameters;
                if (!CompiledTests.ContainsKey(filename)) {
                    CompileCsToPolyExe(@"Tests\" + filename, @"Tests\" + basename + ".poly.exe");
                    if (!File.Exists(@"Tests\" + basename + ".poly.exe"))
                    {
                        Console.Write(displayname + new string(' ', 20 - displayname.Length));
                        Console.WriteLine("FAIL");
                        Console.WriteLine("  Compilation failed");
                        continue;
                    }
                    CompiledTests[filename] = true;
                }
                switch (elem.Name.ToLower())
                {
                        // TODO: performance test

                    case "expectoutput":
                        ExpectOutput(@"Tests\" + basename + ".poly.exe", parameters, elem.InnerText.Trim());
                        break;
                    default:
                        throw new FormatException("Unexpected Test Type: " + elem.Name);
                }
            }
            Console.ReadKey();
        }

        private static bool ExpectOutput(string executable, string output)
        {
            return ExpectOutput(executable, "", output);
        }

        private static bool ExpectOutput(string executable, string parameters, string expectedOutput)
        {
            expectedOutput = expectedOutput.Split(new char[] { '\n' }).Select(s => s.Trim()).Aggregate((i, j) => i + "\n" + j);

            var comp = new System.Diagnostics.ProcessStartInfo(executable, parameters);
            comp.RedirectStandardOutput = true;
            comp.RedirectStandardError = true;
            comp.CreateNoWindow = true;
            comp.UseShellExecute = false;
            var proc = new System.Diagnostics.Process();
            proc.StartInfo = comp;
            proc.Start();
            proc.WaitForExit();

            FileInfo fi = new FileInfo(executable);
            string testName = fi.Name.Substring(0, fi.Name.ToLower().LastIndexOf(".poly.exe"));
            string displayname = testName;
            if (parameters != "") displayname += "." + parameters;
            Console.Write(displayname + new string(' ', 20 - displayname.Length));

            string output = proc.StandardOutput.ReadToEnd().Trim();
            output = output.Split(new char[] { '\n' }).Select(s => s.Trim()).Aggregate((i, j) => i + "\n" + j);
            if (expectedOutput == output)
            {
                Console.WriteLine("PASS");
                return true;
            }
            else
            {
                Console.WriteLine("FAIL");
                Console.WriteLine("  got \"" + output.Replace("\n", ", ") + "\", but expected \"" + expectedOutput.Replace("\n", ", ") + "\"");
                return false;
            }
        }

        private static void CompileCsToPolyExe(string cs, string output)
        {
            FileInfo fi = new FileInfo(cs);
            string basename = fi.Name.Substring(0, fi.Name.LastIndexOf("."));
            CompilerSuite.Compile(cs, @"tmp\" + basename + ".exe");
            CompilerSuite.Compile(@"tmp\" + basename + ".exe", @"tmp");
            CompilerSuite.Compile(@"tmp\" + basename + ".c", @"tmp\" + basename + ".obj");
            CompilerSuite.Compile(@"tmp\" + basename + @".obj tmp\mscorlib.obj", output);
        }

        private static void InitializeEnvironment()
        {
            CompilerSuite.Compile(@"mscorlib_.dll", @"tmp");
            CompilerSuite.Compile(@"Poly.Internals.dll", @"tmp");
            CompilerSuite.Compile(@"tmp\mscorlib.c", @"tmp\mscorlib.obj");
        }
    }
}
