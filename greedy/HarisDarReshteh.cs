using System;
using System.Collections;
using System.Collections.Generic;

namespace Program 
{
    class Problem
    {
        static List<List<int>> result = new List<List<int>>();
        static void solve(string str) 
        {
            List<int> ans = new List<int>();
            Stack<Tuple<char, int>> st = new Stack<Tuple<char, int>>();
            for (int i=0; i<str.Length; i++) 
            {
                if (st.Count == 0) 
                {
                    st.Push(new Tuple<char, int>(str[i], i+1));
                    continue;
                } 
                while (st.Count != 0)
                {
                    if (str[i] >= st.Peek().Item1)
                    {
                        break;
                    }
                    ans.Add(st.Peek().Item2);
                    st.Pop();
                }
                st.Push(new Tuple<char, int>(str[i], i+1));
            }
            while (st.Count != 0) 
            {
                ans.Add(st.Peek().Item2);
                st.Pop();
            }
            result.Add(ans); 
        }
        static void Main(string[] args) 
        {
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i=0; i<n; i++)
            {
                string str = Console.ReadLine() ?? "";
                solve(str);
            }
            foreach (var ans in result) 
            {
                foreach (var i in ans) 
                {
                    Console.Write($"{i} ");
                }
                Console.WriteLine();
            }
                                
        }
    }
}
