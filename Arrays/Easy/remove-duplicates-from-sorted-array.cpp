#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> arr;

public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int>::iterator itr;
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[index])
            {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

int main()
{
    vector<int> arr = {1, 1, 2};
    Solution obj;
    int k = obj.removeDuplicates(arr);
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
