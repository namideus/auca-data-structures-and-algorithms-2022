#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int h, w, i, j, f, a, b;
    string str;
    char c;

    vector<pair<string, int>> v{
        {"ABC", 2}, {"DEF", 3}, {"GHI", 4}, {"JKL", 5}, {"MNO", 6}, {"PQRS", 7}, {"TUV", 8}, {"WXYZ", 9}};

    while (cin >> str)
    {
        for (i = 0; i < sz(str); ++i)
        {
            c = str[i];

            f = 0;

            for (auto x : v)
            {
                if (x.first.find(c) != string::npos)
                {
                    cout << x.second;
                    f = 1;
                    break;
                }
            }

            if (!f)
                cout << c;
        }

        cout << "\n";
    }
}