#include <bits/stdc++.h>

using namespace std;

int lastPrime = 1;

int getNextPrime()
{
    int currentNumber = (lastPrime + 1);
    bool isPrime = true;
    
    while (currentNumber < INT_MAX)
    {
        isPrime = true;
        for (int i = 2; i < currentNumber; i++)
        {
            if (currentNumber % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime)
        {
            lastPrime = currentNumber;
            return currentNumber;
        }
        
        currentNumber++;
    }
    
    return -1;
}

vector<int> waiter(vector<int> number, int q) 
{
    std::vector<int> answers;
    std::vector<int> C = number;
    std::vector<int> A;
    
    for (int i = 0; i < q; i++)
    {
        int currentPrimeNumber = getNextPrime();
        std::cout << "Current Prime : " << currentPrimeNumber << std::endl;
        A.clear();
        
        if (i % 2 == 0)
        {
            for (int j = 0; j < C.size(); j++)
            {
                if (C[j] % currentPrimeNumber == 0)
                {
                    answers.push_back(C[j]);
                }
                else
                {
                    A.push_back(C[j]);
                }
            }

            C.clear();
            C = A;
        }
        else
        {
            for (int j = (C.size() - 1); j >= 0; j--)
            {
                if (C[j] % currentPrimeNumber == 0)
                {
                    answers.push_back(C[j]);
                }
                else
                {
                    A.push_back(C[j]);
                }
            }

            C.clear();
            for (auto it = A.rbegin(); it != A.rend(); it++)
            {
                C.push_back(*it);
            }
        }        
    }

    //Move remaining elements
    for (int remainingPlateNum : A)
    {
        answers.push_back(remainingPlateNum);
    }
    
    return answers;
}

int main()
{
    std::vector<int> plates = {2, 3, 4, 5, 6, 7};
    std::vector<int> results = waiter(plates, 3);
    for (int plateNum : results)
    {
        std::cout << plateNum << " ";
    }
    std::cout << std::endl;

    plates.clear();
    results.clear();
    lastPrime = 1;
    
    plates = {3, 4, 7, 6, 5};
    results = waiter(plates, 1);

    for (int plateNum : results)
    {
        std::cout << plateNum << " ";
    }
    std::cout << std::endl;

    plates.clear();
    results.clear();
    lastPrime = 1;
    
    plates = {3, 3, 4, 4, 9};
    results = waiter(plates, 2);

    for (int plateNum : results)
    {
        std::cout << plateNum << " ";
    }
    std::cout << std::endl;

    plates.clear();
    results.clear();
    lastPrime = 1;

    plates = {80, 37, 86, 79, 8, 39, 43, 41, 15, 33, 30, 15, 45, 55, 61, 74, 49, 49, 20, 66, 77, 19, 85, 44, 81, 82, 27, 5, 36, 83, 91, 45, 
        39, 44, 19, 44, 71, 49, 8, 66, 81, 40, 29, 60, 35, 31, 44};
    results = waiter(plates, 21);

    for (int plateNum : results)
    {
        std::cout << plateNum << " ";
    }
    std::cout << std::endl;

    plates.clear();
    results.clear();
    lastPrime = 1;
    
    plates = {9, 7, 2, 13, 3, 11, 4, 5, 6, 11};
    results = waiter(plates, 3);

    for (int plateNum : results)
    {
        std::cout << plateNum << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*
80 86 8 30 74 20 66 44 82 36 44 44 8 66 40 60 44 81 39 45 27 81 45 15 33 15 39 |55 85 5 35 |49 91 77 49 49 | 19 19 29 31 37 41 43 61 71 79 83
80 86 8 30 74 20 66 44 82 36 44 44 8 66 40 60 44 81 39 45 27 81 45 15 33 15 39 55 85 5 35 49 91 77 49 49 19 19 29 31 37 41 43 61 71 79 83 
80 86 8 30 74 20 66 44 82 36 44 44 8 66 40 60 44 |81 39 45 27 81 45 15 33 15 39 | 35 5 85 55 |49 49 77 91 49 | 19 19 29 31 37 41 43 61 71 79 83 

{0, 37, 0, 79, 0, 0, 43, 41, 0, 0, 0, 0, 0, 55, 61, 0, 49, 49, 0, 0, 77, 19, 85, 0, 81, 0, 0, 5, 0, 83, 91, 0, 
        0, 0, 19, 0, 71, 49, 0, 0, 0, 0, 29, 0, 35, 31, 0};

-> 2
80 86 8 30 74 20 66 44 82 36 44 44 8 66 40 60 44 |81 39 45 27 81 45 15 33 15 39|

*/