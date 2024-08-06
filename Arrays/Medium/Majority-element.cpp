#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Approach2(vector<int> &nums)
    {
        int n = nums.size();
        int k = ceil(n / 2);
        int maxEle = nums[0];
        int count = 1;

        for (const auto itr : nums)
        {
            if (itr == maxEle)
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count == 0)
            {
                count = 1;
                maxEle = itr;
            }
        }
        return maxEle;
    }
};

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    Solution obj;
    cout << obj.Approach2(arr) << endl;
    return 0;
}