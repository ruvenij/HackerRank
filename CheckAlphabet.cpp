#include <bits/stdc++.h>
using namespace std;

string pangrams(string s) 
{
    bool result[26] = {false};
    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s.at(i) and s.at(i) <= 'z')
        {
            int index = s.at(i) - 'a';
            result[index] = true;
        }
        else if ('A' <= s.at(i) and s.at(i) <= 'Z')
        {
            int index = s.at(i) - 'A';
            result[index] = true;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (not result[i])
        {
            std::cout << i << std::endl;
            return "not pangram";
        }
    }

    return "pangram";
}

int main()
{
    string str = "We promptly judged"
                 " antique ivory"
                 " buckles for the next prize";

    std::cout << pangrams(str) << std::endl;
    return 0;
}