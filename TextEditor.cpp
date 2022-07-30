#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int operationCount = 0, operation = 0, deleteCharCountFromEnd = 0, charIndexToPrint = 0;
    std::cin >> operationCount;
    std::stack<std::string> history;
    std::string currentString = "", appendText = "";

    for (int i = 0; i < operationCount; i++)
    {
        std::cin >> operation;

        switch (operation)
        {
        case 1:
            std::cin >> appendText;
            history.push(currentString);
            currentString = (currentString + appendText);
            break;

        case 2:
            std::cin >> deleteCharCountFromEnd;
            history.push(currentString);
            currentString = currentString.substr(0, (currentString.size() - deleteCharCountFromEnd));
            break;

        case 3:
            std::cin >> charIndexToPrint;
            std::cout << currentString[charIndexToPrint - 1] << std::endl;
            break;
        
        case 4:
            currentString = history.top();
            history.pop();
            break;
        
        default:
            break;
        }
    }
    return 0;
}
