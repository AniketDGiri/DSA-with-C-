#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> arr;

public:
    void GenerateAllPArenthesis(string temp, int i, int n)
    {
        // cout << "Value of i: " << i << endl;
        if (i == n)
        {
            arr.push_back(temp);
            return;
        }
        temp[i] = '0';
        GenerateAllPArenthesis(temp, i + 1, n);
        if ((i == 0) || (i - 1 >= 0 and temp[i - 1] != '1'))
        {
            temp[i] = '1';
            GenerateAllPArenthesis(temp, i + 1, n);
        }
    }

    void DisplayAllBinaryStrings()
    {
        for (auto i : arr)
        {
            cout << i << endl;
        }
    }
};

int main()
{
    string temp = "000";
    Solution obj;
    obj.GenerateAllPArenthesis(temp, 0, 3);
    obj.DisplayAllBinaryStrings();
    return 0;
}