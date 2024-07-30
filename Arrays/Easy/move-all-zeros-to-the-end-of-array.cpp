#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> arr;

public:
    void moveAllZeros(vector<int> &arr)
    {
        int ind = -1;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[++ind], arr[i]);
            }
        }
    }

    void display(vector<int> &arr)
    {
        }
};

int main()
{
    vector<int> arr = {0, 1, 0, 3, 1, 13};

    return 0;
}