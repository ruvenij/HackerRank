#include<bits/stdc++.h>
using namespace std;

int anagram(string s) 
{
    if (s.size() % 2 != 0)
    {
        return -1;
    }
    
    int arrp[26] = {0};
    int arrq[26] = {0};
    
    for (int i = 0; i < (s.size() / 2); i++)
    {
        int val = s[i] - 'a';
        arrp[val]++;
    }
    
    for (int i = (s.size() / 2); i < s.size(); i++)
    {
        int val = s[i] - 'a';
        arrq[val]++;
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arrp[i] > arrq[i])
        {
            count += std::abs(arrp[i] - arrq[i]);
        }
    }
    
    return count;
}

int main()
{
    std::cout << anagram("aaabbb") << std::endl;
    return 0;
}