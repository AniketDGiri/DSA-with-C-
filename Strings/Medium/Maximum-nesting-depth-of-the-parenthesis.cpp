#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int OptimalApproach(string s)
    {
        int maxDepth = 0;
        int openParenthesisCnt = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                openParenthesisCnt += 1;
            }
            else if (s[i] == ')')
            {
                openParenthesisCnt--;
            }
            maxDepth = max(maxDepth, openParenthesisCnt);
        }
        return maxDepth;
    }
};

int main()
{

    string str = "(1+(2*3)+1)";
    Solution obj;
    cout << obj.OptimalApproach(str) << endl;
    return 0;
}