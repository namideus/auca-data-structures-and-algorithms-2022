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
    double area;

    while (cin >> h >> w)
    {
        area = 0;

        for (i = 0; i < h; ++i)
        {
            a = b = 0;

            f = 0;

            cin >> str;

            for (j = 0; j < w; ++j)
            {
                c = str[j];

                if (c == '\\' || c == '/')
                {
                    a++;
                    f ^= 1;
                }

                if (c == '.' && f)
                    b++;
            }

            area += b + 0.5 * a;
        }

        cout << area << "\n";
    }
}