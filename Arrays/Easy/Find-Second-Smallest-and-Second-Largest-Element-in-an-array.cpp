#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findSecondMax(vector<int> &v)
{
    pair<int, int> p1;
    int fmax = v[0];
    int fmin = v[0];
    int smax = INT_MIN;
    int smin = INT_MAX;

    vector<int>::iterator itr;

    for (itr = v.begin() + 1; itr != v.end(); itr++)
    {
        if (*itr > fmax)
        {
            smax = fmax;
            fmax = *itr;
        }
        else if (*itr > smax && *itr != fmax)
        {
            smax = *itr;
        }
    }
    return smax;
}
int main()
{
    vector<int> vec = {1, 2, 4, 7, 7, 5};
    int p = findSecondMax(vec);
    cout << p << endl;
    return 0;
}