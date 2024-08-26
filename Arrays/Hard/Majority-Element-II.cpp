#include <iostream>
#include <vector>
#include <climits>
#include <__clang_cuda_cmath.h>

using namespace std;

class Solution
{
public:
    vector<int> OptimalApproach(vector<int> &nums)
    {
        int ele1 = INT_MIN;
        int cnt1 = 0;
        int ele2 = INT_MIN;
        int cnt2 = 0;

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt1 == 0 && nums[i] != ele2)
            {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == ele1)
            {
                cnt1++;
            }
            else if (nums[i] == ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (ele1 == nums[i])
                cnt1++;
            if (ele2 == nums[i])
                cnt2++;
        }
        int n = int(nums.size() / 3) + 1;
        if (cnt1 >= n)
            ans.push_back(ele1);
        if (cnt2 >= n)
            ans.push_back(ele2);
        return ans;
    }
};

int main()
{

    return 0;
}