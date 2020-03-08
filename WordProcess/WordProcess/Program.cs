using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WordProcess
{
    class Program
    {
        public static void CountAndSort(String []arr)
        {
            int size = arr.Length;
            Array.Sort<String>(arr);

            Console.WriteLine("Total Number of words : " + size);
            Console.WriteLine("Words : ");
            for (int i = 0; i < size; i++) 
            {
                Console.WriteLine(arr[i]);
            }
        }
        static void Main(string[] args)
        {
            String[] arr2 = new String[2];

            arr2[0] = "QWERT";
            arr2[1] = "POIUY";
            CountAndSort(arr2);
            Console.WriteLine();
            Console.WriteLine();
            String[] arr5 = new String[5];

            arr5[0] = "QWERT";
            arr5[1] = "POIUY";
            arr5[2] = "TFGHJN";
            arr5[3] = "LKJGYT";
            arr5[4] = "TFGHBN";
            CountAndSort(arr5);
        }
    }
}
