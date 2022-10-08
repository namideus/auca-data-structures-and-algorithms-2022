#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, f, r, i, j;
    double d1, d2, ans;

    while (cin >> f && f)
    {
        cin >> r;

        vector<double> vf(f), vr(r), vm;
        ans = 0;

        for (auto &x : vf)
            cin >> x;
        for (auto &x : vr)
            cin >> x;

        for (auto a : vf)
            for (auto b : vr)
                vm.push_back(b / a);

        sort(vm.begin(), vm.end());

        for (i = 0; i < sz(vm) - 1; i++)
            ans = max(ans, vm[i + 1] / vm[i]);

        cout << fixed << setprecision(2) << ans << "\n";
    }
}
