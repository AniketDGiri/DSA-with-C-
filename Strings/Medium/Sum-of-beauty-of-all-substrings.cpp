#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int BruteForceApproach(string s)
    {
        vector<int> charCnt(26, 0);
        int len = s.length();
        int totalCnt = 0;
        for (int i = 0; i < len; i++)
        {
            charCnt.assign(26, 0);

            for (int j = i; j < len; j++)
            {
                int localMin = INT_MAX;
                int localMax = INT_MIN;
                // cout << s[j];
                charCnt[s[j] - 'a']++;
                for (auto each : charCnt)
                {
                    if (each > 0)
                    {
                        localMax = max(localMax, each);
                        localMin = min(localMin, each);
                    }
                }
                totalCnt += localMax - localMin;
            }
        }
        return totalCnt;
    }
};

int main()
{
    string str = "aabcb";
    Solution obj;
    cout << obj.BruteForceApproach(str) << endl;
    return 0;
}