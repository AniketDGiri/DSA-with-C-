#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
private:
    int TotalStudentCount(vector<int> &nums, int mid)
    {
        int studentsCnt = 0;
        int tempPagesCnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tempPagesCnt + nums[i] <= mid)
            {
                tempPagesCnt += nums[i];
            }
            else
            {
                tempPagesCnt = nums[i];
                studentsCnt++;
            }
        }
        if (tempPagesCnt > 0)
        {
            studentsCnt++;
        }
        return studentsCnt;
    }

public:
    int OptimalApproach(vector<int> &nums, int k)
    {
        int low = INT_MIN;
        int n = nums.size();
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int studentsCnt = TotalStudentCount(nums, mid);
            if (studentsCnt <= k)
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

    vector<int> arr = {12, 34, 67, 90};
    Solution obj;
    cout << obj.OptimalApproach(arr, 2) << endl;
    return 0;
}