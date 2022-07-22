#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    std::vector<std::vector<int>> container{(unsigned)n};
    std::vector<int> result;
    int lastAnswer = 0;
    
    for (auto vec : queries)
    {
        if (vec[0] == 1)
        {
            int idx = (vec[1] ^ lastAnswer) % n;
            container[idx].push_back(vec[2]);
        }
        else if (vec[0] == 2)
        {
            int idx = ((vec[1] ^ lastAnswer) % n);
            int idy = (vec[2] % container[idx].size());
            lastAnswer = container[idx][idy];
            result.push_back(lastAnswer);
        }
    }
    
    return result;
}

int main()
{
    vector<vector<int>> vec = {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
    std::vector<int> result = dynamicArray(2, vec);

    for (int res : result)
    {
        std::cout << res << std::endl;
    }
}