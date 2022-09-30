#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int t, n, m, i, j, c, f;
    int cnt[10];

    while (cin >> n >> m)
    {
        c = 0;

        for (i = n; i <= m; ++i)
        {
            f = 1;

            memset(cnt, 0, sizeof(cnt));

            j = i;
            while (j > 0)
            {
                cnt[j % 10]++;
                j /= 10;
            }

            for (j = 0; j <= 9; ++j)
            {
                if (cnt[j] > 1)
                {
                    f = 0;
                    break;
                }
            }

            if (f)
                ++c;
        }

        cout << c << "\n";
    }
}