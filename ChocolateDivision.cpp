#include <bits/stdc++.h>
using namespace std;

int birthday(vector<int> s, int d, int m) 
{
    int matchedCount = 0;
    
    int tot = 0;
    int startPos = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        tot += s.at(i);

        if ((i - startPos + 1) == m)
        {
            if (tot == d)
            {
                matchedCount++;
            }

            tot -= s.at(startPos);
            startPos++;
        }
    }
    
    return matchedCount;
}

int main()
{
    vector<int> A = {4};
   
    std::cout << birthday(A, 4, 1) << std::endl;
    return 0;
}