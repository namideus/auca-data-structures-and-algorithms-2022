#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, cnt;
    string str;
    char c;

    cin >> t;

    cin.ignore();

    while (t--)
    {
        getline(cin, str);

        cnt = 0;

        for (auto x : str)
            if (x == 'M')
                cnt++;
            else if (x == 'F')
                cnt--;

        cout << (cnt == 0 && sz(str) > 2 ? "LOOP" : "NO LOOP") << "\n";
    }
}