#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int i, cnt, f;
    string s, t;
    char c;

    t = "";

    f = 0;

    while (getline(cin, s))
    {
        for (i = 0; i < sz(s); i++)
        {
            c = s[i];

            if (c == '\"' && !f)
            {
                cout << "``";
                f ^= 1;
            }
            else if (c == '\"' && f)
            {
                cout << "''";
                f ^= 1;
            }
            else
                cout << c;
        }
        cout << "\n";
    }
}