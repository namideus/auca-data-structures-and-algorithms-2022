#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int n, i, j, m, amnt, f;
    string name, giftee;

    f = 0;

    while (cin >> n)
    {
        if (f > 0)
            cout << "\n";

        f = 1;

        unordered_map<string, int> mp;
        vector<string> v(n);

        for (i = 0; i < n; i++)
        {
            cin >> name;
            mp[name] = 0;
            v[i] = name;
        }

        for (i = 0; i < n; ++i)
        {
            cin >> name >> amnt >> m;

            mp[name] -= (m > 0 ? (amnt - amnt % m) : 0);

            for (j = 0; j < m; ++j)
            {
                cin >> giftee;

                mp[giftee] += (m > 0 ? amnt / m : 0);
            }
        }

        for (auto a : v)
            for (auto b : mp)
                if (a == b.first)
                    cout << b.first << " " << b.second << "\n";
    }
}