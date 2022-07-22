#include <bits/stdc++.h>
using namespace std;

string caesarCipher(string s, int k) 
{
    std::string result = "";

    for (char letter : s)
    {
        if ((letter >= 'a') and (letter <= 'z'))
        {
            int transform = (letter - 'a' + k) % 26;
            result.push_back(transform + 'a');
        }
        else if ((letter >= 'A') and (letter <= 'Z'))
        {
            int transform = (letter - 'A' + k) % 26;
            result.push_back(transform + 'A');
        }
        else
        {
            result.push_back(letter);
        }
    }

    return result;

}

int main()
{
    std::string text = "middle-Outz";
    std::cout << caesarCipher(text, 2) << std::endl;
    return 0;
}