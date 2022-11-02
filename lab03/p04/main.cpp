#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<string> read_names(int &);
vector<int> find_winner(const int &);
void print_solution(const vector<string> &, const vector<int> &);

int main()
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

        auto ans = find_winner(n);

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

inline vector<int> find_winner(const int &n)
{
    int cnt, mn = 1e9, mx = -1, id = 0;
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
    vector<int> x(cnt);
    int ct[n + 1];

    while (true)
    {
        memset(ct, 0, sizeof(ct));

        for (int i = 0; i < cnt; i++)
            x[i] = v[i][0], ct[x[i]]++;

        mn = 1e9, mx = -1, id = -1;
        for (auto i : x)
        {
            if (ct[i] > mx)
                mx = ct[i], id = i;

            mn = min(mn, ct[i]);
        }

        if (mx * 100.0 / cnt > 50.0)
            return {id};

        if (mx == mn)
        {
            set<int> st(x.begin(), x.end());
            return vector<int>(st.begin(), st.end());
        }

        for (int i = 1; i <= n; i++)
            for (auto &sv : v)
                if (ct[i] == mn)
                    sv.erase(find(sv.begin(), sv.end(), i));
    }
}
