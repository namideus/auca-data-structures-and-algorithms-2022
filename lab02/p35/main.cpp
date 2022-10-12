#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, n, f, ans, b, t, p1, p2, p3;
    char c, l;
    string txt;
    string k = "qwertyuiop[]asdfghjkl;'zxcvbnm,.";

    while (getline(cin, txt))
    {
        for (i = 0; i < sz(txt); ++i)
        {
            c = txt[i];

            if (c == ' ' || c == '\n')
                cout << c;
            else
            {
                p1 = k.find(tolower(c));
                cout << k[p1 - 2];
            }
        }
    }
    cout << "\n";
}