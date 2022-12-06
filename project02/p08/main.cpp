#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, t;
    bool f = false;

    cin >> N >> t;

    vector<int> v(N);

    for (auto &x : v)
        cin >> x;

    sort(begin(v), end(v));

    if (t == 1)
    {
        for (auto x : v)
        {
            for (auto y : v)
            {
                if (x != y && x + y == 7777)
                {
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        cout << (f ? "Yes" : "No");
    }

    if (t == 2)
    {
        for (auto x : v)
        {
            auto lo = lower_bound(begin(v), end(v), x);
            auto up = upper_bound(begin(v), end(v), x);

            if (up - lo > 1)
            {
                f = true;
                break;
            }
        }
        cout << (f ? "Contains duplicate" : "Unique");
    }

    if (t == 3)
    {
        for (auto x : v)
        {
            auto lo = lower_bound(begin(v), end(v), x);
            auto up = upper_bound(begin(v), end(v), x);

            if (up - lo > N / 2)
            {
                cout << *lo;
                f = true;
                break;
            }
        }
        if (!f)
            cout << "-1";
    }

    if (t == 4)
    {
        if (N & 1)
        {
            cout << v[N / 2];
        }
        else
        {
            cout << v[N / 2 - 1] << " " << v[N / 2];
        }
    }

    if (t == 5)
    {
        auto lo = lower_bound(begin(v), end(v), 100);
        auto up = upper_bound(begin(v), end(v), 999);

        for (int i = lo - begin(v); i < up - begin(v); i++)
        {
            cout << v[i] << " ";
        }
    }
}
