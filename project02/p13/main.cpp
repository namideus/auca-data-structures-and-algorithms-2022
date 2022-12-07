#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline void solve(vector<string> &v)
{
    int mx = 0;

    for (auto s : v)
        mx = max(mx, sz(s));

    sort(begin(v), end(v), [](string a, string b)
         {
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));

    return a < b; });

    for (auto &s : v)
        cout << right << setw(mx) << s << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    vector<string> v;

    while (getline(cin, s))
    {
        if (!sz(s))
        {
            solve(v);
            cout << "\n";
            v.clear();
            continue;
        }

        v.push_back(s);
    }

    solve(v);
}
