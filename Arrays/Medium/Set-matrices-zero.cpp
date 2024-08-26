#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void BetterApproach(vector<vector<int>> &matrix)
    {
        int colSize = matrix[0].size();
        int rowSize = matrix.size();
        //  creating a new array's for storing at what location o has been occured.
        vector<int> rowArray(rowSize, 0);
        vector<int> colArray(colSize, 0);

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowArray[i] = 1;
                    colArray[j] = 1;
                }
            }
        } // end of for, checking where 0 occured.
        // for making corresponding rows zero
        for (int i = 0; i < rowSize; i++)
        {
            if (rowArray[i] == 1)
            {
                for (int j = 0; j < colSize; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // for making corresponding col zero
        for (int j = 0; j < colSize; j++)
        {
            if (colArray[j] == 1)
            {
                for (int i = 0; i < rowSize; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    } // Better Approach

    void OptimalApproach(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    // using first row and first col for tracking the value
                    matrix[0][j] = -1;
                    matrix[i][0] = -1;
                }
            }
        }

        // going row size to make zeros
        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == -1)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // going col size to make zeros
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[j][0] == -1)
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1, 0},
                               {1, 1, 1},
                               {1, 1, 1}};

    // Before modifying
    cout << "Before modifying" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
    obj.BetterApproach(arr);

    // after modifying
    cout << "after modifying" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}