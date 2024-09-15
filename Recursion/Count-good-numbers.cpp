#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    long long mod = 1e9 + 7;

public:
    bool calculatePrimeAndEven(long long eachNumber)
    {
        int digitPos = 0; // 0-based index for positions
        bool isGoodNumber = true;

        while (eachNumber > 0 && isGoodNumber)
        {
            int num = eachNumber % 10; // Get the last digit
            eachNumber /= 10;          // Remove the last digit

            if (digitPos % 2 == 0) // Even position (0-based)
            {
                if (num % 2 != 0) // Number should be even
                {
                    isGoodNumber = false;
                }
            }
            else // Odd position (0-based)
            {
                // Number should be prime (only 2, 3, 5, or 7 are prime digits)
                if (num != 2 && num != 3 && num != 5 && num != 7)
                {
                    isGoodNumber = false;
                }
            }
            digitPos++;
        }

        return isGoodNumber;
    }
    int countGoodNumbersApproach1(long long n)
    {

        long long start = pow(10, (n - 1));

        long long end = pow(10, n);
        long long ans = 0;
        if (n == 1)
        {
            ans = 1;
        }

        for (start; start < end; start++)
        {

            if (calculatePrimeAndEven(start))
            {
                cout << start << endl;
                ans += 1;
            }
        }
        return ans % (1000000000 + 7);
    }

    long long calculateBinaryExpo(long long x, long long n)
    {

        long long ans = 1;
        long long M = 1e9 + 7;
        while (n > 0)
        {
            if (n % 2)
            {
                ans = (ans * x) % M;
                n--;
            }
            else
            {
                x = (x * x) % M;
                n = n / 2;
            }
        }
        return ans % M;
    }
    int Approach2(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = (n / 2);
        long long M = 1e9 + 7;
        cout << "---" << calculateBinaryExpo(5, even) << endl;
        return (calculateBinaryExpo(5, even) * calculateBinaryExpo(4, odd)) % M;
    }
    long long power(long long x, long long n)
    {
        long long ans = 1;
        while (n != 0)
        {
            if (n & 1)
                ans = (ans * x) % mod;
            x = (x * x) % mod;
            n = n >> 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        long long even = (n / 2) + (n % 2);
        long long odd = n / 2;
        long long evenx = power(5, even);
        cout << "Evenx" << evenx << endl;
        long long oddx = power(4, odd);
        return (evenx * oddx) % mod;
    }
};

int main()
{
    Solution obj;
    // cout << obj.countGoodNumbersApproach1(4) << endl;
    //  obj.calculatePrimeAndEven(2582);
    cout << obj.Approach2(50) << endl;
    cout << obj.countGoodNumbers(50) << endl;
    return 0;
}