using System;

namespace ConsoleApplication4
{
    class TypingGrades
    {
        static void Main(string[] args)
        {
            int[] words = new int[5] { 0, 16, 31, 51, 76 };
            string[] grade = new string[5] { "F", "D", "C", "B", "A" };

            Console.Write("Enter number of words typed: ");
            int wordsTyped = Convert.ToInt32(Console.ReadLine());
            if (wordsTyped >= words[0] && wordsTyped < words[1])
            {
                Console.WriteLine("");
                Console.WriteLine("Typing {0} words per minute: Grade {1}", wordsTyped, grade[0]);
            }
            else if (wordsTyped >= words[1] && wordsTyped < words[2])
            {
                Console.WriteLine("");
                Console.WriteLine("Typing {0} words per minute: Grade {1}", wordsTyped, grade[1]);
            }
            else if (wordsTyped >= words[2] && wordsTyped < words[3])
            {
                Console.WriteLine("");
                Console.WriteLine("Typing {0} words per minute: Grade {1}", wordsTyped, grade[2]);
            }
            else if (wordsTyped >= words[3] && wordsTyped < words[4])
            {
                Console.WriteLine("");
                Console.WriteLine("Typing {0} words per minute: Grade {1}", wordsTyped, grade[3]);
            }
            else if (wordsTyped >= words[4])
            {
                Console.WriteLine("");
                Console.WriteLine("Typing {0} words per minute: Grade {1}", wordsTyped, grade[4]);
            }
        }
    }
}

