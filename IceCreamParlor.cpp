#include <bits/stdc++.h>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) 
{
    std::vector<int> iceCreamOptions = {0};
    std::vector<int> results;
    int index = 1;
    
    if (m == 0) return results;
    
    for (int price : arr)
    {
        int optionTwoFlavorValue = (m - price);
        if (optionTwoFlavorValue <= 0) 
        {
            index++;
            continue;
        }
        
        int maxPrice = std::max(price, optionTwoFlavorValue);
        if (iceCreamOptions.size() < (maxPrice + 1))
        {
            iceCreamOptions.resize(maxPrice + 1, 0);
        }
        
        if (iceCreamOptions[optionTwoFlavorValue] > 0)
        {
            results.push_back(iceCreamOptions[optionTwoFlavorValue]);
            results.push_back(index);
            break;
        }
        else 
        {
            iceCreamOptions[price] = index;
        }
        
        index++;
    }
    
    
    return results;
}

int main()
{
    std::vector<int> arr = {1, 4, 5, 3, 2};
    std::vector<int> res = icecreamParlor(4, arr);

    for (int flavor : res)
    {
        std::cout << flavor << " ";
    }

    std::cout << std::endl;
    return 0;
}