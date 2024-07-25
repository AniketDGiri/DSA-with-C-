#include <iostream>
#include <vector>

using namespace std;

class SortedArray
{
private:
    vector<int> vec;

public:
    int getArrayIndex(vector<int> &arr)
    {
        int n = arr.size();
        int index = 0;
        bool flag = true;
        for (int i = 0; i < n - 1 && flag == true; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                index = i + 1;
                flag = false;
            }
        }
        return index;
    }
    bool check(vector<int> &nums)
    {
        int startIndex = getArrayIndex(nums);
        int n = nums.size();
        int itr = (startIndex + 1) % n;
        int i = startIndex;
        bool flag = true;
        while (itr != startIndex && flag == true)
        {
            if (nums[itr] >= nums[i])
            {
                i = itr;
                itr = (itr + 1) % n;
            }
            else
            {
                flag = false;
            }
        }
        return flag;
    }

    bool Approach2(vector<int> &arr)
    {
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                if (arr[i] > arr[0])
                {
                    count++;
                }
            }
            else
            {
                if (arr[i] > arr[i + 1])
                {
                    count++;
                }
            }
        }
        if (count >= 2)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    SortedArray obj;
    cout << obj.check(arr) << endl;
    cout << obj.Approach2(arr) << endl;
    return 0;
}