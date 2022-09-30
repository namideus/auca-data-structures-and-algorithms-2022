#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);

    int t, n, i, j, cnt, sum;

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> a(n);

        for (auto &x : a)
            cin >> x;

        sum = 0;

        for (i = n - 1; i >= 0; i--)
        {
            cnt = 0;

            for (j = i - 1; j >= 0; j--)
            {
                if (a[i] >= a[j])
                    cnt++;
            }

            sum += cnt;
        }

        cout << sum << "\n";
    }
}