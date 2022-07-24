#include<bits/stdc++.h>
using namespace std;

int getTotalX(vector<int> a, vector<int> b) 
{    
    std::sort(b.begin(), b.end());
    int count = 0;
    
    for (int number = 1; number <= b[b.size() - 1]; number++)
    {
        bool validNumberFoundFromSetOne = true;
        
        for(int i = 0; i < b.size(); i++)
        {
            if (b[i] % number != 0)
            {
                validNumberFoundFromSetOne = false;
                break;
            }
        }
              
        if (not validNumberFoundFromSetOne) continue;
        
        bool validNumberFoundFromSetTwo = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (number % a[i] != 0)
            {
                validNumberFoundFromSetTwo = false;
                break;
            }
        }
        
        if (validNumberFoundFromSetTwo) count++;
    }
    
    return count;
}

int main()
{
    std::vector<int> A = {1};
    std::vector<int> B = {100};
    std::cout << getTotalX(A, B) << std::endl;
    return 0;
}