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

    int ans, b1, g1, c1, b2, g2, c2, b3, g3, c3;
    string res;
    vector<pair<int, string>> cmb = {{0, "BGC"}, {0, "BCG"}, {0, "CBG"}, {0, "GBC"}, {0, "GCB"}, {0, "CGB"}};

    while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3)
    {
        ans = INF;

        cmb[0].first = b2 + b3 + g1 + g3 + c1 + c2;
        cmb[1].first = b2 + b3 + c1 + c3 + g1 + g2;
        cmb[2].first = c2 + c3 + b1 + b3 + g1 + g2;
        cmb[3].first = g2 + g3 + b1 + b3 + c1 + c2;
        cmb[4].first = g2 + g3 + c1 + c3 + b1 + b2;
        cmb[5].first = c2 + c3 + g1 + g3 + b1 + b2;

        for (auto &x : cmb)
            if (x.first < ans || x.first == ans && res > x.second)
                ans = x.first, res = x.second;

        cout << res << " " << ans << "\n";
    }
}