#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    void InsertCorrectPosition(vector<int> &arr, int temp)
    {
        if (arr.size() == 0)
        {
            arr.push_back(temp);
        }
        else if (arr.back() < temp)
        {
            int greaterEle = arr.back();
            arr.pop_back();
            InsertCorrectPosition(arr, temp);
            arr.push_back(greaterEle);
        }
        else
        {
            arr.push_back(temp);
        }
    }
    void SortArray(vector<int> &arr)
    {
        if (arr.size() == 1)
        {
            return;
        }
        int temp = arr.back();
        arr.pop_back();
        SortArray(arr);
        InsertCorrectPosition(arr, temp);
    }
};

int main()
{
    vector<int> arr = {1, 7, 0, 3, 5};
    Solution obj;
    cout << "Array before sorting is: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    obj.SortArray(arr);

    cout << "Array after sorting is: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}