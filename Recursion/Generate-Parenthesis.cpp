#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> arr;

public:
    void GenerateParenthesis(string str, int open, int close)
    {
        // cout << "Open: " << open << " " << "Close: " << close << endl;
        // cout << "Str at this point is: " << str << endl;
        cout << str << " ---> " << open << " " << close << endl;
        if ((open == 0) and (close == 0))
        {
            cout << "Str is: " << str << endl;
            arr.push_back(str);
            return;
        }

        if (open > 0)
        {
            str += "(";
            GenerateParenthesis(str, open - 1, close);
            str.pop_back();
        }

        if (close > open)
        {
            str += ")";
            GenerateParenthesis(str, open, close - 1);
            str.pop_back();
        }
    }

    vector<string> Approach1(int n)
    {
        string temp = "";
        GenerateParenthesis(temp, n, n);
        return arr;
    }
};

int main()
{
    vector<string> str;
    Solution obj;
    str = obj.Approach1(2);

    for (auto i : str)
    {
        cout << i << " " << endl;
    }

    return 0;
}