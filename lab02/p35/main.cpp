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

    int i, k, j, n, f, ans, b, t, p1, p2, p3;
    char c, l;
    string txt;
    string k1 = "qwertyuiop[]";
    string k2 = "asdfghjkl;'";
    string k3 = "zxcvbnm,.";

    while (getline(cin, txt, '\n'))
    {
        for (i = 0; i < sz(txt); ++i)
        {
            c = txt[i];

            if (c == ' ' || c == '\n')
                cout << c;
            else
            {
                p1 = k1.find(tolower(c));
                p2 = k2.find(tolower(c));
                p3 = k3.find(tolower(c));

                if (p1 != string::npos)
                    cout << k1[p1 - 2];
                else if (p2 != string::npos)
                    cout << k2[p2 - 2];
                else if (p3 != string::npos)
                    cout << k3[p3 - 2];
            }
        }
    }

    cout << "\n";
}