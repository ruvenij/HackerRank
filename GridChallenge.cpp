
#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
        {
            return true;
        }
    }

    return false;
}

string gridChallenge(vector<string> grid) 
{
    for (int i = 0; i < grid.size(); i++)
    {
        std::sort(grid[i].begin(), grid[i].end());
    }

    if (std::is_sorted(grid.begin(), grid.end(), comp))
    {
        return "YES";
    }

    return "NO";
}

int main()
{
    std::vector<std::string> input = {"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"kc", "iu"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"uxf", "vof", "hmp"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"hcd", "awc", "shm"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"sur", "eyy", "gxy"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"nyx", "ynx", "xyt"};
    std::cout << gridChallenge(input) << std::endl;

    input.clear();
    input = {"vpvv", "pvvv", "vzzp", "zzyy"};
    std::cout << gridChallenge(input) << std::endl;

    return 0;
}