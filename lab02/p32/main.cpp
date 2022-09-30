#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int t, n, i, j;

    cin >> t;

    while (t--)
    {
        int cnt[10];

        memset(cnt, 0, sizeof(cnt));

        cin >> n;

        for (i = 1; i <= n; ++i)
        {
            j = i;
            while (j > 0)
            {
                cnt[j % 10]++;
                j /= 10;
            }
        }

        for (i = 0; i <= 9; ++i)
            cout << cnt[i] << (i < 9 ? " " : "");

        cout << "\n";
    }
}