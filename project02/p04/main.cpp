#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string dna;
    int inversions;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, r, c, m, n, ans, ct, inv;

    cin >> test;

    for (int t = 1; t <= test; t++)
    {
        cin >> n >> m;

        string l;

        vector<SpecialString> v(m);

        for (auto &x : v)
        {
            inv = 0;

            cin >> l;

            x.dna = l;

            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (l[i] > l[j])
                        inv++;

            x.inversions = inv;
        }

        stable_sort(begin(v), end(v), [](SpecialString a, SpecialString b)
                    { return a.inversions < b.inversions; });

        for (auto d : v)
            cout << d.dna << "\n";

        if (t < test)
            cout << "\n";
    }
}