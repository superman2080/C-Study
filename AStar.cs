using System;
using System.Threading;
using System.Collections.Generic;

namespace AStar
{
    class AStar
    {
        public int posX = 0;
        public int posY = 0;
        public int endPosX = 0;
        public int endPosY = 0;


        List<int> pathX = new List<int>();
        List<int> pathY = new List<int>();

        public char[,] map = new char[9, 9];


        public void Render()
        {
            map = new char[9, 9] {
        { '□', '□', '■', '□', '■', '□', '□', '□', '□', } ,
        { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
        { '□', '■', '■', '■', '■', '□', '□', '□', '□', } ,
        { '□', '■', '□', '□', '■', '□', '□', '□', '□', } ,
        { '□', '■', '■', '□', '■', '□', '□', '□', '□', } ,
        { '□', '□', '□', '□', '■', '■', '■', '□', '□', } ,
        { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
        { '■', '□', '■', '■', '■', '□', '□', '□', '□', } ,
        { '□', '□', '□', '□', '□', '□', '□', '□', '□', } };
            map[posY, posX] = '●';
            map[endPosY, endPosX] = '★';

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    System.Console.Write(map[i, j]);
                }
                System.Console.WriteLine();
            }
        }

        private char AstarPath(int posX, int posY, int endPosX, int endPosY)
        {
            List<char> openedDir = new List<char>();
            Dictionary<char, double> result = new Dictionary<char, double>();
            char dir = '-';
            if (endPosX == posX && endPosY == posY)
                return '!';
            //오른쪽
            if (posX + 1 < 9 && !map[posY, posX + 1].Equals('■'))
                openedDir.Add('R');

            //왼쪽
            if (posX - 1 >= 0 && !map[posY, posX - 1].Equals('■'))
                openedDir.Add('L');

            //아래쪽
            if (posY + 1 < 9 && !map[posY + 1, posX].Equals('■'))
                openedDir.Add('D');

            //위쪽
            if (posY - 1 >= 0 && !map[posY - 1, posX].Equals('■'))
                openedDir.Add('U');
            

            for (int i = 0; i < openedDir.Count; i++)
            {
                bool isExistPath = false;
                switch (openedDir[i])
                {

                    case 'R':
                        for (int x = 0; x < pathX.Count; x++)
                        {
                            if (pathX[x] == posX + 1 && pathY[x] == posY)
                            {
                                isExistPath = true;
                                break;
                            }
                        }
                        if (isExistPath == false)
                            result.Add('R', Math.Sqrt(Math.Abs(Math.Pow(endPosX - posX + 1, 2) + Math.Pow(endPosY - posY, 2))));
                        break;
                    case 'L':
                        for (int x = 0; x < pathX.Count; x++)
                        {
                            if (pathX[x] == posX - 1 && pathY[x] == posY)
                            {
                                isExistPath = true;
                                break;
                            }
                        }
                        if (isExistPath == false)
                            result.Add('L', Math.Sqrt(Math.Abs(Math.Pow(endPosX - posX - 1, 2) + Math.Pow(endPosY - posY, 2))));
                        break;
                    case 'D':
                        for (int x = 0; x < pathX.Count; x++)
                        {
                            if (pathX[x] == posX && pathY[x] == posY + 1)
                            {
                                isExistPath = true;
                                break;
                            }
                        }
                        if (isExistPath == false)
                            result.Add('D', Math.Sqrt(Math.Abs(Math.Pow(endPosX - posX, 2) + Math.Pow(endPosY - posY + 1, 2))));
                        break;
                    case 'U':
                        for (int x = 0; x < pathX.Count; x++)
                        {
                            if (pathX[x] == posX && pathY[x] == posY - 1)
                            {
                                isExistPath = true;
                                break;
                            }
                        }
                        if (isExistPath == false)
                            result.Add('U', Math.Sqrt(Math.Abs(Math.Pow(endPosX - posX, 2) + Math.Pow(endPosY - posY - 1, 2))));
                        break;
                    default:
                        break;
                }
            }

            double dist = 0;
            foreach (var kvp in result)
            {
                if (kvp.Value > dist)
                {
                    dir = kvp.Key;
                    dist = kvp.Value;
                }
            }

            switch (dir)
            {

                case 'R':
                    pathX.Add(posX + 1);
                    pathY.Add(posY);
                    break;
                case 'L':
                    pathX.Add(posX - 1);
                    pathY.Add(posY);
                    break;
                case 'D':
                    pathX.Add(posX);
                    pathY.Add(posY + 1);
                    break;
                case 'U':
                    pathX.Add(posX);
                    pathY.Add(posY - 1);
                    break;
                case '-':
                    pathX.Clear();
                    pathY.Clear();
                    break;
                    
                default:
                    break;
            }

            return dir;

        }

        static void Main(string[] args)
        {
            AStar program = new AStar();

            program.posX = 0;
            program.posY = 0;
            program.endPosX = 8;
            program.endPosY = 8;

            while (true)
            {
                System.Console.Clear();

                char dir = program.AstarPath(program.posX, program.posY, program.endPosX, program.endPosY);

                if (dir == '!')
                    break;

                switch (dir)
                {
                    case 'R':
                        System.Console.WriteLine('R');
                        program.posX++;
                        break;
                    case 'L':
                        System.Console.WriteLine('L');
                        program.posX--;
                        break;
                    case 'D':
                        System.Console.WriteLine('D');
                        program.posY++;
                        break;
                    case 'U':
                        System.Console.WriteLine('U');
                        program.posY--;
                        break;
                    case '-':
                        System.Console.WriteLine("경로 오류");
                        break;
                    default:
                        break;
                }


                program.Render();
                Thread.Sleep(1000);
            }
        }
    }
}
