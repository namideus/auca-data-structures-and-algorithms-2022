#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<string> read_names(int &);
vector<int> find_winner(const vector<string> &, const int &);
void print_solution(const vector<string> &, const vector<int> &);

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n;

        auto names = read_names(n);

        auto ans = find_winner(names, n);

        print_solution(names, ans);

        if (t > 0)
            cout << "\n";
    }
}

inline void print_solution(const vector<string> &names, const vector<int> &ans)
{
    for (auto id : ans)
        cout << names[id - 1] << "\n";
}

inline vector<string> read_names(int &n)
{
    cin >> n;

    vector<string> v(n);

    cin.ignore();

    for (auto &x : v)
        getline(cin, x);

    return v;
}

inline vector<int> find_winner(const vector<string> &names, const int &n)
{
    int a, cnt;
    vector<vector<int>> v;

    for (string s; getline(cin, s, '\n') && isdigit(s[0]);)
    {
        istringstream iss(s);
        vector<int> votes(n);

        for (auto &x : votes)
            iss >> x;

        v.push_back(votes);
    }

    cnt = sz(v);

    while (true)
    {
        vector<int> x(cnt);

        for (int i = 0; i < cnt; i++)
            x[i] = v[i][0];

        set<int> st(x.begin(), x.end());

        if (sz(st) == cnt)
            return vector<int>(st.begin(), st.end());

        int min_count = 1e9, min_id = 0, c = 0;
        for (auto d : x)
        {
            c = count(x.begin(), x.end(), d);

            if (c < min_count)
            {
                min_count = c;
                min_id = d;
            }
        }

        for (auto &x : v)
            x.erase(find(x.begin(), x.end(), min_id));

        for (auto id : x)
            if ((double)count(x.begin(), x.end(), id) * 100.0 / cnt > 50.0)
                return {id};
    }
}
