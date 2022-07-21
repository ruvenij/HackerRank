#include<bits/stdc++.h>

using namespace std;
#include <vector>
#include <algorithm>

int sockMerchant(int n, vector<int> ar) {
    vector<int> sockSum(101, 0);
    int matchCount = 0;
    
    for (int value : ar)
    {
        sockSum[value]++;
    }
    
    for (int sockValue : sockSum)
    {
        matchCount += std::floor(sockValue / 2);
    }
    
    return matchCount;
}

int main(int argc, char *argv[]) {
    vector<int> arr = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout << sockMerchant(9, arr) << endl;
    return 0;
}