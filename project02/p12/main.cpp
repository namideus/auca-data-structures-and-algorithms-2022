#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

typedef pair<string, string> pss;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
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

            string w, rank = "";
            istringstream iss2(status + "-");

            while (!iss2.eof())
            {
                getline(iss2, w, '-');

                if (w[0] == 'u')
                    rank = "3" + rank;
                else if (w[0] == 'm')
                    rank = "2" + rank;
                else if (w[0] == 'l')
                    rank = "1" + rank;
            }

            for (int j = 0; j < 10; j++)
            {
                rank += "2";
            }

            p.push_back({name, rank});
        }

        stable_sort(begin(p), end(p), [](const pss &p1, const pss &p2)
                    {
            for (int i = 0; i < 10; i++)
            {
                if (p1.second[i] == p2.second[i])
                    continue;

                if (p1.second[i] > p2.second[i])
                    return true;

                if (p1.second[i] < p2.second[i])
                    return false;
            }
            return p1.first < p2.first; });

        for (auto d : p)
            cout << d.first << "\n";

        cout << string(30, '=') << "\n";
    }
}
