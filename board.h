#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Board
{
private:
    int SIDE_SIZE = 9;
    int SUB_GRID_SIZE = 3;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> possibleNumbersGrid;
    int foundNumbers = 0;

public:
    Board() : grid(SIDE_SIZE, vector<int>(SIDE_SIZE)), possibleNumbersGrid(SIDE_SIZE, vector<vector<int>>(SIDE_SIZE, {1,2,3,4,5,6,7,8,9}))
        {
        }

    void set(int i, int j, int val)
        {
            cout << "Setting " << i << ", " << j << " to " << val << endl;
            grid[i][j] = val;
            foundNumbers++;
            possibleNumbersGrid[i][j] = {};
            for (int m = 0; m < SIDE_SIZE; m++)
            {
                removeNum(val, possibleNumbersGrid[i][m]);
            }
            for (int n = 0; n < SIDE_SIZE; n++)
            {
                removeNum(val, possibleNumbersGrid[n][j]);
            }

            int row;
            int col;
            if (i < 3) row = 0;
            if (i >= 3 && i < 6) row = 3;
            if (i >= 6) row = 6;

            if (j < 3) col = 0;
            if (j >= 3 && j < 6) col = 3;
            if (j >= 6) col = 6;

            //cout << "row: " << row << ", col: " << col << endl;
    
            vector<vector<int>> subGrid = getSubGrid(i, j);
            for (int i = 0; i < SUB_GRID_SIZE; i++)
            {
                for (int j = 0; j < SUB_GRID_SIZE; j++)
                {
                    removeNum(val, possibleNumbersGrid[i + row][j + col]);
                }
            }
    
            //           cout << "(After) Possible numbers in row " << i << endl;
            //print2DVector(possibleNumbersGrid[i]);
            //cout << "---------------------------------------" << endl;
        }

    void findNumbers()
        {
            cout << "Finding Numbers" << endl;
            bool foundNumber = false;
            do
            {
                for (int i = 0; i < SIDE_SIZE; i++)
                {
                    for (int j = 0; j < SIDE_SIZE; j++)
                    {
                        foundNumber = findNumber(i, j);
                        if (foundNumber) break;
                    }
                    if (foundNumber) break;
                }
            }
            while (foundNumber);
            if (foundNumbers == 81)
            {
                cout << "------------------------\nSUDOKU PUZZLE FINISHED\n------------------------\n";
            }
        }

    bool findNumber(int row, int col)
        {
            vector<int> posNums = possibleNumbersGrid[row][col];
            if (posNums.size() == 1)
            {
                set(row, col, posNums[0]);
                //print();
                return true;
            }
            return false;
        }

    void removeNum(int num, vector<int>& posNums)
        {
            for (int i = 0; i < posNums.size(); i++)
            {
                 if (num == posNums[i])
                {
                     posNums.erase(posNums.begin() + i);
                    break;
                }

            }
         }

    vector<vector<int>> getSubGrid(int m, int n)
        {
            int row;
            int col;
            if (m < 3) row = 0;
            if (m >= 3 && m < 6) row = 3;
            if (m >= 6) row = 6;

            if (n < 3) col = 0;
            if (n >= 3 && m < 6) col = 3;
            if (n >= 6) col = 6;

            vector<vector<int>> subGrid;
            for (int i = row; i < row + 3; i++)
            {
                int end = col + 2;
                vector<int> v(grid[i].begin() + col, grid[i].begin() + end);
                subGrid.push_back(v);
            }
            return subGrid;
        }

    void printPosNums(vector<int> posNums)
        {
            for(int j = 0; j < posNums.size(); j++)
            {
                cout << posNums[j] << " ";
            }
            cout << endl;
        }

    void print2DVector(vector<vector<int>> v)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << i << ": ";
                for (int j = 0; j < v[i].size(); j++)
                {
                    cout << v[i][j] << "  ";
                }
                cout << endl;
            }
        }

    void print()
        {
            string paddingRow = "||       |       |       ||       |       |       ||       |       |       ||";
            string innerRow =   "||-----------------------||-----------------------||-----------------------||";
            string subGridRow = "||#######################||#######################||#######################||";
            cout << subGridRow << endl;
            cout << paddingRow << endl;
            for (int i = 0; i < SIDE_SIZE; i++)
            {
                cout << "||";
                for (int j = 0; j < SIDE_SIZE; j++)
                {
                    if (grid[i][j] != 0)
                    {
                        cout << "   " << grid[i][j] << "   |";
                    }
                    else
                    {
                        cout << "       |";
                    }
                    if ((j+1) % 3 == 0)
                    {
                        cout << "|";
                    }
                }
                cout << endl << paddingRow << endl;
                if ((i+1) % 3 == 0)
                {
                    cout << subGridRow << endl;
                }
                else
                {
                    cout << innerRow << endl;
                }
                if (i != 8) cout << paddingRow << endl;
            }
        }
};
