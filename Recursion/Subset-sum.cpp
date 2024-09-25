#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> subsetSumArray;

public:
    void calculateSubsetSum(vector<int> subsetArray, int tempSum, int start)
    {
        if (start == subsetArray.size())
        {
            subsetSumArray.push_back(tempSum);
            return;
        }
        tempSum += subsetArray[start];
        calculateSubsetSum(subsetArray, tempSum, start + 1);
        tempSum -= subsetArray[start];
        calculateSubsetSum(subsetArray, tempSum, start + 1);
    }

    vector<int> SumOfAllSubsets(vector<int> subsetArray)
    {
        calculateSubsetSum(subsetArray, 0, 0);
        return subsetSumArray;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2};
    Solution obj;
    arr = obj.SumOfAllSubsets(arr);

    sort(arr.begin(), arr.end());

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}