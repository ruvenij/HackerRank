#include <bits/stdc++.h>
using namespace std;

int flippingMatrix(vector<vector<int>> matrix) {
    int n = (matrix.size() / 2);
    int sum = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {    
        for (int j = 0; j < n; j++)
        {
            max = 0;

            max = std::max(matrix[i][j], max);
            max = std::max(matrix[i][2 * n - 1 - j], max);
            max = std::max(matrix[2 * n - 1 - i][j], max);
            max = std::max(matrix[2 * n - 1 - i][2 * n - 1 - j], max);
            
            sum +=max;
        }
    }
    
    return sum;
}

int main()
{
    vector<vector<int>> A = {{112, 42, 83, 119}, {56, 125, 56, 49}, {15, 78, 101, 43}, {62, 98, 114, 108}};

    std::cout << flippingMatrix(A) << std::endl;
    return 0;
}
