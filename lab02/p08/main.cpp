#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int f;
    string s;
    f = 0;

    while (getline(cin, s))
    {
        for (auto c : s)
        {
            if (c == '\"' && !f)
            {
                cout.put('`');
                cout.put('`');
                f ^= 1;
            } else if (c == '\"' && f)
            {
                cout.put('\'');
                cout.put('\'');
                f ^= 1;
            }
            else
                cout << c;
        }
        cout << "\n";
    }
}