#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, i, t;

    cin >> n;

    vector<string> t1 = {"Happy", "birthday", "to", "you"};

    vector<string> v(n);

    for (auto &x : v)
        cin >> x;

    int i1 = 0, i2 = 0;

    for (t = 0; t < ceil(n / 16) + 1; ++t)
    {
        for (i = 0; i < 16; ++i)
        {
            i1 = i1 % n;
            i2 = i2 % 4;

            if (i == 11)
                cout << v[i1] << ": Rujia"
                     << "\n";
            else
                cout << v[i1] << ": " << t1[i2] << "\n";

            i1++;
            i2++;
        }
    }
}