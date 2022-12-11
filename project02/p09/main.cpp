#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, s, ans;

    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        cin >> s;

        vector<int> b, r;

        for (int i = 0; i < s; i++)
        {
            string x;
            cin >> x;

            if (x.back() == 'B')
                b.push_back(stoi(x.substr(0, sz(x) - 1)));
            else
                r.push_back(stoi(x.substr(0, sz(x) - 1)));
        }

        sort(begin(b), end(b));
        sort(begin(r), end(r));

        int MIN = min(sz(b), sz(r));

        ans = accumulate(begin(b) + sz(b) - MIN, end(b), -MIN);
        ans = accumulate(begin(r) + sz(r) - MIN, end(r), ans - MIN);

        cout << "Case #" << test << ": " << ans << "\n";
    }
}