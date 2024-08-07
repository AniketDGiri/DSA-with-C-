#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    // This is used for storing unit values
    vector<string> units = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    // This will be used for storing teens
    vector<string> teens = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    // This will be used for tens
    vector<string> tens = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    // This will be used for division
    vector<string> partition = {"", "Thousand ", "Million ", "Billion "};

public:
    string convertNumToWords(int num)
    {
        string ans = "";

        while (num > 0)
        {
            if (num > 99)
            {
                int temp = num / 100;
                ans = units[temp] + ans + "Hundred ";
                num = num % 100;
            }
            else
            {
                if (num >= 10 and num <= 19)
                {
                    num = num % 10;
                    ans = ans + teens[num];
                    num = num / 100;
                }
                else
                {
                    ans = ans + tens[num / 10];
                    num = num % 10;
                    // ans = ans + units[temp];
                    // num = num / 10;
                    // cout << "nums is" << temp;

                    // Case missed
                    // This was missed, where we are checking for numbers ending with 0, since we have already checked above.
                    if (num != 0)
                    {
                        ans = ans + units[num];
                        num = num / 10;
                    }
                }
            }
        }

        return ans;
    }
    // Leetcode function name is: numberToWords
    string Approach1(int num)
    {
        string finalWord = "";
        int partitionCount = 0;
        if (num == 0)
            return "Zero";

        while (num > 0)
        {
            int temp = num % 1000;
            // Case missed
            // This case is added where we are getting 000 as the number where we are still adding the string from the partition vector.
            if (temp == 0)
            {
                finalWord = convertNumToWords(temp) + finalWord;
            }
            else
            {
                finalWord = convertNumToWords(temp) + partition[partitionCount] + finalWord;
            }
            partitionCount++;
            num = num / 1000;
        }
        // cout << "ans is" << convertNumToWords(7483647) << endl;
        // cout << "final word is:" << endl;
        // cout << finalWord;
        finalWord.resize(finalWord.size() - 1);
        return finalWord;
    }
};
int main()
{
    Solution obj;
    cout << obj.Approach1(1000000) << endl;
    return 0;
}