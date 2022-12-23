#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    while (cin >> n && n)
    {
        vector<string> v(n);

        for (auto &x : v)
            cin >> x;

        stable_sort(begin(v), end(v), [](const string &a, const string &b)
                    { return a.substr(0, 2) < b.substr(0, 2); });

        for (auto x : v)
            cout << x << "\n";
    }
}
