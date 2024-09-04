/*
# [](https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/)

## Description

Difficulty: **undefined**


## Solution

Language: ****

```

[1,2,3,4,5,6,7,8,9,10]
```
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution
{
public:
    float BruteForceApproach(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> insertedStations(n - 1, 0);
        for (int newStation = 0; newStation < k; newStation++)
        {
            float maxDist = INT_MIN;
            int index = -1;

            for (int i = 0; i < n - 1; i++)
            {
                float tempDist = (((float)(nums[i + 1] - nums[i])) / (insertedStations[i] + 1));
                if (maxDist < tempDist)
                {
                    maxDist = tempDist;
                    index = i;
                }
            }
            insertedStations[index]++;
        }

        float minOfMaxDistance = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            float tempDist = (((float)(nums[i + 1] - nums[i])) / (insertedStations[i] + 1));
            minOfMaxDistance = max(minOfMaxDistance, tempDist);
        }
        return minOfMaxDistance;
    }
    float OptimalApporach(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<float> pq;

        for (int i = 0; i < n - 1; i++)
        {
            int tempDist = (nums[i + 1] - nums[i]);
            pq.push(tempDist);
        }

        for (int newStation = 0; newStation < k; newStation++)
        {
            float pr = pq.top();
            pq.pop();
            float newDist = pr / 2;
            pq.push(newDist);
            pq.push(newDist);
        }

        float minOfMaxDistance = INT_MIN;
        while (!pq.empty())
        {
            minOfMaxDistance = max(minOfMaxDistance, pq.top());
            pq.pop();
        }
        return minOfMaxDistance;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    Solution obj;
    cout << obj.BruteForceApproach(arr, k) << endl;
    cout << obj.OptimalApporach(arr, k) << endl;

    return 0;
}