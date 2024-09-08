#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    string reverseString(string str)
    {
        int len = str.length();
        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            swap(str[i], str[j]);
        }
        return str;
    }

public:
    string OptimalApproach(string s)
    {
        string temp = "";
        int len = s.length();
        // cout << len << endl;
        string finalAns = "";
        int i = 0;

        while (i < len)
        {
            temp = "";

            while (i < len and s[i] == ' ')
            {
                i++;
            }
            cout << "Temp is: " << temp << endl;
            while (i < len and s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            if (temp.length() > 0)
            {
                if (finalAns.length() == 0)
                {
                    finalAns = temp;
                }
                else
                {
                    finalAns = temp + " " + finalAns;
                }
            }
        }
        return finalAns;
    }
};

int main()
{
    Solution obj;
    cout << obj.OptimalApproach(" hello world ") << endl;
    return 0;
}