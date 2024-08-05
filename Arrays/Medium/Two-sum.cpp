#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> Approach1(vector<int> &nums, int target)
    {
        vector<int> tempArr;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    tempArr.push_back(i);
                    tempArr.push_back(j);
                    break;
                }
            }
        }
        return tempArr;
    }

    vector<int> Approach2(vector<int> &nums, int target)
    {
        unordered_map<int, int> mapData;
        vector<int> tempArr;
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n && flag == false; i++)
        {
            if (mapData.find(target - nums[i]) != mapData.end())
            {
                auto firstElement = mapData.find(target - nums[i]);

                tempArr.push_back(firstElement->second);
                tempArr.push_back(i);
                flag = true;
            }
            mapData.insert({nums[i], i});
        }
        return tempArr;
    }
};

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int>::iterator itr;
    Solution obj;
    vector<int> ans = obj.Approach1(arr, target);

    for (itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}