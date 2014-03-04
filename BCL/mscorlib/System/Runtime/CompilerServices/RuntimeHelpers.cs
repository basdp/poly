using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Runtime.CompilerServices
{
    class RuntimeHelpers
    {
        /// <summary>
        /// Provides a fast way to initialize an array from data that is stored in a module.
        /// </summary>
        /// <param name="array"></param>
        /// <param name="fldHandle"></param>
        // TODO: endianess
        [Poly.Internals.CompilerImplemented.InlineCode(@"
            struct SYSTEM__RUNTIMEFIELDHANDLE_proto *fldHandle = (struct SYSTEM__RUNTIMEFIELDHANDLE_proto *)parameter1;
	        int8_t *data = (int8_t *)fldHandle->addr;
            int8_t *arr = (int8_t *)parameter0;
            int arr_length = ((int32_t*)arr)[0];
            int arr_elemsize = ((int32_t*)arr)[0];
            int arr_offset = 2;
            int i = 0;
            if (arr_elemsize == 8) arr_offset = 1;
            for (; i < arr_length * arr_elemsize; i++) { arr[i + arr_offset] = data[i]; /*printf(""arr[%d + %d] = %d;\n"", i, arr_offset, data[i]);*/ }
            printf(""arr[0] = %d;\n"", ((int32_t *)arr)[1]);
printf(""arr[0] = %d;\n"", ((int32_t *)arr)[2]);
printf(""arr[0] = %d;\n"", ((int32_t *)arr)[3]);
printf(""arr[0] = %d;\n"", ((int32_t *)arr)[4]);

        ")]
        public static void InitializeArray(Array array, RuntimeFieldHandle fldHandle)
        { }

    }
}
