#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, string> digitsMap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

class Solution
{
private:
    vector<string> arr;

public:
    void calculateCombination(int index, string digits, string temp)
    {
        if (index == digits.length())
        {
            arr.push_back(temp);
            return;
        }
        char num = digits[index];
        for (auto eachChar : digitsMap[num])
        {
            calculateCombination(index + 1, digits, temp + eachChar);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
        {
            return {};
        }
        calculateCombination(0, digits, "");
        return arr;
    }
};

int main()
{
    string str = "234";
    Solution obj;
    vector<string> temp;
    temp = obj.letterCombinations(str);

    for (auto eachStr : temp)
    {
        cout << eachStr << endl;
    }

    return 0;
}