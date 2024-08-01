#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    int MaxOnes(vector<int> &nums)
    {
        int maxVal = INT_MIN;
        int temp = 0;
        vector<int>::iterator itr;
        for (itr = nums.begin(); itr != nums.end(); itr++)
        {
            if (*itr == 1)
            {
                temp++;
            }
            else
            {
                maxVal = max(temp, maxVal);
                temp = 0;
            }
        }
        maxVal = max(temp, maxVal);

        return maxVal;
    }
};

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    Solution obj;
    cout << obj.MaxOnes(arr) << endl;
    return 0;
}