#include<bits/stdc++.h>

using namespace std;
#include <vector>
#include <algorithm>

/* This is inefficiet

long sumXor(long n) 
{
    long counter = 0;
    for (long i = 0; i <= n; i++)
    {
        if ((n + i) == (n ^ i))
        {
            counter++;
        }
    }
    
    return counter;
}*/

/*
    (a + b) = (a ^ b) + (a & b) * 2
    a & b should be zero

    Should find the zero count
    1L << (zero count) Left shift operator

*/

long sumXor(long n) 
{
    long counter = 0;
    while(n > 0)
    {
        counter += (n % 2 == 0) ? 1 : 0;
        n /= 2;
    }
    
    return 1L << counter;
}

int main(int argc, char *argv[]) {
    cout << sumXor(8) << endl;
    return 0;
}