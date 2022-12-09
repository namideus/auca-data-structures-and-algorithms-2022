#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string name;
    int val;

    Skill(): name(""), val(0){};

    Skill(string a, int b) : name(a), val(b){};
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;

    cin >> m >> n;

    vector<Skill> v(m);

    for(auto &x : v)
        cin >> x.name >> x.val;

    sort(begin(v), end(v), [](const Skill &a, const Skill &b)
    {
        return a.name < b.name;
    });

    for(int i = 0; i < n; i++)
    {   
        int ans = 0;

        for(string txt; cin >> txt && txt != ".";)
        {   
            auto it = lower_bound(begin(v), end(v), Skill{txt, 0}, [](const Skill &a, const Skill &b) 
            {
                return a.name < b.name;
            });

            if(it != end(v) && txt == it->name)
            {
                ans += it->val;
            }
        }

        cout << ans << "\n";
    }
}