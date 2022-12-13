#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c;

    while (cin >> r >> c && r + c > 0)
    {
        vector<string> v(r);

        for (int i = 0; i < r; i++)
            cin >> v[i];

        vector<string> rotated(c, string(r, ' '));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                rotated[j][i] = v[i][j];

        stable_sort(begin(rotated), end(rotated), [](const string &s1, const string &s2)
                    {
        for (int i = 0; i < sz(s1); i++)
        {
            if (tolower(s1[i]) < tolower(s2[i]))
            return true;

            if (tolower(s1[i]) > tolower(s2[i]))
            return false;
        }
        return false; });

        vector<string> result(r, string(c, ' '));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                result[i][j] = rotated[j][i];

        for (auto d : result)
            cout << d << "\n";

        cout << "\n";
    }
}