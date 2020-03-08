using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyBestFriends
{
    class MyBestFriendsFile
    {
        public static void Main(String[] args)
        {
            String[] arr = new String[5];
            arr[0] = "Frank";
            arr[1] = "Danial";
            arr[2] = "Mohammed";
            arr[3] = "Sarah";
            arr[4] = "Pedro";

            string path = @"BFF.txt";

            if (File.Exists(path))
            {
                path = "BFF-NEW.txt";
            }
            FileStream fileStream = File.Create(path);
            StreamWriter sw = new StreamWriter(fileStream);
            for (int i = 0; i < 5; i++)
            {
                sw.WriteLine(arr[i]);
            }
            sw.Close();
            fileStream.Close();
            Console.Read();
        }
    }
}
