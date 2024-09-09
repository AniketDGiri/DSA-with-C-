#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    long long int OptimalApproach(string str, int k)
    {
        int len = str.length();
        int i = 0, j = 0;
        int finalCnt = 0;
        vector<int> charCnt(26, 0);
        int distinctCnt = 0;
        while (j < len)
        {
            charCnt[str[j] - 'a']++;
            if (charCnt[str[j] - 'a'] == 1)
                distinctCnt++;

            while (distinctCnt > k)
            {
                charCnt[str[i] - 'a']--;
                if (charCnt[str[i] - 'a'] <= 0)
                {
                    distinctCnt--;
                }
                i++;
            }
            finalCnt += (j - i) + 1;
            j++;
        }
        return finalCnt;
    }
};

int main()
{
    string str = "abaaca";
    int k = 1;
    Solution obj;
    cout << obj.OptimalApproach(str, k) - obj.OptimalApproach(str, k - 1) << endl;

    return 0;
}