#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void BetterApproach(vector<vector<int>> &matrix)
    {
        // Calculate transpose of the matrix

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reversing the rows values
        int colSize = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {
            int n = 0;
            int m = colSize - 1;
            while (n < m)
            {
                swap(matrix[i][n], matrix[i][m]);
                n++;
                m--;
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
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
    obj.BetterApproach(arr);

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