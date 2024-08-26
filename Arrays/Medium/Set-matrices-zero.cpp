#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
<<<<<<< HEAD
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
=======
    void Better_Approach(vector<vector<int>> &matrix)
    {
        vector<int> rowSize(matrix.size(), 0);
        vector<int> colSize(matrix[0].size(), 0);

>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
<<<<<<< HEAD
                    // using first row and first col for tracking the value
                    matrix[0][j] = -1;
                    matrix[i][0] = -1;
=======
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
>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
                }
            }
        }

<<<<<<< HEAD
        // going row size to make zeros
        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == -1)
            {
                for (int j = 0; j < matrix[0].size(); j++)
=======
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
                {
                    matrix[i][j] = 0;
                }
            }
        }

<<<<<<< HEAD
        // going col size to make zeros
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[j][0] == -1)
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
=======
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
>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
            }
        }
    }
};

int main()
{
<<<<<<< HEAD
    vector<vector<int>> arr = {{0, 1, 0},
                               {1, 1, 1},
                               {1, 1, 1}};

    // Before modifying
    cout << "Before modifying" << endl;
=======
    vector<vector<int>> arr = {{0, 1, 1},
                               {1, 0, 1},
                               {1, 1, 1}};
    // Before checking
    cout << "Before permorming" << endl;

>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
<<<<<<< HEAD
    obj.BetterApproach(arr);

    // after modifying
    cout << "after modifying" << endl;
=======
    obj.Better_Approach(arr);

    // after transformation
    cout << "After performing" << endl;

>>>>>>> 88f08faa2d1fb61ac09f240173791c2d75165219
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