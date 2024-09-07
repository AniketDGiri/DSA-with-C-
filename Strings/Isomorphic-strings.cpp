#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool OptimalApproach(string s, string t)
    {
        map<char, char> chartCount1;
        map<char, char> chartCount2;
        bool check = true;
        int len1 = s.length();
        int len2 = t.length();
        for (int i = 0; i < len1 && check == true; i++)
        {
            if (chartCount1.find(s[i]) == chartCount1.end())
            {
                chartCount1[s[i]] = t[i];
            }
            else if (chartCount1[s[i]] == t[i])
            {
                continue;
            }
            else
            {
                check = false;
            }
            if (chartCount2.find(t[i]) == chartCount2.end())
            {
                chartCount2[t[i]] = s[i];
            }
            else if (chartCount2[t[i]] == s[i])
            {
                continue;
            }
            else
            {
                check = false;
            }
        }
        return check;
    }
};

int main()
{

    Solution obj;
    cout << obj.OptimalApproach("foo", "bar") << endl;

    return 0;
}