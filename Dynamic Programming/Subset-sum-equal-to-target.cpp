#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<bool>> memo;

public:
    Solution() : memo(101, vector<bool>(10001, false)) {};

    bool checkIsSubsetPresentRecursive(vector<int> &arr, int sum, int start)
    {
        bool leftPart, rightPart;
        if (start == arr.size())
        {
            if (sum == 0)
            {
                return true;
            }
            return false;
        }

        if (memo[start][sum])
        {
            return true;
        }

        if (arr[start] <= sum)
        {
            leftPart = checkIsSubsetPresentRecursive(arr, sum - arr[start], start + 1);
        }
        if (!leftPart)
            rightPart = checkIsSubsetPresentRecursive(arr, sum, start + 1);
        memo[start][sum] = leftPart || rightPart;
        return memo[start][sum];
    }

    bool checkIsSubsetTopdown(vector<int> &arr, int sum, int start)
    {
        vector<vector<bool>> memo1(arr.size() + 1, vector<bool>(sum + 1, false));

        for (int j = 0; j < sum + 1; j++)
        {
            memo1[0][j] = false;
        }

        for (int i = 0; i < arr.size() + 1; i++)
        {
            memo1[i][0] = true;
        }

        for (int i = 1; i <= arr.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    memo1[i][j] = (memo1[i - 1][j - arr[i - 1]]) || memo1[i - 1][j];
                }
                else
                {
                    memo1[i][j] = memo1[i - 1][j];
                }
            }
        }
        return memo1[arr.size()][sum];
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        return checkIsSubsetPresentRecursive(arr, sum, 0);
    }
};

int main()
{
    vector<int> arr = {8, 4, 3, 13, 10, 18, 6, 13, 16, 10, 7, 16, 13, 3, 9, 4, 8, 2, 18};
    Solution obj;
    cout << obj.isSubsetSum(arr, 190) << endl;
    return 0;
}