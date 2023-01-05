
using System;
using System.Threading;
using System.Collections.Generic;

namespace AStar
{
    class Pos
    {
        public int x;
        public int y;
        public int cost;
        public int g;
        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public Pos(int x, int y, int c, int g)
        {
            this.x = x;
            this.y = y;
            cost = c;
            this.g = g;
        }
        public Pos Copy()
        {
            return new Pos(x, y, cost, g);
        }
    }

    class AStar
    {
        public Pos startPos;
        public Pos endPos;
        public char[,] map = new char[9, 9];

        int[] dirY = new int[] { -1, 0, 1, 0, -1, 1, 1, -1 };
        int[] dirX = new int[] { 0, -1, 0, 1, -1, -1, 1, 1 };

        private List<Pos> openDir;
        private List<Pos> closeDir;

        public List<Pos> result;

        public AStar()
        {
            startPos = new Pos(0, 0);
            endPos = new Pos(0, 0);
            map = new char[9, 9];
        }
        public AStar(int sX, int sY, int eX, int eY, char[,] m)
        {
            startPos = new Pos(sX, sY);
            endPos = new Pos(eX, eY);
            map = m;

            AstarPath();
        }
        private int SetCost(Pos sP, Pos nP, Pos eP)
        {
            int g = (int)Math.Round(Math.Sqrt(Math.Abs(sP.x - nP.x) + Math.Abs(sP.y - sP.y)) * 10);
            int f = (int)Math.Round(Math.Sqrt(Math.Abs(nP.x - eP.x) + Math.Abs(nP.y - eP.y)) * 10);
            return f + g;
        }
        private int SetG(Pos sP, Pos nP, Pos eP)
        {
            return (int)Math.Round(Math.Sqrt(Math.Abs(sP.x - nP.x) + Math.Abs(sP.y - sP.y)) * 10);
        }

        public void AstarPath()
        {
            bool findingTarget = true;
            openDir = new List<Pos>();
            closeDir = new List<Pos>();
            result = new List<Pos>();
            closeDir.Add(startPos);
            for (int i = 0; i < dirX.Length; i++)
            {
                //맵 밖을 나가거나 ■인 경우 openDir에서 제외
                if ((startPos.x + dirX[i] >= 9 || startPos.x + dirX[i] < 0 || startPos.y + dirY[i] >= 9 || startPos.y + dirY[i] < 0) 
                    || map[startPos.y + dirY[i], startPos.x + dirX[i]] == '■')
                    continue;
                Pos nowPos = new Pos(startPos.x + dirX[i], startPos.y + dirY[i]);
                openDir.Add(new Pos(nowPos.x, nowPos.y, SetCost(startPos, nowPos, endPos), SetG(startPos, nowPos, endPos)));
            }
            //목표 경로에 닿을 때 까지
            while (findingTarget)
            {
                //최소 비용의 인접한 좌표로 nowPos를 이동
                int min = 0;
                for (int i = 0; i < openDir.Count; i++)
                {
                    if (openDir[min].cost > openDir[i].cost)
                        min = i;
                }
                
                Pos nowPos = new Pos(openDir[min].x, openDir[min].y);
                for (int i = 0; i < dirX.Length; i++)
                {
                    //맵 밖을 나가거나 ■거나 closeDir인 경우 제외
                    if ((nowPos.x + dirX[i] >= 9 || nowPos.x + dirX[i] < 0 || nowPos.y + dirY[i] >= 9 || nowPos.y + dirY[i] < 0) 
                        || map[nowPos.y + dirY[i], nowPos.x + dirX[i]] == '■')
                        continue;

                    if (openDir.Find(item => item.x == nowPos.x + dirX[i] && item.y == nowPos.y + dirY[i]) == null)
                    {
                        Pos temp = new Pos(nowPos.x + dirX[i], nowPos.y + dirY[i], SetCost(startPos, nowPos, endPos), SetG(startPos, nowPos, endPos));
                        if(closeDir.Find(item => item.x == temp.x && item.y == temp.y) == null)
                            openDir.Add(temp);
                    }
                }
                closeDir.Add(openDir[min].Copy());
                openDir.Remove(openDir[min]);
                for (int i = 0; i < closeDir.Count; i++)
                {
                    if (closeDir[i].x == endPos.x && closeDir[i].y == endPos.y)
                        findingTarget = false;
                }
                if(openDir.Count == 0)
                {
                    Console.WriteLine("경로 탐색 실패!");
                    return;
                }

            }

            foreach (var item in closeDir)
            {
                map[item.y, item.x] = '☆';
            }
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Console.Write(map[i, j]);
                }
                Console.WriteLine();
            }

