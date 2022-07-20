#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    int counter[100] = {0};
    std::vector<int> result(0);

    for (int a : arr)
    {
        counter[a]++;
    }

    for (int i = 0; i < 100; i++)
    {
        if (counter[i] > 0)
        {
            result.insert(result.end(), counter[i], i);
        }
    }
    
    return result;
}


int main()
{
    std::vector<int> a = {1, 1, 3, 2, 1};
    std::vector<int> b = countingSort(a);
    
    for (int c : b)
    {
        std::cout << c << " ";
    }
    
    return 0;
}

