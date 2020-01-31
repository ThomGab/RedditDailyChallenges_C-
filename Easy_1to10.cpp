using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Reddit_Daily_Programmer_Challenges_Easy_1_10
{
    class Easy_1
    {
        class User
        {
            public string name;
            public string age;
            public string username;
        }

        static void Enter_User (User input){
            Console.WriteLine("Please Enter your name, age and username.");

            Console.WriteLine("Name: ");
            input.name = Console.ReadLine();

            Console.WriteLine("Age: ");
            input.age = Console.ReadLine();

            Console.WriteLine("Username: ");
            input.username = Console.ReadLine();
        }

        static void Main(string[] args)
        {
            string add_user_prompt;
            int complete = 0;

            while (complete == 0)
            {
                Console.WriteLine("Would you like to add a User to the database? (Y/N)");
                add_user_prompt = Console.ReadLine();

                if ((string.Equals(add_user_prompt, "Y")) || (string.Equals(add_user_prompt, "y")))
                {
                    User New = new User();
                    Enter_User(New);
                    Console.WriteLine("Your Name is {0}, your Age is {1} and your username is {2}", New.name, New.age, New.username);
                    string write_data = (New.age + " " + New.name + " " + New.username + "\n");
                    File.WriteAllText("C:\\Users\\Thomas.Gabriel\\Desktop\\Users.txt", (write_data));
                }

                else
                {
                    if ( (string.Equals(add_user_prompt,"N")) || string.Equals(add_user_prompt, "n") )
                    {
                        complete = 1;
                    }
                    else
                    {
                        Console.WriteLine("Please only enter valid characters");
                    }
                }

            }
        }
    }




    class Easy_2
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World 2!");
            Console.ReadKey();
        }
    }
}
