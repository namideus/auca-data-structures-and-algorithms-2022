#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int t, n, i, j, r, ans, sum, vito;

    cin >> t;

    while (t--)
    {
        cin >> r;

        vector<int> v(r);

        for(auto &x : v) cin >> x;

        ans = 1e9;

        sort(v.begin(), v.end());

        vito = (v[0]+v[r-1])/2;

        for(i = 0; i <= v[r-1]; i++)
        {
            sum = 0;

            for(j = 0; j < r; j++)
            {
                sum += abs(v[j]-i);
            }

            ans = min(ans, sum);
        }

        cout << ans << "\n";
    }
}