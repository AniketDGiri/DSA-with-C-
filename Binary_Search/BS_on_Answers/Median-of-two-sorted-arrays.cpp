#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    double OptimalApproach(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int totalSize = n + m;

        int i = 0, j = 0, cnt = -1, ele1, ele2, ele1Ind1, ele2Ind2;

        ele1Ind1 = totalSize / 2;
        ele2Ind2 = ((totalSize / 2) - 1);
        // cout << "first Index is: " << ele1Ind1 << endl;
        // cout << "first Index is: " << ele2Ind2 << endl;

        bool flag1 = false, flag2 = false;

        while (i < n and j < m and (flag1 == false || flag2 == false))
        {
            if (nums1[i] <= nums2[j])
            {
                cnt++;
                if (cnt == ele1Ind1)
                {
                    ele1 = nums1[i];
                    flag1 = true;
                }

                if (cnt == ele2Ind2)
                {

                    ele2 = nums1[i];
                    flag2 = true;
                }
                i++;
            }
            else
            {
                cnt++;
                if (cnt == ele1Ind1)
                {
                    ele1 = nums2[j];
                    flag1 = true;
                }
                if (cnt == ele2Ind2)
                {

                    ele2 = nums2[j];
                    flag2 = true;
                }
                j++;
            }
        }

        if (j < m)
        {
            while (j < m and (flag1 == false || flag2 == false))
            {
                cnt++;
                if (cnt == ele1Ind1)
                {
                    ele1 = nums2[j];
                    flag1 = true;
                }
                if (cnt == ele2Ind2)
                {
                    ele2 = nums1[j];
                    flag2 = true;
                }
                j++;
            }
        }

        if (i < n)
        {
            while (i < n and (flag1 == false || flag2 == false))
            {
                cnt++;
                if (cnt == ele1Ind1)
                {
                    ele1 = nums1[i];
                    flag1 = true;
                }
                if (cnt == ele2Ind2)
                {
                    ele2 = nums1[i];
                    flag2 = true;
                }
                i++;
            }
        }

        cout << "Element 1 is:" << ele1 << endl;
        cout << "Element 2 is:" << ele2 << endl;
        if (totalSize % 2 == 0)
        {
            return ((double)(ele1 + ele2) / 2);
        }
        return ele1;
    }

    double OptimalApproach2(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
            return OptimalApproach2(nums2, nums1);

        int low = 0, high = n;
        int median = (n + m + 1) / 2;
        int total = n + m;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = median - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n)
                r1 = nums1[mid1];
            if (mid2 < m)
                r2 = nums2[mid2];

            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if ((l1 <= r2) and (l2 <= r1))
            {
                if (total % 2 == 1)
                    return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2)) / 2);
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else if (l2 > r1)
                low = mid1 + 1;
        }
        return 0;
    }
};

int main()
{
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2};
    Solution obj;
    cout << obj.OptimalApproach(arr1, arr2) << endl;
    cout << obj.OptimalApproach2(arr1, arr2) << endl;
    return 0;
}