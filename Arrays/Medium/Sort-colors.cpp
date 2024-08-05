#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void Approach1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp(n, -1);
    }

    void approach2(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, mid = 0;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }

        } // while
    } // approach2
};

int main()
{
    vector<int> arr = {2, 0, 1};
    Solution obj;
    // obj.Approach1(arr);
    obj.approach2(arr);

    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}