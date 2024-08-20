#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void Better_Approach(vector<vector<int>> &matrix)
    {
        vector<int> rowSize(matrix.size(), 0);
        vector<int> colSize(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowSize[i] = 1;
                    colSize[j] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (rowSize[i] == 1 || colSize[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void Optimal_Approach(vector<vector<int>> &matrix)
    {
        bool checkCol = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;

                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        checkCol = true;
                    }
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (checkCol)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1, 1},
                               {1, 0, 1},
                               {1, 1, 1}};
    // Before checking
    cout << "Before permorming" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
    obj.Better_Approach(arr);

    // after transformation
    cout << "After performing" << endl;

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