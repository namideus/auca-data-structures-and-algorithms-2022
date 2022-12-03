#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    string s, r;

    vector<pair<int, string>> v;

    cin >> n;

    for (int t = 1; t <= n; t++)
    {
        cin >> s >> r;

        if (isdigit(s[0]))
        {
            d = stoi(s) / 2;
            v.emplace_back(d, r);
        }
        else
        {
            d = stoi(r);
            v.emplace_back(d, s);
        }
    }

    sort(begin(v), end(v), [](pair<int, string> a, pair<int, string> b)
         { return a.first < b.first; });

    for (auto x : v)
        cout << x.second << "\n";
}
