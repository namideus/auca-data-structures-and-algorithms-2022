#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n, f, ans, c, min_cnt;
    string str;

    vector<string> v;

    while (cin >> str && str != "#")
    {
        if (str[0] == 'e')
        {
            min_cnt = INF;

            for (i = 0; i < sz(v); ++i)
            {
                c = 0;

                for (j = 0; j < sz(v); ++j)
                {
                    if (i != j)
                    {
                        for (k = 1; k <= 17; k += 4)
                            if (v[i][k - 1] != v[j][k - 1] || v[i][k + 1] != v[j][k + 1])
                                c++;
                    }
                }

                // cout << "cnt = " << c <<"\n";

                if (c <= min_cnt)
                {
                    min_cnt = c;
                    ans = i + 1;
                }
            }

            cout << ans << "\n";

            v.clear();
        }
        else
            v.push_back(str);
    }
}