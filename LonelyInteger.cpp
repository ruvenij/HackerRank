#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(vector<int> a) {
    int lonelyValue = 0;

    for (int value : a)
    {
        lonelyValue ^= value;
    }

    return lonelyValue;
}


int main()
{
    std::vector<int> a = {1, 2, 3, 4, 3, 2, 1};

    std::cout << lonelyinteger(a) << std::endl;

    return 0;
}

