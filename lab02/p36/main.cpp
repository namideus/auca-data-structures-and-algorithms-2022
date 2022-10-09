#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, j, test, f;
    string str, ans, cnt;
    char c;

    cin >> t;

    for (test = 1; test <= t; test++)
    {
        cin >> str;
        str += "C";
        cnt = ans = "";
        f = 0;

        for (i = 0; i < sz(str); ++i)
        {
            if (isalpha(str[i]))
            {
                if (f)
                {
                    for (j = 0; j < stoi(cnt); j++)
                        ans += c;
                    f = 0;
                    cnt = "";
                }
                c = str[i];
            }
            else
            {
                f = 1;
                cnt += str[i];
            }
        }

        cout << "Case " << test << ": " << ans << "\n";
        ans = "";
    }
}