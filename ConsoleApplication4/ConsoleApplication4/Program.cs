using System;
using System.IO;

namespace ReadPatientRecords
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Id#\tPatient Name\tAmount");
            //Read each line and print
            foreach (string line in File.ReadLines("Patients.txt"))
            {
                Console.WriteLine("{0}", line);
            }
            Console.ReadKey();
        }
    }
}
