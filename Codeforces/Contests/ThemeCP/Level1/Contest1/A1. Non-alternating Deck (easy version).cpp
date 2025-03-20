
// simple template for competitive programming

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vs = vector<string>;

#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

void solution(int n)
{
    int player1 = 0, player2 = 0;
    bool player1Turn = true;
    int amountToAdd = 1;

    while (player1 + player2 < n)
    {
        if (player1 + player2 + amountToAdd > n)
        {
            if (player1Turn)
            {
                player1 += n - player1 - player2;
            }
            else
            {
                player2 += n - player1 - player2;
            }
            break;
        }

        if (player1Turn)
        {
            player1 += amountToAdd;
        }
        else
        {
            player2 += amountToAdd;
        }
        player1Turn = !player1Turn;
        amountToAdd += 4;
    }

    cout << player1 << ' ' << player2 << endl;
}

int main()
{
    int t = 1;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solution(n);
    }

    return 0;
}

/*

1, 4, 5, 8, 9, 12, 13 => 1, 9, 17, 25
2, 3, 6, 7, 10, 11, 14, 15 => 5, 13, 21, 29

*/