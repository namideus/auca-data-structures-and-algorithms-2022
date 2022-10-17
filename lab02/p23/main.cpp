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

    string s;
    int i, k, j, n, l, f, ans, b, t;

    for (string btm, top; cin >> btm >> top;)
    {
        if (sz(btm) < sz(top))
            swap(btm, top);

        ans = -1;
        n = sz(top);
        l = sz(btm);

        for (i = 0; i < l - n + 1; ++i)
        {
            s = btm.substr(i, n);
            f = 1;

            for (j = 0; j < n; ++j)
                if (s[j] == top[j] && s[j] == '2')
                {
                    f = 0;
                    break;
                }

            if (f)
            {
                ans = l;
                break;
            }
        }

        if (ans == -1)
        {
            ans = INF;

            for (k = 1; k < n; ++k)
            {
                s = top.substr(n - k, n);
                f = 1;

                for (i = 0; i < k; ++i)
                    if (s[i] == btm[i] && s[i] == '2')
                    {
                        f = 0;
                        break;
                    }

                if (f)
                {
                    ans = min(n - k + l, ans);
                }
            }

            for (k = 1; k < n; ++k)
            {
                s = top.substr(0, k);

                f = 1;

                for (i = l - k, j = 0; i < l; ++i, ++j)
                    if (s[j] == btm[i] && s[j] == '2')
                    {
                        f = 0;
                        break;
                    }

                if (f)
                {
                    ans = min(n - k + l, ans);
                }
            }
        }

        if (ans != INF)
            cout << ans << "\n";
        else
            cout << l + n << "\n";
    }
}