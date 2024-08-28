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
            if (nums[mid] >= key)
            {
                index = mid;
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
    vector<int> arr = {1, 2, 2, 2, 2, 3, 3, 3, 5, 5};
    int key = 4;
    Solution obj;
    cout << obj.OptimalApproach(arr, key) << endl;
}