#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> OptimalApproach(vector<int> &nums)
    {
        int rightMax = INT_MIN;
        vector<int> temp;
        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++)
        {
            if (*itr > rightMax)
            {
                temp.push_back(*itr);
                rightMax = *itr;
            }
        }
        return temp;
    }
};

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    Solution obj;
    arr = obj.OptimalApproach(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}