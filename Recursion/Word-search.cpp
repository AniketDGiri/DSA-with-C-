#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
public:
    bool pathExistFromGivenNode(vector<vector<char>> &board, vector<vector<bool>> &visistedChar, int i, int j, string word, int ind)
    {

        if (ind == word.length())
        {
            return true;
        }

        if (i == -1 || j == -1 || i == board.size() || j == board[0].size() || visistedChar[i][j] == true)
        {
            return false;
        }
        // checking if the current word is not same as the char in board
        if (board[i][j] != word[ind])
        {
            return false;
        }

        visistedChar[i][j] = true;
        // for up direction

        bool up = pathExistFromGivenNode(board, visistedChar, i - 1, j, word, ind + 1);

        // for left direction

        bool left = pathExistFromGivenNode(board, visistedChar, i, j - 1, word, ind + 1);

        // for down direction

        bool down = pathExistFromGivenNode(board, visistedChar, i + 1, j, word, ind + 1);

        // for right direction

        bool right = pathExistFromGivenNode(board, visistedChar, i, j + 1, word, ind + 1);

        visistedChar[i][j] = false;
        return up || left || down || right;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visitedChar(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pathExistFromGivenNode(board, visitedChar, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> arr = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    Solution obj;
    cout << obj.exist(arr, "abcced") << endl;
}