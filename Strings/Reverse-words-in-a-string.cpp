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
        string finalAns = "";

        for (int i = 0; i < len; i++)
        {

            if (s[i] == ' ' || s[i] == '\0')
            {
                finalAns += reverseString(temp) + " ";
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        return finalAns;
    }
};

int main()
{
    Solution obj;
    cout << obj.OptimalApproach("the sky is blue") << endl;
    return 0;
}