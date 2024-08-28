#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution
{
public:
    // int BinarySearch(vector<int> &nums, int target, function<bool(int, int)> comp)
    // {

    //     int low = 0;
    //     int n = nums.size();
    //     int high = n - 1;
    //     int index = -1;
    //     while (low <= high)
    //     {
    //         int mid = (low + high) / 2;
    //         if (comp(nums[mid], target))
    //         {
    //             index = mid;
    //             high = mid - 1;
    //         }
    //         else
    //         {
    //             low = mid + 1;
    //         }
    //     }
    //     return index;
    // }

    int CeilArray(vector<int> &nums, int target)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int index = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] <= target)
            {
                if (nums[mid] == target)
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

    int FloorArray(vector<int> &nums, int target)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int index = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
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

    vector<int> OptimalApproach(vector<int> &nums, int target)
    {
        vector<int> temp(2, -1);
        int val1 = FloorArray(nums, target);
        int val2 = CeilArray(nums, target);
        temp = {val1, val2};
        return temp;
    }
};

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution obj;
    arr = obj.OptimalApproach(arr, target);
    cout << "First and Last position is:" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}