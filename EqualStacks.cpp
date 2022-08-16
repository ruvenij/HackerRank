#include <bits/stdc++.h>

void markHeights(const std::vector<int>& inputStack, std::vector<int>& outputHeights)
{
    int currentTot = 0;
    for (int i = (inputStack.size() - 1); i >= 0; i--)
    {
        currentTot += inputStack[i];
        
        if (outputHeights.size() < (currentTot + 1))
        {
            outputHeights.resize(currentTot + 1, 0);
        }
        
        outputHeights[currentTot]++;
    }
};

int equalStacks(std::vector<int>& h1, std::vector<int>& h2, std::vector<int>& h3) {
    std::vector<int> counts;
    
    if ((h1.size() == 0) or (h2.size() == 0) or (h3.size() == 0))
        return 0;
    
    markHeights(h1, counts);  
    markHeights(h2, counts);  
    markHeights(h3, counts);  
    
    for (int i = (counts.size() - 1); i >= 0; i--)
    {
        if (counts[i] == 3)
            return i;
    }
    
    return 0;
}

int main()
{
    std::vector<int> h1 = {3, 2, 1, 1, 1};
    std::vector<int> h2 = {4, 3, 2};
    std::vector<int> h3 = {1, 1, 4, 1};

    std::cout << equalStacks(h1, h2, h3) << std::endl;

    return 0;
}