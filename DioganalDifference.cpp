#include <bits/stdc++.h>

using namespace std;


int diogonalDifference(vector<vector<int>> a) {
    int diagon1 = 0;
    int diagon2 = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        diagon1 += a[i][i];
        diagon2 += a[i][a.size() - 1 - i];
    }

    return std::abs(diagon1 - diagon2);
}


int main()
{
    std::vector<std::vector<int>> a = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
    std::cout << diogonalDifference(a) << std::endl;

    return 0;
}

