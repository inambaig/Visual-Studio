using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[5];
            for (int i = 0; i < 5; i++)
            {
                Console.Write("Enter integer number " + (i + 1) + " : ");
                array[i] = int.Parse(Console.ReadLine());
            }

            int highest = array[0];
            int lowest = array[0];

            for (int i = 0; i < 5; i++)
            {
                if (array[i] > highest)
                    highest = array[i];
                if (array[i] < lowest)
                    lowest = array[i];
            }

            Console.WriteLine("The highest score is: " + highest);
            Console.WriteLine("The lowest score is: " + lowest);
        }
    }
}
