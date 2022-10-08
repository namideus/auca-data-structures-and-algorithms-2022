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

    int t = 1, n, i, j, sum, m, ans, q, d;

    while (cin >> n && n)
    {
        vector<int> v(n);

        for (auto &x : v)
            cin >> x;

        cin >> m;

        cout << "Case " << t << ":\n";

        while (m--)
        {
            cin >> q;

            d = INF;

            for (i = 0; i < n; ++i)
                for (j = 1; j < n; ++j)
                    if (v[i] != v[j])
                    {
                        sum = v[i] + v[j];

                        if (abs(q - sum) < d)
                        {
                            ans = sum;
                            d = abs(q - sum);
                        }
                    }

            cout << "Closest sum to " << q << " is " << ans << ".\n";
        }

        t++;
    }
}