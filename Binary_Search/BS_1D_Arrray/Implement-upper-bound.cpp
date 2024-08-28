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
        int index = nums.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > key)
            {
                index = key;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> arr = {1, 4, 56, 3, 2};
    Solution obj;
    obj.OptimalApproach(arr, 5);
    return 0;
}