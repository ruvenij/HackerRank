 #include <bits/stdc++.h>
 #include <string>

using namespace std;
 
int getSuperDigit(long number)
{
    if (number < 10) return number;

    long sum = 0;
    long internalSum = number;
    while (internalSum > 0)
    {
        sum += internalSum % 10;
        internalSum /= 10;
    }

    return getSuperDigit(sum);
};

int superDigit(string n, int k) 
{
    long sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += (n[i] - '0');
    }
    sum *= k;
    
    return getSuperDigit(sum);
}

int main()
{
    std::cout << superDigit("593", 10) << std::endl;
    return 0;
}
