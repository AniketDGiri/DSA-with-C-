#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> Approach1(int numRows)
    {
        vector<vector<int>> arr;

        if (numRows == 1)
        {
            arr.push_back({1});
            return arr;
        }
        else if (numRows == 2)
        {
            arr.push_back({1});
            arr.push_back({1, 1});
            return arr;
        }
        else
        {
            arr.push_back({1});
            arr.push_back({1, 1});
            for (int i = 2; i < numRows; i++)
            {
                vector<int> numArr(i + 1, 1);
                for (int j = 1; j < i; j++)
                {
                    numArr[j] = arr[i - 1][j - 1] + arr[i - 1][j];
                }
                arr.push_back(numArr);
            }
        }
        return arr;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = obj.Approach1(5);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}