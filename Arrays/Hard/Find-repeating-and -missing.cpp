#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> OptimalApproach(vector<int> arr)
    {
        int repeatingNumber;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[abs(arr[i]) - 1] < 0)
            {
                ans.push_back(abs(arr[i]));
            }
            else
            {
                arr[abs(arr[i]) - 1] = -1 * arr[abs(arr[i]) - 1];
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 5, 3};
    Solution obj;
    arr = obj.OptimalApproach(arr);
    cout << "Repeating and Missing numbers are" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}