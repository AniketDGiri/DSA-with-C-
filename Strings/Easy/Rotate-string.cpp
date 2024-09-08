#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool OptimalApproach(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        string s1 = s + s;
        size_t len;
        len = s1.find(goal);

        if (len == string::npos)
        {
            return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}