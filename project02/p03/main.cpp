#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct CompByMod
{
    int m;

    CompByMod(int aM) : m(aM) {}

    bool operator()(const int a, const int b) const
    {
        int rA = a % m;
        int rB = b % m;

        if (rA != rB)
        {
            return rA < rB;
        }

        if (a % 2 != 0 && b % 2 != 0)
        {
            return a > b;
        }

        if (a % 2 != 0 && b % 2 == 0)
        {
            return true;
        }

        if (a % 2 == 0 && b % 2 != 0)
        {
            return false;
        }

        return a < b;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m && n + m > 0)
    {
        vector<int> v(n);

        for (auto &x : v)
            cin >> x;

        sort(begin(v), end(v), CompByMod(m));

        cout << n << " " << m << "\n";

        for (auto d : v)
            cout << d << "\n";
    }

    cout << "0 0\n";
}