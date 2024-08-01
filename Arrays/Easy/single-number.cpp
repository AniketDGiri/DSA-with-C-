#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Approach1(vector<int> &nums)
    {
        int ans = 0;
        for (auto itr = nums.begin(); itr != nums.end(); itr++)
        {
            ans = ans ^ (*itr);
        }
        return ans;
    }

    int Approach2(vector<int> &nums)
    {
        int ans = 0;
        for (const int i : nums)
        {
            ans = ans ^ i;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {2, 3, 4, 3, 2};
    Solution obj;
    cout << obj.Approach1(arr) << endl;
    cout << obj.Approach2(arr) << endl;
    return 0;
}