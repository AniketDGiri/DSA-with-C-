#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string BetterApproach(string s)
    {
        stack<int> stack;
        int len = s.length();
        string ans;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                if (stack.size() > 0)
                {
                    ans += s[i];
                }
                stack.push(s[i]);
            }
            else
            {
                stack.pop();
                if (stack.size() > 0)
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
    string OptimalApproach(string s)
    {
        int cnt = 0;
        int len = s.length();
        string ans;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                if (cnt > 0)
                {
                    ans += s[i];
                }
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt > 0)
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

int main()
{
    string str = "(()())(())(()(()))";
    Solution obj;
    cout << obj.OptimalApproach(str) << endl;
    return 0;
}