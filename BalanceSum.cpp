#include <bits/stdc++.h>

using namespace std;

string balancedSums(vector<int> arr) 
{
    int leftSum = 0;
    int rightSum = 0;
    
    for (int val : arr)
    {
        rightSum += val;
    }
    
    for (int val : arr)
    {
        rightSum -= val;
        
        if (rightSum == leftSum)
        {
            return "YES";
        }
        
        leftSum += val;
    }
    
    return "NO";
};

int main()
{
    std::vector<int> a = {1, 2, 3};
    std::cout << balancedSums(a) << std::endl;

    a.clear();
    a = {1, 2, 3, 3};
    std::cout << balancedSums(a) << std::endl;
    return 0;
}