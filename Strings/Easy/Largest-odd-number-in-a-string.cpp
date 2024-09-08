#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string OptimalApproach(string num)
    {
        int len = num.length();
        int i = len - 1;
        string finalAns = "";
        int pos = -1;
        while (i >= 0)
        {
            int number = num[i] - '0';
            if (number % 2 != 0)
            {
                pos = i;
                break;
            }
            i--;
        }

        return num.substr(0, pos + 1);
    }
};

int main()
{
    Solution obj;
    cout << obj.OptimalApproach("1772") << endl;
    return 0;
}