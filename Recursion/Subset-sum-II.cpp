#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<int>> arr;

public:
    void FindAllUniqueSubsets(vector<int> &nums, vector<int> &temp, int start)
    {
        arr.push_back(temp);
        for (int i = start; i < nums.size(); i++)
        {
            if (i != start && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            FindAllUniqueSubsets(nums, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int start = 0;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        FindAllUniqueSubsets(nums, temp, start);
        return arr;
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 2};
    Solution obj;
    vector<vector<int>> temp;
    temp = obj.subsetsWithDup(arr1);

    cout << "All unique subsets are: " << endl;
    for (int i = 0; i < temp.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < temp[i].size(); j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}