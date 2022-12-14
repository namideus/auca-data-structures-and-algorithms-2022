#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

typedef pair<string, string> pss;

// stable_sort, pair<string, string>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    char ch;
    string s, name, status;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin.ignore();

        vector<pair<string, string>> p;

        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            istringstream iss(s);
            getline(iss, name, ':');
            iss >> status;
            p.push_back({name, status});
        }

        stable_sort(begin(p), end(p), [](const pss &p1, const pss &p2)
                    {
            string w1, w2, c1 = p1.second + "-", c2 = p2.second + "-";
            istringstream iss1(c1), iss2(c2);

            if (c1 == c2)
                return p1.first < p2.first;

            while (!iss1.eof() && !iss2.eof())
            {
                getline(iss1, w1, '-');
                getline(iss2, w2, '-');

                // cout << w1 << "   " << w2 << "\n";
                if (w1 != w2)
                {
                    if (w1 == "upper")
                        return true;

                    if (w2 == "upper")
                        return false;

                    if (w1 == "middle")
                        return true;

                    if (w2 == "middle")
                        return false;

                    if (w1 == "lower")
                        return true;

                    if (w2 == "lower")
                        return false;
                }
            }

            return p1.first < p2.first; });

        for (auto d : p)
            cout << d.first << "\n";

        cout << string(30, '=') << "\n";
    }
}