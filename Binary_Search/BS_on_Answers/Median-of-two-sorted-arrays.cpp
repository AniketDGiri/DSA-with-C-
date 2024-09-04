#include <iostream>
#include <vector>

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
        cout << "first Index is: " << ele1Ind1 << endl;
        cout << "first Index is: " << ele2Ind2 << endl;

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
                    cout << "Cnt is:-- " << cnt << endl;
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
                    cout << "Cnt is: " << cnt << endl;
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
};

int main()
{
    vector<int> arr1 = {3, 4};
    vector<int> arr2 = {};
    Solution obj;
    cout << obj.OptimalApproach(arr1, arr2) << endl;
    return 0;
}