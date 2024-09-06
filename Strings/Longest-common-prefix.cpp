#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string OptimalApproach(vector<string> &str)
    {
        int n = str.size();
        string longestPrefix = "";
        bool check = true;
        for (int eachWord = 0; eachWord < str[0].size() and check == true; eachWord++)
        {
            char ch = str[0][eachWord];
            int eachWordCnt = 1;
            for (int i = 1; i < n; i++)
            {
                if (eachWord >= str[i].size())
                {
                    check = false;
                    break;
                }

                if (ch == str[i][eachWord])
                {
                    eachWordCnt++;
                }
                else
                {
                    check = false;
                    break;
                }
            }
            if (eachWordCnt == n)
            {
                longestPrefix += ch;
            }
        }
        return longestPrefix;
    }
};

int main()
{
    vector<string> arr = {"cir", "car"};
    Solution obj;
    cout << obj.OptimalApproach(arr) << endl;
    return 0;
}