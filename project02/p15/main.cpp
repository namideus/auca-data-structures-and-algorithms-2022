#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

// stable_sort with lambda expression (capture), find

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;

    vector<string> v;

    string s;

    getline(cin, s);

    istringstream iss(s);

    for (string w; iss >> w;)
        v.push_back(w);

    cin >> m;

    vector<vector<string>> songs(m);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < sz(v); j++)
        {
            cin >> s;
            songs[i].push_back(s);
        }
    }

    cin >> n;

    while (n--)
    {
        cin >> s;

        auto it = find(begin(v), end(v), s);
        int pos = it - begin(v);

        stable_sort(begin(songs), end(songs), [pos](const vector<string> &v1, const vector<string> &v2)
                    { return v1[pos] < v2[pos]; });

        for (auto attr : v)
            cout << attr << " ";

        cout << "\n";

        for (auto list : songs)
        {
            for (auto song : list)
            {
                cout << song << " ";
            }
            cout << "\n";
        }

        cout << "\n";
    }
}