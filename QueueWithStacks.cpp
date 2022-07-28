#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*class Queue
{
    public:
        void enqueue(int value)
        {
            s1.push(value);
        }
        
        void dequeue()
        {
            fillElementsToSecondStack();
            
            if (not s2.empty()) s2.pop();
            
            fillElementsToFirstStack();
        }
        
        void printTop()
        {
            fillElementsToSecondStack();
            
            if (not s2.empty()) 
                std::cout << s2.top() << std::endl;

            fillElementsToFirstStack();
        }

        void fillElementsToSecondStack()
        {
            while(not s1.empty())
            {
                int topValue = s1.top();
                s1.pop();
                s2.push(topValue);
            }
        }

        void fillElementsToFirstStack()
        {
            while(not s2.empty())
            {
                int topValue = s2.top();
                s2.pop();
                s1.push(topValue);
            }
        }
    
    private:
        std::stack<int> s1, s2;   
    
};*/

/*class Queue
{
    public:
        void enqueue(int value)
        {
            if (s1.empty() and s2.empty()) 
            {
                currentTop = value;
            }
            
            if (s1.empty() and not (s2.empty()))
            {
                fillElementsToFirstStack();
            }
            
            s1.push(value);
        }
        
        void dequeue()
        {
            if (s1.empty() and s2.empty()) 
            {
                return;
            }

            if (s2.empty() and not (s1.empty()))
            {
                fillElementsToSecondStack();
            }
            
            if (not s2.empty()) s2.pop();
            if (not s2.empty()) currentTop = s2.top();
        }
        
        void printTop()
        {
            std::cout << currentTop << std::endl;
        }

        void fillElementsToSecondStack()
        {
            while(not s1.empty())
            {
                int topValue = s1.top();
                s1.pop();
                s2.push(topValue);
            }
        }

        void fillElementsToFirstStack()
        {
            while(not s2.empty())
            {
                int topValue = s2.top();
                s2.pop();
                s1.push(topValue);
            }
        }
    
    private:
        std::stack<int> s1, s2;  
        int currentTop = 0; 
    
};*/

class Queue
{
    public:
        void enqueue(int value)
        {
            s1.push(value);
        }
        
        void dequeue()
        {
            dequeCount++;
        }
        
        void printTop()
        {
            removeMessagesFromSecondQueue(dequeCount);
            fillElementsToSecondStack();
            dequeCount = 0;
            std::cout << s2.top() << std::endl;
        }

        void fillElementsToSecondStack()
        {
            if (not s2.empty())
            {
                return;
            }
            
            while(not s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        void removeMessagesFromSecondQueue(int count)
        {
            while(count > 0)
            {
                fillElementsToSecondStack();
                if (s2.empty()) return;
                s2.pop();
                count--;
            }
        }
    
    private:
        std::stack<int> s1, s2;  
        int dequeCount = 0;
    
};


int main() 
{
    int testCaseCount = 0, option = 0, value = 0;
    Queue stackQueue;
    /*std::cin >> testCaseCount;
    
    for (int i = 0; i < testCaseCount; i++)
    {
        std::cin >> option;
        
        if (option == 1)
        {
            std::cin >> value;
            stackQueue.enqueue(value);
        }
        else if (option == 2)
        {
            stackQueue.dequeue();
        }
        else if (option == 3)
        {
            stackQueue.printTop();
        }
    }*/

    stackQueue.enqueue(42);
    stackQueue.dequeue();
    stackQueue.enqueue(14);
    stackQueue.printTop();
    stackQueue.enqueue(28);
    stackQueue.printTop();
    stackQueue.enqueue(60);
    stackQueue.enqueue(78);
    stackQueue.dequeue();
    stackQueue.dequeue();

    
    return 0;
}
