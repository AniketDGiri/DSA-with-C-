#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> arr;

public:
    void FindPossibleCombination(int start, int end, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (start == end)
        {
            if (target == 0)
            {
                arr.push_back(temp);
            }
            return;
        }

        if (candidates[start] <= target)
        {
            temp.push_back(candidates[start]);
            FindPossibleCombination(start, end, candidates, target - candidates[start], temp);
            temp.pop_back();
        }

        FindPossibleCombination(start + 1, end, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        int start = 0, end = candidates.size();
        FindPossibleCombination(start, end, candidates, target, temp);
        return arr;
    }
};

int main()
{
    vector<int> arr = {2, 3, 5};
    Solution obj;
    vector<vector<int>> temp;
    temp = obj.combinationSum(arr, 8);

    // printing all possible combinataions
    cout << "Allpossible combinations are: " << endl;

    for (int i = 0; i < temp.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < temp[i].size(); j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}