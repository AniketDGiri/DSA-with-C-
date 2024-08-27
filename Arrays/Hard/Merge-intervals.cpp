#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> BruteForceApproach(vector<vector<int>> &intervals)
    {
        // creating final return 2D vector;
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0], intervals[0][1]});

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> temp;
            temp = ans.back();
            int start = temp[0];
            int end = temp[1];
            if (intervals[i][0] <= end)
            {
                if (end < intervals[i][1])
                {
                    end = intervals[i][1];
                }
                ans.pop_back();
                ans.push_back({start, end});
            }
            else
            {
                ans.pop_back();
                ans.push_back({start, end});
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

    Solution obj;
    arr = obj.BruteForceApproach(arr);

    cout << "Merege Intervals are:" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}