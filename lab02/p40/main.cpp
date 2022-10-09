#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;
    string str, w;
    char c, l;
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    while (getline(cin, str))
    {
        w = "";
        str += "\n";

        for (i = 0; i < sz(str); i++)
        {
            c = str[i];

            if (isalpha(c))
            {
                w += c;
            }
            else
            {
                if (w != "")
                {
                    if (find(v.begin(), v.end(), tolower(w[0])) != v.end())
                        cout << w << "ay";
                    else if (w[0] != ' ')
                    {
                        l = w[0];
                        w.erase(0, 1);
                        cout << w << l << "ay";
                    }
                }
                cout << c;
                w = "";
            }
        }
    }
}