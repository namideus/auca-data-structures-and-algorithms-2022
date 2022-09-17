#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    long long i, t, n, res;

    cin >> t;

    while (t--)
    {
        cin >> n;
        res = 0;

        for (i = 1; i <= (long long)10e19; i++)
        {
            n -= i;

            if (n >= 0)
                ++res;
            else
                break;
        }
        cout << res << "\n";
    }
}