#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int BruteForceApproach(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }
    int OptimalApproach(vector<int> &arr, int k)
    {
        int n = arr.size() - 1;
        int low = 0;
        int high = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if ((arr[mid] - mid - 1) < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "High is: " << high << endl;
        if (high < 0)
        {
            k;
        }
        return arr[high] + (k - (arr[high] - high - 1));
    }
};

int main()
{
    vector<int> arr = {2};
    Solution obj;
    cout << obj.BruteForceApproach(arr, 1) << endl;
    cout << obj.OptimalApproach(arr, 1) << endl;
    return 0;
}