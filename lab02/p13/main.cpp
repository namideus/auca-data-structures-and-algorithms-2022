#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, b, r, d, c, v;
    bool f;

    while (cin >> b >> n && b + n)
    {
        f = true;
        vector<int> r(b);

        for (auto &x : r) cin >> x;

        for (int i = 0; i < n; i++)
        {
            cin >> d >> c >> v;

            r[d-1] -= v;
            r[c-1] += v;
        }

        for(auto x : r)
            if(x < 0) 
            {
                f = false;
                break;
            }
        
        cout << (f ? "S" : "N") << "\n";
    }
}
