#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(const std::string& text, int start, int end)
{
    while (start < end)
    {
        if (text[start] != text[end])
        {
            return false;    
        }
        
        start++;
        end--;
    }

    return true;
}

int palindromeIndex(string s) 
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            if (isPalindrome(s, start + 1, end))
            {
                return start;
            }

            if (isPalindrome(s, start, end - 1))
            {
                return end;
            }
        }
    }

    return -1;
}

int main()
{
    std::cout << palindromeIndex("bcbc") << std::endl;
    return 0;
}