#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int OptimalApproach(vector<int> &nums, int key)
    {
        int low = 0;
        int high = nums.size() - 1;
        int index = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] <= key)
            {
                index = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> arr = {2, 2, 4, 5, 6};
    Solution obj;
    int key = 7;
    cout << obj.OptimalApproach(arr, key) << endl;
    return 0;
}