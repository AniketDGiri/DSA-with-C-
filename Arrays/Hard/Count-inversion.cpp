#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int totalInversion = 0;

public:
    void CountInversions(vector<int> &arr1, vector<int> &arr2)
    {
        int len1 = arr1.size();
        int len2 = arr2.size();

        // cout << "Len is" << len << endl;
        // cout << "Elements in arr1" << endl;
        // for (auto i : arr1)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        // cout << "Elements in arr2" << endl;
        // for (auto i : arr2)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        int i = 0, j = 0;
        while (i < len1 and j < len2)
        {
            if (arr1[i] > arr2[j])
            {

                totalInversion += (len1 - i);
                j++;
            }
            else
            {
                i++;
            }
        }
    }

    void Merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> arr1(mid - low + 1, 0);
        vector<int> arr2(high - mid, 0);

        int temp = low;
        int idx = 0;
        while (temp <= mid)
        {
            arr1[idx] = nums[temp];
            temp++;
            idx++;
        }

        temp = mid + 1;
        idx = 0;
        while (temp <= high)
        {
            arr2[idx] = nums[temp];
            temp++;
            idx++;
        }
        CountInversions(arr1, arr2);

        temp = low;
        int i = 0;
        int j = 0;
        int n = mid - low + 1;
        int m = high - mid;

        while (i < n and j < m)
        {
            if (arr1[i] < arr2[j])
            {
                nums[temp] = arr1[i];
                temp++;
                i++;
            }
            else
            {
                nums[temp] = arr2[j];
                j++;
                temp++;
            }
        }

        if (i < n)
        {
            while (i < n)
            {
                nums[temp] = arr1[i];
                temp++;
                i++;
            }
        }

        if (j < m)
        {
            while (j < m)
            {
                nums[temp] = arr2[j];
                j++;
                temp++;
                ;
            }
        }
    }

    void Partition(vector<int> &nums, int low, int high)
    {
        if (low == high)
            return;
        int mid = (low + high) / 2;
        Partition(nums, low, mid);
        Partition(nums, mid + 1, high);
        Merge(nums, low, mid, high);
    }

    void OptimalApproach(vector<int> &nums)
    {

        int low = 0;
        int high = nums.size() - 1;
        Partition(nums, low, high);
    }

    int getTotalInversions()
    {
        return totalInversion;
    }
};

int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};

    Solution obj;
    obj.OptimalApproach(arr);

    cout << "Sorted Array is:" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Total Inversions are:" << obj.getTotalInversions() << endl;
    return 0;
}