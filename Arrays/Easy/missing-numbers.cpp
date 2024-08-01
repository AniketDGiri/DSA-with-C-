#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int Approach1(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            nums[i]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) - 1 < n)
            {
                nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                return i;
            }
        }
        return n;
    }
};

int main()
{
    vector<int> arr = {1, 2};
    Solution obj;
    cout << "Ans is:" << obj.Approach1(arr) << endl;
    return 0;
}