#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
private:
    int calculateTotalBoques(vector<int> nums, int k, int mid)
    {
        int tempFlowerCnt = 0;
        int totalBouqueCnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                tempFlowerCnt++;
            }
            else
            {
                tempFlowerCnt = 0;
            }

            if (tempFlowerCnt == k)
            {
                totalBouqueCnt++;
                tempFlowerCnt = 0;
            }
        }
        return totalBouqueCnt;
    }

public:
    int OptimalApproach(vector<int> &bloomDay, int m, int k)
    {
        int low = 1;
        int high = INT_MIN;
        int n = bloomDay.size();

        // checking base condition
        if (n < (m * k))
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            high = max(high, bloomDay[i]);
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int totalBouqueCnt = calculateTotalBoques(bloomDay, k, mid);
            cout << "FOr M" << mid << "Total Bouques cnt are" << totalBouqueCnt << endl;
            if (totalBouqueCnt >= m)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> arr = {7, 7, 7, 7, 12, 7, 7};
    Solution obj;
    cout << obj.OptimalApproach(arr, 2, 3) << endl;
    return 0;
}