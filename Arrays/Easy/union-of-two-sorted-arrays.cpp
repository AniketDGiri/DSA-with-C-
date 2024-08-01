#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    void Approach1(vector<int> arr1, vector<int> arr2)
    {
        unordered_map<int, int> map_data;
        unordered_map<int, int>::iterator itr;
        int n = arr1.size();
        int m = arr2.size();

        // code for inserting the first array
        for (int i = 0; i < n; i++)
        {
            if (map_data.find(arr1[i]) == map_data.end())
            {
                map_data[arr1[i]]++;
            }
        }

        // code for inserting th second array
        for (int i = 0; i < m; i++)
        {
            if (map_data.find(arr2[i]) == map_data.end())
            {
                map_data[arr2[i]]++;
            }
        }

        // printing all the unique elements
        for (itr = map_data.begin(); itr != map_data.end(); itr++)
        {
            cout << itr->first << " ";
        }
        cout << endl;
    } // approach1

    // using set data structure
    void Approach2(vector<int> arr1, vector<int> arr2)
    {
        unordered_set<int> set_data;

        for (auto itr = arr1.begin(); itr != arr1.end(); itr++)
        {
            set_data.insert(*itr);
        }

        for (auto itr = arr2.begin(); itr != arr2.end(); itr++)
        {
            set_data.insert(*itr);
        }

        for (auto itr = set_data.begin(); itr != set_data.end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr1 = {-7, 8};
    vector<int> arr2 = {-8, -3, 8};
    Solution obj;
    obj.Approach1(arr1, arr2);
    obj.Approach2(arr1, arr2);
    return 0;
}