#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int ascii;
    int value;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    char c;
    string s;
    bool f = false;

    while (getline(cin, s))
    {
        if (f)
            cout << "\n";

        f = true;

        n = sz(s);

        vector<Pair> v;
        map<int, int> cnt;

        for (int i = 0; i < n; i++)
        {
            cnt[(int)s[i]]++;
        }

        for (auto d : cnt)
            v.push_back({d.first, d.second});

        sort(begin(v), end(v), [](Pair a, Pair b)
             { 
                        if(a.value == b.value)
                            return a.ascii > b.ascii;

                        return a.value < b.value; });

        for (auto d : v)
            cout << d.ascii << " " << d.value << "\n";
    }
}
