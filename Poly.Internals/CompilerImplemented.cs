using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Poly.Internals.CompilerImplemented
{
    public class InlineCodeAttribute : Attribute
    {
        string lang;
        string code;
        bool replaceCompleteImplementation;


        public InlineCodeAttribute(string code, string lang = "C", bool replaceCompleteImplementation = true)
        {
            this.code = code;
            this.lang = lang;
            this.replaceCompleteImplementation = replaceCompleteImplementation;
        }

        public string GetLang()
        {
            return lang;
        }

        public string GetCode()
        {
            return code;
        }

        public bool GetReplaceCompleteImplementation()
        {
            return replaceCompleteImplementation;
        }
    }

    public class StructureCodeAttribute : Attribute
    {
        string lang = "C";
        string code = "";

        public StructureCodeAttribute(string code)
        {
            this.code = code;
        }

        public StructureCodeAttribute(string code, string lang)
        {
            this.lang = lang;
        }

        public string GetLang()
        {
            return lang;
        }

        public string GetCode()
        {
            return code;
        }
    }
}
