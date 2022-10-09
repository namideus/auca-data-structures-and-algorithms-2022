#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, n, f, ans, maxCnt;
    string str;
    char c, l;

    vector<string> v;
    map<string, int> cnt;

    while (cin >> str && str != "#")
    {
        maxCnt = 0;

        if (str[0] == 'e')
        {
            for (i = 0; i < sz(v); ++i)
            {
                cnt[v[i]]++;

                if (cnt[v[i]] >= maxCnt)
                {
                    ans = i + 1;
                    maxCnt = cnt[v[i]];
                }
            }

            cout << ans << "\n";

            v.clear();
            cnt.clear();
        }
        else
            v.push_back(str);
    }
}