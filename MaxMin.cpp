#include <bits/stdc++.h>
using namespace std;

int maxMin(int k, vector<int> arr) {
    int unfairness = INT_MAX;
    
    std::sort(arr.begin(), arr.end());
    
    for (int i = 0; i < (arr.size() - k + 1); i++)
    {
        if (unfairness > (arr[i + k - 1] - arr[i]))
        {
            unfairness = (arr[i + k - 1] - arr[i]);
        }
    }
    
    return unfairness;
}

int main()
{
    std::vector<int> arr = {10, 100, 300, 200, 1000, 20, 30};
    std::cout << maxMin(3, arr) << std::endl;
}