            Pos now = endPos;
            result.Add(now);
            List<Pos> neighbor = new List<Pos>();
            while (true)
            {
                for (int i = 0; i < dirX.Length; i++)
                {
                    if (closeDir.Find(item => item.x == now.x + dirX[i] && item.y == now.y + dirY[i]) != null)
                        neighbor.Add(closeDir.Find(item => item.x == now.x + dirX[i] && item.y == now.y + dirY[i]));
                }

                int min = 0;
                if (neighbor.Count > 0)
                {
                    for (int i = 0; i < neighbor.Count; i++)
                    {
                        if (neighbor[min] == null || neighbor[i] == null)
                            continue;
                        if (neighbor[min].g > neighbor[i].g)
                        {
                            min = i;
                        }
                    }
                }
                now = neighbor[min];
                result.Add(neighbor[min]);
                closeDir.Remove(closeDir.Find(item => item.x == neighbor[min].x && item.y == neighbor[min].y));
                neighbor.Clear();
                if (now.x == startPos.x && now.y == startPos.y)
                    break;
            }
            result.Reverse();


            //Pos now = startPos;
            //result.Add(now.Copy());
            //List<Pos> neighbor = new List<Pos>();
            //while (now.x != endPos.x && now.y != endPos.y)
            //{
            //    for (int i = 0; i < dirX.Length; i++)
            //    {
            //        if (closeDir.Find(item => item.x == now.x + dirX[i] && item.y == now.y + dirY[i]) != null)
            //            neighbor.Add(closeDir.Find(item => item.x == now.x + dirX[i] && item.y == now.y + dirY[i]).Copy());
            //    }
            //    int min = 0;
            //    if (neighbor.Count > 0)
            //    {
            //        for (int i = 0; i < neighbor.Count; i++)
            //        {
            //            if (neighbor[min] == null || neighbor[i] == null)
            //                continue;
            //            if (neighbor[min].cost > neighbor[i].cost)
            //            {
            //                min = i;
            //            }
            //        }
            //    }
            //    Console.WriteLine(now.x +", "+ now.y);
            //    now = neighbor[min];
            //    result.Add(neighbor[min]);
            //    closeDir.Remove(neighbor[min]);
            //    neighbor.Clear();
            //}
        }



        static void Main(string[] args)
        {
            //char[,] map = new char[9, 9] {
            //{ '□', '□', '■', '□', '■', '□', '□', '□', '□', } ,
            //{ '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            //{ '□', '■', '■', '■', '■', '□', '□', '□', '□', } ,
            //{ '□', '■', '□', '□', '■', '□', '□', '□', '□', } ,
            //{ '□', '■', '■', '□', '■', '□', '□', '□', '□', } ,
            //{ '□', '□', '□', '□', '■', '■', '■', '□', '□', } ,
            //{ '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            //{ '■', '□', '■', '■', '■', '□', '□', '□', '□', } ,
            //{ '□', '□', '□', '□', '□', '□', '□', '□', '□', } };
                    char[,] map = new char[9, 9] {
            { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '■', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '■', '■', '■', '□', '□', } ,
            { '□', '□', '□', '□', '□', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '□', '□', '□', '□', '□', } ,
            { '□', '□', '□', '□', '□', '□', '□', '□', '□', } };
            AStar aStar = new AStar(0, 0, 6, 0, map);
            foreach (var item in aStar.result)
            {
                map[item.y, item.x] = '★';
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {

                        Console.Write(map[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
        }
    }
}

