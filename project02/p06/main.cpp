#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Team
{
    string name;
    int b, c, d, e, f, g, h, i;

    Team() : name(""), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0) {}
    Team(string s) : name(s), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0) {}
};

struct CmpByName
{
    bool operator()(const Team &t1, const Team &t2) const
    {
        return t1.name < t2.name;
    }
};

struct CmpByResult
{
    bool operator()(const Team &t1, const Team &t2) const
    {

        if (t1.b != t2.b)
            return t1.b > t2.b;

        if (t1.d != t2.d)
            return t1.d > t2.d;

        if (t1.g != t2.g)
            return t1.g > t2.g;

        if (t1.h != t2.h)
            return t1.h > t2.h;

        if (t1.c != t2.c)
            return t1.c < t2.c;

        string teamName1 = t1.name;
        string teamName2 = t2.name;

        for (auto &x : teamName1)
            x = tolower(x);

        for (auto &x : teamName2)
            x = tolower(x);

        return teamName1 < teamName2;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t, g;
    char ch;

    cin >> n;
    cin.ignore();

    while (n--)
    {
        string tournament;
        getline(cin, tournament);

        cin >> t;
        cin.ignore();

        vector<Team> v(t);

        for (auto &x : v)
        {
            string team;
            getline(cin, team);
            x = Team(team);
        }

        sort(begin(v), end(v), CmpByName());

        cin >> g;
        cin.ignore();

        for (int k = 0; k < g; k++)
        {
            string game, gameTeam1, gameTeam2, teamName1, teamName2;
            int g1, g2;
            getline(cin, game);

            istringstream iss(game);
            getline(iss, gameTeam1, '@');
            getline(iss, gameTeam2);

            iss = istringstream(gameTeam1);
            getline(iss, teamName1, '#');
            iss >> g1;

            iss = istringstream(gameTeam2);
            iss >> g2 >> ch;
            getline(iss, teamName2);

            auto itTeam1 = lower_bound(begin(v), end(v), teamName1, CmpByName());
            auto itTeam2 = lower_bound(begin(v), end(v), teamName2, CmpByName());

            itTeam1->c++;
            itTeam2->c++;
            itTeam1->h += g1;
            itTeam2->h += g2;
            itTeam1->i += g2;
            itTeam2->i += g1;
            itTeam1->g = itTeam1->h - itTeam1->i;
            itTeam2->g = itTeam2->h - itTeam2->i;
            if (g1 > g2)
            {
                itTeam1->b += 3;
                itTeam1->d++;
                itTeam2->f++;
            }
            else if (g2 > g1)
            {
                itTeam2->b += 3;
                itTeam2->d++;
                itTeam1->f++;
            }
            else if (g1 == g2)
            {
                itTeam1->b++;
                itTeam2->b++;
                itTeam1->e++;
                itTeam2->e++;
            }
        }

        sort(begin(v), end(v), CmpByResult());

        cout << tournament << "\n";

        for (int i = 0; i < sz(v); i++)
        {
            auto t = v[i];
            cout << i + 1 << ") " << t.name << " " << t.b << "p, " << t.c << "g (" << t.d << "-" << t.e << "-" << t.f << "), " << t.g << "gd (" << t.h << "-" << t.i << ")\n";
        }

        if (n > 0)
            cout << "\n";
    }
}