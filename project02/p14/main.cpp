#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<string> v(n);

        for (auto &x : v) cin >> x;

        stable_sort(begin(v), end(v), [](const string &a, const string &b)
                    { return a.substr(0, 2) < b.substr(0, 2); });

        for (auto x : v) cout << x << "\n";
    }
}
