#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool OptimalApporach(vector<vector<int>> &matrix, int target)
    {

        int totalRows = matrix.size();
        int totalColumns = matrix[0].size();
        int correctRow = totalRows;

        int low = 0;
        int high = totalRows - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (matrix[mid][totalColumns - 1] >= target)
            {
                correctRow = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (correctRow == totalRows)
        {
            return false;
        }
        low = 0;
        high = totalColumns - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[correctRow][mid] == target)
            {
                return true;
            }
            else if (matrix[correctRow][mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution obj;
    cout << obj.OptimalApporach(arr, 0) << endl;
    return 0;
}