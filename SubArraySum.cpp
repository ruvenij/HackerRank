#include <bits/stdc++.h>

std::vector<int> maxSubarray(std::vector<int> arr)
{
    std::vector<int> ret = {0, 0};

    if (arr.size() == 0)
        return ret;

    int maxSum = 0;
    int maxSoFar = INT_MIN;
    int maxEndHere = 0;
    bool atLeastOnePositiveElementPresent = false;

    for (int val : arr)
    {
        maxEndHere += val;

        if (maxSoFar < maxEndHere)
            maxSoFar = maxEndHere;

        if (maxEndHere < 0)
            maxEndHere = 0;

        if (val >= 0)
        {
            maxSum += val;
            atLeastOnePositiveElementPresent = true;
        }
    }

    if (not atLeastOnePositiveElementPresent)
        maxSum = maxSoFar;

    ret[0] = maxSoFar;
    ret[1] = maxSum;

    return ret;
}

int main()
{
    std::vector<int> arr = {-1, 2, 3, -4, 5, 10};
    std::vector<int> ret = maxSubarray(arr);
    std::cout << ret[0] << " " << ret[1] << std::endl;

    arr.clear();
    ret.clear();

    arr = {-2, -3, -1, -4, -6};
    ret = maxSubarray(arr);
    std::cout << ret[0] << " " << ret[1] << std::endl;
    return 0;
}