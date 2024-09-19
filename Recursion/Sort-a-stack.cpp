#include <iostream>
#include <stack>

using namespace std;

class Solution
{
    stack<int> s;

public:
    void InsertAtPositionInStack(int temp)
    {
        if (s.size() == 0)
        {
            s.push(temp);
        }
        else if (s.top() < temp)
        {
            int ele = s.top();
            s.pop();
            InsertAtPositionInStack(ele);
            s.push(ele);
        }
        else
        {
            s.push(temp);
        }
    }

    void Sort()
    {
        if (s.size() == 1)
        {
            return;
        }
        int temp = s.top();
        s.pop();
        Sort();
        InsertAtPositionInStack(temp);
    }

    void InsertIntoStack(int temp)
    {
        s.push(temp);
    }

    void DisplayStack()
    {
        int stackSize = s.size();
        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main()
{
    Solution obj;
    int count, temp;
    cout << "How many elements you want to enter into array: " << endl;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter " << (i + 1) << "element: " << endl;
        cin >> temp;
        obj.InsertIntoStack(temp);
    }
    obj.DisplayStack();

    return 0;
}