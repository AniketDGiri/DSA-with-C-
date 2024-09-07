#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    string OptimalApproach(string s)
    {
        string finalAns = "";
        unordered_map<char, int> charCount;

        vector<pair<char, int>> pairs;

        for (auto i : s)
        {
            charCount[i]++;
        }

        for (auto it : charCount)
        {
            pairs.push_back(it);
        }
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        for (auto each : pairs)
        {
            int count = each.second;
            for (int i = 0; i < count; i++)
            {
                finalAns += each.first;
            }
        }
        return finalAns;
    }
};

int main()
{
    string s = "Aabb";
    Solution obj;
    cout << obj.OptimalApproach(s) << endl;
    return 0;
}