#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{

private:
    vector<vector<int>> arr;
    set<vector<int>> setArr;

public:
    void FindCombinationSum(int start, int end, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            arr.push_back(temp);
            return;
        }

        for (int i = start; i < end; i++)
        {
            if (i > start && candidates[start] == candidates[start - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            FindCombinationSum(i + 1, end, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int start = 0, end = candidates.size();
        vector<int> temp;
        FindCombinationSum(start, end, candidates, target, temp);
        return arr;
    }
};

int main()
{
    return 0;
}