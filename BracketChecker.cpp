#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string isBalanced(string s) {
    std::stack<char> bracketChecker;
    
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == '{') or (s[i] == '(') or (s[i] == '['))
        {
            bracketChecker.push(s[i]);
            continue;
        }
        
        if (bracketChecker.empty()) return "NO";
        
        if (((s[i] == '}') and (bracketChecker.top() != '{')) or 
            ((s[i] == ']') and (bracketChecker.top() != '[')) or 
            ((s[i] == ')') and (bracketChecker.top() != '('))) 
        {
            return "NO";
        }
        
        bracketChecker.pop();
    }
    
    if (not bracketChecker.empty()) return "NO";
    
    return "YES";
};

std::string checkString(std::string s)
{
    bool replaced = false;
    while (true)
    {
        replaced = false;
        if (s.size() == 0) return "YES";

        auto len = s.find("[]");
        if (len != std::string::npos)
        {
            s.replace(len, 2, "");
            replaced = true;
        }

        len = s.find("()");
        if (len != std::string::npos)
        {
            s.replace(len, 2, "");
            replaced = true;
        }

        len = s.find("{}");
        if (len != std::string::npos)
        {
            s.replace(len, 2, "");
            replaced = true;
        }

        if (not replaced) return "NO";
    }

    return "YES";
}



int main()
{
    std::cout << isBalanced("{(([])[])[]}") << std::endl;
    std::cout << checkString("{(([])[])[]}") << std::endl;
    return 0;
}
