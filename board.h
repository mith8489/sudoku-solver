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

 public:
 Board() : grid(SIDE_SIZE, vector<int>(SIDE_SIZE))
    {
    }

  void set(int i, int j, int val)
  {
    grid[i][j] = val;
  }

  void findNumbers()
  {
    bool foundNumber = false;

    do
      {
        for (int i = 0; i < SIDE_SIZE; i++)
          {
            for (int j = 0; j < SIDE_SIZE; j++)
              {

              }
          }
      }
    while (!foundNumber);
  }

  void findNumber(int row, int col)
  {
    vector<vector<int>> subGrid = getSubGrid(0, 0);
    print2DVector(subGrid);

    vector<int> posNums = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < SIDE_SIZE; i++)
      {
        if (grid[0][i] != 0)
          {
            removeNum(grid[0][i], posNums);
          }
      }

    for (int i = 0; i < SIDE_SIZE; i++)
      {
        if (grid[i][0] != 0)
          {
            removeNum(grid[0][i], posNums);
          }
      }

    for (int i = 0; i < SUB_GRID_SIZE; i++)
      {
        for (int j = 0; j < SUB_GRID_SIZE; j++)
          {
            if (subGrid[i][j] != 0)
              {
                removeNum(subGrid[i][j], posNums);
              }
          }
      }

    if (posNums.size() == 1)
      {
        grid[0][0] = posNums[0];
        print();
      }
  }

  void removeNum(int num, vector<int>& posNums)
  {
    for (int i = 0; i < posNums.size(); i++)
      {
        if (num == posNums[i])
          {
            posNums.erase(posNums.begin() + i);
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
        vector<int> v(grid[i].begin() + col, grid[i].begin() + col + 3);
        subGrid.push_back(v);
      }
    return subGrid;
  }

  void printPosNums(vector<int> posNums)
  {
    for(int j = 0; j < posNums.size(); j++)
      {
        cout << posNums[j] << endl;
      }
  }

  void print2DVector(vector<vector<int>> v)
  {
    for (int i = 0; i < v.size(); i++)
      {
        for (int j = 0; j < v[0].size(); j++)
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
