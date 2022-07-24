#include <bits/stdc++.h>
#include <string>

using namespace std;

long getNearestPower(long number)
{
    long double power = std::log2l(number);

    //This can also be found by if ((x & (x - 1)) == 0)
    if (std::ceil(power) == std::floor(power))
    {
        //The number is a power of 2
        return (number / 2);
    }

    long nearestPower = std::pow(2, std::floor(power));
    return (number - nearestPower);
}

string counterGame(long n) 
{
    int index = 0;
    long number = n;

    while(number > 0)
    {
        if (number == 1) break;

        number = getNearestPower(number);
        index++;
    }

    return (index % 2 == 0) ? "Richard" : "Louise";
}

int main()
{
    std::cout << counterGame(132) << std::endl;
    return 0;
}