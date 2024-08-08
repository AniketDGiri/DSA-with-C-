/*
URL: https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08

885. Spiral Matrix III

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 
Example 1:

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

 
Constraints:

    1 <= rows, cols <= 100
    0 <= rStart < rows
    0 <= cStart < cols
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> turns = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversedMatrix;
        traversedMatrix.push_back({rStart, cStart});
        int totalCounts = rows * cols;
        int currentCount = 1;
        int increment = 1;
        int index = 0;
        while (currentCount < totalCounts)
        {
            for (int i = 0; i < 2; i++)
            {
                int nextRow = turns[index % 4][0];
                int nextCol = turns[index % 4][1];

                for (int j = 0; j < increment; j++)
                {
                    rStart += nextRow;
                    cStart += nextCol;

                    if (rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols)
                    {
                        traversedMatrix.push_back({rStart, cStart});
                        currentCount++;
                    }
                }
                index++;
            }
            increment++;
            // cout << "---" << currentCount;
        }
        return traversedMatrix;
    }
    vector<vector<int>> spiralMatrixIII_Myapproach(int rows, int cols, int rStart, int cStart)
    {
        vector<int> turnsCount = {1, 1, 2, 2};
        string directions = "RDLU";
        vector<vector<int>> finalAns;
        int totalCount = rows * cols;
        int currentCount = 1;
        int n = turnsCount.size();
        int temp = 0;
        char turn = 'a';
        while (0 < currentCount <= totalCount)
        {
            cout << currentCount << "--";
            for (int i = 0; i < n; i++)
            {
                if (turnsCount[i] != -1)
                {
                    int temp = turnsCount[i];
                    char turn = directions[i];

                    switch (turn)
                    {
                    case 'R':
                        while (temp > 0 and cStart + 1 < cols)
                        {
                            cStart++;
                            finalAns.push_back({rStart, cStart});
                            cout << "R" << endl;
                            temp--;
                            currentCount++;
                        }
                        if (cStart + 1 < cols)
                        {
                            turnsCount[i] = -1;
                        }
                        else
                        {
                            turnsCount[i]++;
                        }
                        break;
                    case 'D':
                        while (temp > 0 and rStart + 1 < rows)
                        {
                            rStart++;
                            finalAns.push_back({rStart, cStart});
                            cout << "R" << endl;
                            temp--;
                            currentCount++;
                        }
                        if (rStart + 1 < rows)
                        {
                            turnsCount[i] = -1;
                        }
                        else
                        {
                            turnsCount[i]++;
                        }
                        break;
                    case 'L':
                        while (temp > 0 and cStart - 1 < 0)
                        {
                            cStart++;
                            finalAns.push_back({rStart, cStart});
                            cout << "L" << endl;
                            temp--;
                            currentCount++;
                        }
                        if (cStart - 1 < 0)
                        {
                            turnsCount[i] = -1;
                        }
                        else
                        {
                            turnsCount[i]++;
                        }
                        break;
                    case 'U':
                        while (temp > 0 and rStart - 1 < 0)
                        {
                            rStart++;
                            finalAns.push_back({rStart, cStart});
                            cout << "U" << endl;
                            temp--;
                            currentCount++;
                        }
                        if (rStart - 1 < 0)
                        {
                            turnsCount[i] = -1;
                        }
                        else
                        {
                            turnsCount[i]++;
                        }
                        break;
                    }
                }
            }
        }
        return finalAns;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> ans;
    ans = obj.spiralMatrixIII(5, 6, 1, 4);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}