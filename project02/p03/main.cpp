#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char letter;
    int count;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, r, c, m, n, ans, ct;

    cin >> x;

    for (int t = 1; t <= x; t++)
    {
        cin >> r >> c >> m >> n;

        map<char, int> cnt;

        ans = 0;
        ct = 0;

        string l;

        for (int i = 0; i < r; i++)
        {
            cin >> l;

            for (int j = 0; j < c; j++)
                cnt[l[j]]++;
        }

        vector<Freq> v;

        for (auto d : cnt)
            v.push_back({d.first, d.second});

        sort(begin(v), end(v), [](Freq a, Freq b)
             { return a.count > b.count; });

        for (auto d : v)
            if (v[0].count == d.count)
                ans += d.count * m;
            else
                ans += d.count * n;

        cout << "Case " << t << ": " << ans << "\n";
    }
}