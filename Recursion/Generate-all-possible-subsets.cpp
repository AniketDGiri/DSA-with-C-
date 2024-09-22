#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> arr;

public:
    void FindPossibleSubset(int start, int end, vector<int> &temp, vector<int> &nums)
    {
        if (start == end)
        {
            arr.push_back(temp);
            return;
        }
        temp.push_back(nums[start]);
        FindPossibleSubset(start + 1, end, temp, nums);
        temp.pop_back();
        FindPossibleSubset(start + 1, end, temp, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        int n = nums.size();
        FindPossibleSubset(0, n, temp, nums);
        return arr;
    }
};

int main()
{
    vector<int> nums = {1};
    Solution obj;
    vector<vector<int>> arr;
    arr = obj.subsets(nums);

    cout << "All possible subsets are: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}