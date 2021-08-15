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
      grid[0][5] = 5;
      grid[0][2] = 2;
      grid[0][7] = 7;
      grid[0][6] = 1;
      grid[1][2] = 8;
      grid[2][0] = 9;
      grid[2][2] = 3;
      grid[1][0] = 4;
    }

  void findNumber()
  {
    vector<int> posNums = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < SIDE_SIZE; i++)
      {
        if (grid[0][i] != 0)
          {
            removeNum(grid[0][i], posNums);
          }
      }

    for (int i = 0; i < SUB_GRID_SIZE; i++)
      {
        for (int j = 0; j < SUB_GRID_SIZE; j++)
          {
            if (grid[i][j] != 0)
              {
                removeNum(grid[i][j], posNums);
              }
          }
      }

    printPosNums(posNums);

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
            cout << "Found match: " << posNums[i] << endl;
            posNums.erase(posNums.begin() + i);
          }

      }
  }

  void printPosNums(vector<int> posNums)
  {
    for(int j = 0; j < posNums.size(); j++)
      {
        cout << posNums[j] << endl;
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
