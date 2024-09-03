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
        vector<int> insertedStations(n - 1, 0);
        priority_queue<pair<float, int>> pq;

        for (int i = 0; i < n - 1; i++)
        {
            float tempDist = (((float)(nums[i + 1] - nums[i])) / (insertedStations[i] + 1));
            pq.push({tempDist, i});
        }

        for (int newStation = 0; newStation < k; newStation++)
        {
            pair<float, int> pr = pq.top();
            pq.pop();
            insertedStations[pr.second]++;
        }

        float minOfMaxDistance = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            float tempDist = (((float)(nums[i + 1] - nums[i])) / (insertedStations[i] + 1));
            minOfMaxDistance = max(minOfMaxDistance, tempDist);
        }
        return minOfMaxDistance;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 1;
    Solution obj;
    cout << obj.BruteForceApproach(arr, k) << endl;

    return 0;
}