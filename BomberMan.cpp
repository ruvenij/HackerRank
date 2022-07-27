#include <bits/stdc++.h>

using namespace std;

void printVector(int index, const vector<string>& B)
{
    std::cout << "================ " << index << std::endl;
    for (std::string word : B)
    {
        std::cout << word << std::endl;
    }
}

vector<string> greedyBomberMan(int n, vector<string> grid) 
{
    if (n == 1) return grid;

    int index = 1;
    int rowCount = grid.size();
    int colCount = grid[0].size();
    
    while (n >= index)
    {
        for (int r = 0; r < rowCount; r++)
        {
            for (int c = 0; c < colCount; c++)
            {
                if (grid[r][c] != '.') grid[r][c]++;
                
                if (index == 1) continue;
                
                if (index % 2 == 0)
                {
                    if (grid[r][c] == '.') grid[r][c] = 'O';
                }
                else if (grid[r][c] == 'R') 
                {
                    if ((r + 1 < rowCount) and (grid[r + 1][c] != 'Q')) grid[r + 1][c] = '.';
                    if ((r > 0) and (grid[r - 1][c] != 'Q')) grid[r - 1][c] = '.';
                    if ((c + 1 < colCount) and (grid[r][c + 1] != 'Q')) grid[r][c + 1] = '.';
                    if ((c > 0) and (grid[r][c - 1] != 'Q')) grid[r][c - 1] = '.';
                        
                    grid[r][c] = '.';
                }
                
                if (n == index)
                {
                    if (grid[r][c] != '.') grid[r][c] = 'O';
                }
            }
        }

        index++;  
    }

    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) 
{
    if (n == 1) return grid;

    int index = 1;
    int rowCount = grid.size();
    int colCount = grid[0].size();
    int count = n % 4;
    count = (count == 0) ? 4 : count;
    index = 1;

    while (index <= count)
    {
        for (int r = 0; r < rowCount; r++)
        {
            for (int c = 0; c < colCount; c++)
            {
                if (grid[r][c] != '.')
                {
                    grid[r][c]++;
                }

                if (count == index)
                {
                    if (grid[r][c] == '.') 
                    {
                        if (count != 1)
                        {
                            grid[r][c] = 'O';
                        }
                    }
                    else if (grid[r][c] == 'R')
                    {
                        grid[r][c] = '.';
                    }
                    else
                    {
                        grid[r][c] = 'O';
                    }
                }
            }
        }

        index++;
    }

    return grid;
}

int main()
{
    int n = 5;
    std::vector<string> A = {".......", "...O...", "....O..", ".......", "OO.....", "OO....."};
    //std::vector<string> A = {".......", "...O.O.", "....O..", "..O....", "OO...OO", "OO.O..."};
    std::vector<string> B = bomberMan(n, A);
    printVector(-1, B);

    B.clear();
    B = greedyBomberMan(n, A);
    printVector(-1, B);

    /*for (std::string word : B)
    {
        std::cout << word << std::endl;
    }*/

    return 0;
}