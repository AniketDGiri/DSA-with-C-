#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int OptimalApproach(string s)
    {
        unordered_map<char, int> romanLetters;
        romanLetters.insert({'I', 1});
        romanLetters.insert({'V', 5});
        romanLetters.insert({'X', 10});
        romanLetters.insert({'L', 50});
        romanLetters.insert({'C', 100});
        romanLetters.insert({'D', 500});
        romanLetters.insert({'M', 1000});

        int len = s.length();
        int i = 0;
        int totalSum = 0;
        while (i < len)
        {
            if (s[i] == 'I')
            {

                if (i + 1 < len and s[i + 1] == 'V')
                {
                    totalSum += 4;
                    i = i + 2;
                }
                else if (i + 1 < len and s[i + 1] == 'X')
                {
                    totalSum += 9;
                    i = i + 2;
                }
                else
                {
                    totalSum += 1;
                    i++;
                }
            }
            else if (s[i] == 'X')
            {

                if (i + 1 < len and s[i + 1] == 'L')
                {
                    totalSum += 40;
                    i = i + 2;
                }
                else if (i + 1 < len and s[i + 1] == 'C')
                {
                    totalSum += 90;
                    i = i + 2;
                }
                else
                {
                    totalSum += 10;
                    i++;
                }
            }
            else if (s[i] == 'C')
            {

                if (i + 1 < len and s[i + 1] == 'D')
                {
                    totalSum += 400;
                    i = i + 2;
                }
                else if (i + 1 < len and s[i + 1] == 'M')
                {
                    totalSum += 900;
                    i = i + 2;
                }

                else
                {
                    totalSum += 100;
                    i++;
                }
            }
            else
            {
                totalSum += romanLetters[s[i]];
                i++;
            }
        }
        return totalSum;
    }
};

int main()
{
    string str = "III";
    Solution obj;
    cout << obj.OptimalApproach(str) << endl;
    return 0;
}