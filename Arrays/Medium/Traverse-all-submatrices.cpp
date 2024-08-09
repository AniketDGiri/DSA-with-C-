#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void printAllSubMatrices(vector<vector<int>> &nums)
    {
        int k = 3;
        int n = nums.size();
        int m = nums[0].size();
        int count = 0;
        for (int r = 0; r < n - k + 1; r++)
        {
            for (int c = 0; c < m - k + 1; c++)
            {
                cout << "Sub Matrix no is:" << ++count << endl;
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < k; j++)
                    {
                        cout << nums[i + r][j + c] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};

    Solution obj;
    // Here we can check for how much size we want the sub matrices to print
    obj.printAllSubMatrices(arr);
    return 0;
}