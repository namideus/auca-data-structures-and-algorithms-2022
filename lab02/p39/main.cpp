#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int i, cnt;
    string s, w;

    while (getline(cin, s))
    {
        istringstream iss(s);

        deque<int> v;

        cnt = 0;

        for (auto x : s)
            if (x == ' ')
                cnt++;
            else if (cnt > 0)
            {
                v.push_back(cnt);
                cnt = 0;
            }

        int id = 0;

        while (iss >> w)
        {
            reverse(w.begin(), w.end());
            cout << w;

            if (id < v.size())
                for (i = 0; i < v[id]; i++)
                    cout << " ";

            id++;
        }

        cout << "\n";
    }
}