#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    int OptimalApproach(string s)
    {
        int len = s.length();
        int i = 0;
        string stringNumber = "";
        bool checkNegative = false;
        bool numStarts = false;
        // here we are ignoring all the irrelevarnt characters;
        while (s[i] == ' ')
        {

            i++;
        }
        while (s[i] == '+' || s[i] == '-')
        {
            if (numStarts)
            {
                return 0;
            }
            if (s[i] == '-')
            {
                cout << "Entered here" << endl;
                checkNegative = true;
            }
            numStarts = true;
            i++;
        }
        while (s[i] == '0')
        {
            i++;
        }

        while (i < len)
        {
            cout << s[i] - '0' << endl;
            if (((s[i] - '0') >= 0) and ((s[i] - '0') <= 9))
            {
                stringNumber += s[i];
            }
            else
            {
                break;
            }
            i++;
        }
        cout << "Number is: " << stringNumber << endl;
        long long intNumber = 0;
        if (stringNumber.length() >= 11)
        {
            if (checkNegative)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        for (char c : stringNumber)
        {
            intNumber = intNumber * 10 + (c - '0');
        }

        cout << "Number after transformation is: " << stringNumber << endl;
        if (checkNegative)
        {
            intNumber = intNumber * -1;
        }
        if (intNumber > INT_MAX)
        {
            return INT_MAX;
        }
        if (intNumber < INT_MIN)
        {
            return INT_MIN;
        }

        return intNumber;
    }
};

int main()
{
    string str = "-91283472332";
    Solution obj;
    cout << obj.OptimalApproach(str) << endl;
    return 0;
}