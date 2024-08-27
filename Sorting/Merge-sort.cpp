#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> arr1(mid - low + 1, 0);
        vector<int> arr2(high - mid, 0);

        int idx = 0;
        int temp = low;
        while (temp <= mid)
        {
            arr1[idx] = nums[temp];
            idx++;
            temp++;
        }
        idx = 0;
        temp = mid + 1;
        while (temp <= high)
        {
            arr2[idx] = nums[temp];
            idx++;
            temp++;
        }
        int i = 0, j = 0;
        int n = mid - low + 1;
        int m = high - mid;
        int k = low;
        while (i < n and j < m)
        {
            if (arr1[i] < arr2[j])
            {
                nums[k] = arr1[i];
                i++;
                k++;
            }
            else
            {
                nums[k] = arr2[j];
                j++;
                k++;
            }
        }

        if (i < n)
        {
            while (i < n)
            {
                nums[k] = arr1[i];
                i++;
                k++;
            }
        }
        if (j < m)
        {
            while (j < m)
            {
                nums[k] = arr2[j];
                j++;
                k++;
            }
        }
    }

    void Partition(vector<int> &nums, int low, int high)
    {
        if (low == high)
        {
            return;
        }
        int mid = (low + high) / 2;
        Partition(nums, low, mid);
        Partition(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
};

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    Solution obj;
    obj.Partition(arr, 0, 7);
    cout << "Elements after sorting are:" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}