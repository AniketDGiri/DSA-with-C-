#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int OptimalApproach(vector<int> arr)
    {
        int finalAns = INT_MAX;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[low] <= arr[mid])
            {
                finalAns = min(finalAns, arr[low]);
                low = mid + 1;
            }
            else
            {
                finalAns = min(finalAns, arr[mid]);
                high = mid - 1;
            }
        }
        return finalAns;
    }
};

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    Solution obj;
    cout << obj.OptimalApproach(arr) << endl;
    return 0;
}