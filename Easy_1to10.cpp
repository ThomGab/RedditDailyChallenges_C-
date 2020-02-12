using System;
using System.IO;

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
        static void Generate_TotalTime(int workout_distance, int Upper_Split_Seconds, int Lower_Split_Seconds)
        {
            //Prints a range of total times for the workout, based on a 2 min per 100m split, to a 1:30 per 100m split.

            int Split_Time = Upper_Split_Seconds;
            TimeSpan Split_Time_Span;
            TimeSpan Time_Taken;

            for (Split_Time = Upper_Split_Seconds; Split_Time >= Lower_Split_Seconds; Split_Time -= 5)
            {
                Split_Time_Span = TimeSpan.FromSeconds(Split_Time);

                Time_Taken = TimeSpan.FromSeconds( (workout_distance / 100) * Split_Time );
                Console.WriteLine("{0}:{1} per 100m = {2:D2}h:{3:D2}m:{4:D2}s", Split_Time_Span.Minutes,
                    Split_Time_Span.Seconds, Time_Taken.Hours, Time_Taken.Minutes, Time_Taken.Seconds);
            }
        }

        static void Main(string[] args)
        {
            
            string User_Input;
            int complete = 0;
            int pool_size = 0;
            int variable_1 = 0;

            while (complete == 0)
            {

                Console.WriteLine("Welcome to Swimming Calculator!\n");

                Console.WriteLine("Please select a size of Pool");
                Console.WriteLine("1) 25m");
                Console.WriteLine("2) 33m");
                Console.WriteLine("3) 50m");

                Console.Write("\n>");
                variable_1 = Convert.ToInt16(Console.ReadLine());

                if ( (variable_1 < 1) || (variable_1 > 3))
                {
                    Console.WriteLine("Invalid Input, please only enter between 1 and 3");
                    complete = 0;
                }
                else
                {
                    switch (variable_1)
                    {
                        case (1):
                            pool_size = 25;
                            break;
                        case (2):
                            pool_size = 33;
                            break;
                        case (3):
                            pool_size = 50;
                            break;
                        default:
                            Console.WriteLine("Unknown Error");
                            break;
                    }
                    Console.WriteLine("_______________");
                    complete = 1;
                    variable_1 = 0;
                }
            }

            complete = 0;

            Console.WriteLine("\nGenerate a Workout based on the below:\n");

            Console.WriteLine("1) Total Distance");
            //Console.WriteLine("1) Total Time");

            //Validating Inputs
            while (complete == 0)
            {
                Console.Write("\n>");
                User_Input = Console.ReadLine();

                if ( /*(User_Input != "2") && */ (User_Input != "1"))
                {
                    Console.WriteLine("Invalid input, please only enter 1, or 2.");
                }

                else
                {
                    complete = 1;
                    if (User_Input == "1")
                    {
                        Console.WriteLine("How much distance (in meters) are you planning to cover in this session?");
                        User_Input = Console.ReadLine();
                        variable_1 = int.Parse(User_Input); //Total Distance stored
                        Console.WriteLine("Outputs are:\n");
                        Console.WriteLine("Lengths Required: {0}", variable_1/pool_size);
                        Generate_TotalTime(variable_1, 120, 90);
                        Console.WriteLine("_______________");
                    }
                }
            }

        }
    }

    class Easy_3
    {
        static void Main(string[] args)
        {
            string User_Input;
            char[] Input_arr;
            int Encrypt = 0;

            Console.WriteLine("Enter your input:");
            User_Input = Console.ReadLine();

            Console.WriteLine("Would you like to: \n1)Encrypt\n2)Decrypt\n>");
            Encrypt = Convert.ToInt16(Console.ReadLine());

            while (((Encrypt != 1) && (Encrypt != 2))) {
                    Console.WriteLine("Please only enter 1 or 2\n>");
                    Encrypt = Convert.ToInt16(Console.ReadLine());
                }

            Input_arr = User_Input.ToCharArray();

            Console.WriteLine("Output:");
            foreach (char c in Input_arr)
            {
                if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
                {
                        Console.Write("{0}", Convert.ToChar(c + 13));
                }
                else
                {
                    if ((c >= 'm' && c <= 'z') || (c >= 'M' && c <= 'Z'))
                    {
                            Console.Write("{0}", Convert.ToChar(c - 13));
                    }

                    else
                    {
                        Console.WriteLine("Please only enter between a-z and A-Z.");
                    }
                }

            }
        }
        
    }

    class Easy_4
    {
        static void Main()
        {
            char a;
            int length, number, i, y = 0;
            Random rnd = new Random();

            Console.WriteLine("How Many passwords would you like to generate?");
            number = Convert.ToInt16(Console.ReadLine());
            
            Console.WriteLine("What length would you like the passwords?");
            length = Convert.ToInt16(Console.ReadLine());

            for (i = 0; i < number; i++)
            {
                Console.WriteLine("\nOutput - Password {0}", i+1);
                for (y = 0; y <= length; y++)
                {
                    a = Convert.ToChar(rnd.Next(33, 126));
                    Console.Write("{0}",a);
                }
            }
        }
    }

    class Easy_5
    {
        class User
        {
            private string User_Name;
            private string Password;
        }

        static void Main()
        {
            string File_Location = "C:\\Users\\Thomas.Gabriel\\Desktop\\Deleteme.txt";
            string[] lines = File.ReadAllLines(File_Location);
            string[] Active_User_Pair = new string[2]; //Element 1 is Username, Element 2 is Password.

            string Username;
            string Password;

            

            Console.WriteLine("Login Screen\n_______________");
            Console.WriteLine("Please Enter Username:\n>");
            Username = Console.ReadLine();
            Console.WriteLine("Please Enter Password:\n>");
            Password = Console.ReadLine();

            foreach (string userPassPair in lines)
            {
                Active_User_Pair = userPassPair.Split(' ');

                if (Active_User_Pair[0] == Username)
                {
                    //Username Match found, does the password also match?
                    if (Active_User_Pair[1] == Password)
                    {
                        Console.WriteLine("User Login successful.");
                        break;
                    }
                    else
                    {
                        Console.WriteLine("Failed Login.");
                    }
                }
                else
                {
                    Console.WriteLine("Failed Login.");
                }
            }
            

        }
    }


    class Pokemon_Game
    {

        public static int RandomNumber(int min, int max)
        {
            Random random = new Random();
            return random.Next(min, max);
        }

        struct Pokemon
        {
            public string Name;
            public int Catch_Threshold;
            public int Run_Threshold;

            public Pokemon(string Name, int Catch_Threshold, int Run_Threshold)
            {
                this.Name = Name;
                this.Catch_Threshold = Catch_Threshold;
                this.Run_Threshold = Run_Threshold;
            }
        }

        static int Catch_Attempt(Pokemon Active_Pokemon)
        {

            int random_number = RandomNumber(1, 100);
            Console.WriteLine("You throw a ball au la Poke!\n(With {0}% Skillz))",random_number);

            if (random_number > Active_Pokemon.Catch_Threshold)

            {
                Console.WriteLine("CATCH SUCCESS!\n\n____________________");
                return 1;
            }
            else
            {
                Console.WriteLine("UTTER FAILURE. YOU.");
                return 0;
            }
        }

        static int Get_And_Validate_Input(int min, int max) // Battle Input
        {
            string user_input;
            int user_input_int;

            Console.Write(">");
            user_input = Console.ReadLine();
            user_input_int = Convert.ToInt16(user_input);

            if ((user_input_int < min) || (user_input_int > max))
            {
                Console.WriteLine("No Effect!");
                Console.WriteLine("Select between {0} and {1}", min, max);
                return -1;
            }
            else
            {
                return user_input_int;
            }
        }

        static void Main()
        {
            int walk_around = 1;
            int in_battle = 0;
            int battle_threshold = 33;
            int bat_stat = 0;
            int getting_input = 0;
            int input_recieved = -1;
            int pokemon_run_rand = 0;

            Pokemon[] Pokelist = new[]
            {
                new Pokemon("a Bulbasaur", 30, 30),
                new Pokemon("a Charmander", 30, 30),
                new Pokemon("a Squirtle", 30, 30),
                new Pokemon("an Abra", 60, 95)
            };

            Pokemon Active_Pokemon;

            Console.WriteLine("WELCOME TO POKEMON!\n");
            Console.WriteLine("Gotta Catch them all cunt.\n");
            Console.WriteLine("_________________\n");
            
            // Game Loop
            while (walk_around == 1)
            {
                Console.WriteLine("You are walking around like a lost mongrel.\n");
                Console.WriteLine("Will you continue to try to be the very best?\n");
                Console.WriteLine("1)Yes\t2)No\n");
                walk_around = Get_And_Validate_Input(1, 2);

                if (walk_around == 0)
                {
                    Console.WriteLine("You decide you will stop trying to be the best,");
                    Console.WriteLine("Like no one ever was,");
                    Console.WriteLine("You die in the dirt.\n\n");
                    Console.WriteLine("And no one remembers you.\n");
                    break;
                }
                else
                {
                    bat_stat = RandomNumber(0, 100);

                    if (bat_stat > battle_threshold)
                    {
                        in_battle = 1;
                        Console.WriteLine("FUCK ME A WILD POKEMON HAS APPEARED.");
                        bat_stat = RandomNumber(0, (Pokelist.Length));
                        Console.WriteLine("It's {0}!!!\n", Pokelist[bat_stat].Name);
                        Active_Pokemon = Pokelist[bat_stat];

                        while (in_battle == 1)
                        {
                            Console.WriteLine("What are you go do?");
                            Console.WriteLine("1) Throw a Poke Ball\t 2) Run\n");
                            getting_input = 1;

                            while (getting_input == 1)
                            {
                                while (input_recieved == -1)
                                {
                                    input_recieved = Get_And_Validate_Input(1, 2);
                                }
                                getting_input = 0;
                            }

                            if (input_recieved == 1)
                            {
                                // 1 for Successful, 0 for failure
                                if (Catch_Attempt(Active_Pokemon) == 1)
                                {
                                    in_battle = 0;
                                    battle_threshold = 0;
                                }
                                else
                                {
                                    pokemon_run_rand = RandomNumber(1, 100);
                                    if (pokemon_run_rand < Active_Pokemon.Run_Threshold)
                                    {
                                        Console.WriteLine("Balls. The Pokemon escaped. Running away at {0} mph.\n", pokemon_run_rand);
                                        Console.WriteLine("________________________________");
                                        in_battle = 0;
                                        battle_threshold = 0;
                                    }
                                    else
                                    {
                                        Console.WriteLine("The Pokemon stands there, staring blankly at you.\n");
                                        in_battle = 1;
                                    }
                                }
                            }
                            else
                            {
                                Console.WriteLine("You flee!");
                                in_battle = 0;
                                battle_threshold = 0;
                            }
                        }

                    }
                    else
                    {
                        Console.WriteLine("You see nothing but a shit tonne of grass.\n");
                    }
                }

            }
        }


                

    }
}
