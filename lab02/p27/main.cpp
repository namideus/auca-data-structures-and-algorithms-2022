#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, j, n, k, test, cnt;
    string names;

    cin >> test;

    for (t = 1; t <= test; t++)
    {
        cin >> n >> k >> names;

        cnt = 0;

        deque<char> d;

        for (i = 0; i < n; ++i)
        {
            char p = names[i];

            if (find(d.begin(), d.end(), p) != d.end())
                cnt++;

            d.push_back(p);

            if (d.size() > k)
                d.pop_front();
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }
}