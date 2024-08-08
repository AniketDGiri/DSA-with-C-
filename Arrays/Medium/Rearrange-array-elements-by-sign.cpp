

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> Approach1(vector<int> &nums)
    {
        vector<int> arr;
        int n = nums.size();
        int left = 0, right = 0;
        bool flag = true;
        while (left < n and right < n)
        {
            // cout << left;
            // cout << right;
            while (nums[left] < 0 and flag == true)
            {
                left++;
            }
            if (nums[left] > 0)
            {
                arr.push_back(nums[left]);
                left++;
                flag = false;
            }

            // for checing negative elemetns
            while (nums[right] > 0 and flag == false)
            {
                right++;
            }
            if (nums[right] < 0)
            {
                arr.push_back(nums[right]);
                right++;
                flag = true;
            }
        } // end of while loop

        while (left < n && nums[left] > 0)
        {
            arr.push_back(nums[left]);
            left++;
        }
        while (right < n && nums[right] < 0)
        {
            arr.push_back(nums[right]);
            right++;
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    Solution obj;
    arr = obj.Approach1(arr);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}