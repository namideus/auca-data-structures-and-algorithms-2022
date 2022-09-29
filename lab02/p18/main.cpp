#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int k, m, i, j, c, r, right, left, mid, num, cnt;
    bool f;

    while (cin >> k >> m && k)
    {
        f = true;

        vector<int> v(k);

        for (auto &x : v)
            cin >> x;

        sort(v.begin(), v.end());

        for (i = 0; i < m; ++i)
        {
            cin >> c >> r;

            cnt = 0;

            for (j = 0; j < c; ++j)
            {
                cin >> num;

                left = 0;
                right = k;

                while (left <= right)
                {
                    mid = (left + right) / 2;

                    if (v[mid] == num)
                    {
                        cnt++;
                        break;
                    }
                    else if (num > v[mid])
                        left++;
                    else
                        right--;
                }
            }

            if (r > cnt)
                f = false;
        }

        cout << (f ? "yes" : "no") << "\n";
    }
}