#include <bits/stdc++.h>
using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B) 
{
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    for (int i = 0; i < A.size(); i++)
    {
        if ((A.at(i) + B.at(i)) < k)
        {
            return "NO";
        }
    }

    return "YES";
}

int main()
{
    vector<int> A = {0, 1};
    vector<int> B = {0, 2};
    int k = 1;

    std::cout << twoArrays(k, A, B) << std::endl;
    return 0;
}