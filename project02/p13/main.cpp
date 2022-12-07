#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline void solve(vector<string> &v, int mx)
{
    sort(begin(v), end(v), [](const string &a, const string &b)
         {
    auto itA = a.rbegin();
    auto itB = b.rbegin();

    while(itA != a.rend() || itB != b.rend())
    {
      if(*itA != *itB)
        return *itA < *itB;

      itA++;
      itB++;
    }

    return sz(a) > sz(b); });

    for (auto &s : v)
        cout << right << setw(mx) << s << "\n";

    v.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int mx = 0;
    string s;
    vector<string> v;

    while (getline(cin, s))
    {
        if (sz(s))
        {
            v.push_back(s);
            mx = max(mx, sz(s));
        }
        else
        {
            solve(v, mx);
            cout << "\n";
        }
    }

    solve(v, mx);
}