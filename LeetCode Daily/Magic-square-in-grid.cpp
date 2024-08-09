/*
URL: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09

840. Magic Squares In Grid

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 
Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0

 
Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 10
    0 <= grid[i][j] <= 15

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findAllRowSum(vector<vector<int>> &nums, int r, int c)
    {
        int rowSum = 0;
        int eachRowSum = 0;
        int val = 0;
        vector<bool> visitedCell(10, false);
        // cout << "2222" << endl;
        for (int i = 0; i < 3; i++)
        {
            eachRowSum = 0;
            for (int j = 0; j < 3; j++)
            {
                val = nums[i + r][j + c];
                // cout << val << "------";
                if (val == 0 || val >= 10 || visitedCell[val] == true)
                {
                    return -1;
                }
                eachRowSum += val;
                visitedCell[val] = true;
            }
            if (i == 0)
            {
                rowSum = eachRowSum;
            }
            else
            {
                if (eachRowSum != rowSum)
                    return -1;
            }
        }
        // cout << "RolSum--" << rowSum;
        return rowSum;
    }

    int findAllColSum(vector<vector<int>> &nums, int r, int c)
    {
        int colSum = 0;
        int eachColSum = 0;
        for (int j = 0; j < 3; j++)
        {
            eachColSum = 0;
            for (int i = 0; i < 3; i++)
            {
                eachColSum += nums[i + r][j + c];
            }
            if (j == 0)
            {
                colSum = eachColSum;
            }
            else
            {
                if (eachColSum != colSum)
                    return -1;
            }
        }
        // cout << "ColSum--" << colSum;
        return colSum;
    }

    int findAllDiagonalSum(vector<vector<int>> &nums, int r, int c)
    {

        // calculate left Sum
        int leftDiagSum = nums[r][c] + nums[r + 1][c + 1] + nums[r + 2][c + 2];
        int rightDiagSum = nums[r][c + 2] + nums[r + 1][c + 1] + nums[r + 2][c];

        if (leftDiagSum == rightDiagSum)
            return leftDiagSum;
        return -1;
    }

    bool isMagicMatrix(vector<vector<int>> &grid, int r, int c)
    {
        int rowSum = findAllRowSum(grid, r, c);
        if (rowSum == -1)
            return false;
        int colSum = findAllColSum(grid, r, c);
        if (colSum == -1)
            return false;
        int diagSum = findAllDiagonalSum(grid, r, c);
        if (diagSum == -1)
            return false;

        if (rowSum == colSum and rowSum == diagSum)
            return true;
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int totalCount = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int r = 0; r < n - 3 + 1; r++)
        {
            for (int c = 0; c < m - 3 + 1; c++)
            {
                if (isMagicMatrix(grid, r, c))
                {
                    totalCount++;
                }
            }
        }
        return totalCount;
    }
};

int main()
{
    vector<vector<int>> arr = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    Solution obj;
    cout << obj.numMagicSquaresInside(arr) << endl;
    return 0;
}