#include <bits/stdc++.h>
using namespace std;

int pageCount(int n, int p) {
    if ( (n + 1) % 2 != 0) n++;
    return std::min((p / 2), (n - p) / 2);
}

int main()
{

    std::cout << pageCount(6, 5) << std::endl;
    return 0;
}