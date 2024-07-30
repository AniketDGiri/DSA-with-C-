#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void approach1(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int temp = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            temp = nums[0];
            for (int j = 1; j < n; j++)
            {
                swap(nums[j], temp);
            }
            nums[0] = temp;
        }
    }

    void reversalArray(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    void approach2(vector<int> &nums, int k)
    {
        int n = nums.size();
        reversalArray(nums, 0, k - 1);
        reversalArray(nums, k, n - 1);
        reversalArray(nums, 0, n - 1);
    }
};

int main()
{
    vector<int> arr = {1, 2, 5, 6, 3};
    int k = 4;
    Solution obj;
    int n = arr.size();
    k = n - (k % n);
    obj.approach2(arr, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}