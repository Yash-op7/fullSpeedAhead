#include<bits/stdc++.h>
using namespace std;
void check(string &str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        int len = 1;
        int j = i + 1;
        while (j < str.length() && str[j] == c)
        {
            j++;
            len++;
        }
        if (len > 2)
        {
            i = j - 1;
        }
        else
        {
            i = j - 1;
            ans += c;
            if (len > 1)
            {
                ans += c;
            }
        }
    }
    str = ans;
}

int f(int x, string &board, string &hand)
{
    if (board.length() == 0)
    {
        return 0;
    }
    if (x == hand.length())
    {
        return 1e9;
    }
    string temp = board;
    int ans = INT_MAX;
    for (int i = 0; i < board.size() + 1; i++)
    {
        // board.insert(i, 1, hand[x]);
        board = board.substr(0, i) + hand[x] + board.substr(i);
        string gh = board;
        check(board);
        if(x == 0){
            cout<<gh<<" -> "<<board<<endl;
        }
        ans = min(ans, 1 + f(x + 1, board, hand));
        board = temp;
    }
    return ans;
}

int findMinStep(string board, string hand)
{
    int ans = f(0, board, hand);
    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}

int main(){
    cout << findMinStep("WWRRBBWW", "WRBRW");
}