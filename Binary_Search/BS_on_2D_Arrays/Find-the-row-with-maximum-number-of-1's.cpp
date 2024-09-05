#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int FindSmallestIndex(vector<int> &nums)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int index = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= 1)
            {
                index = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return index;
    }

    int FindLargestIndex(vector<int> &nums)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int index = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > 1)
            {
                index = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return index;
    }

public:
    vector<int> OptimalApproach(vector<vector<int>> &mat)
    {
        int totalRows = mat.size();
        int smallerIndex = -1, totalOnes = -1;

        for (int i = 0; i < totalRows; i++)
        {
            sort(mat[i].begin(), mat[i].end());
            int firstIndex = FindSmallestIndex(mat[i]);

            int lastIndex = FindLargestIndex(mat[i]);
            cout << "FirstIndex is: " << firstIndex << endl;
            cout << "LastIndex is: " << lastIndex << endl;
            if (firstIndex > -1 and lastIndex < mat[i].size())
            {
                if (totalOnes < ((lastIndex - firstIndex) + 1))
                {
                    totalOnes = (lastIndex - firstIndex) + 1;
                    smallerIndex = i;
                }
            }
        }
        return {smallerIndex < 0 ? 0 : smallerIndex, totalOnes < 0 ? 0 : totalOnes};
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1}, {0, 1}};
    Solution obj;
    vector<int> temp = obj.OptimalApproach(arr);

    for (auto i : temp)
    {
        cout << i << endl;
    }
    return 0;
}