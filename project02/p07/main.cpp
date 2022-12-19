#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Submission
{
    int contestant, problem, penalty, solved;
    vector<int> cnt;
    bitset<10> isSolved;

    Submission() : contestant(0), problem(0), penalty(0), solved(0), cnt(vector<int>(10)) {}
    Submission(int a) : contestant(a), problem(0), penalty(0), solved(0), cnt(vector<int>(10)) {}
    Submission(int a, int b, int c) : contestant(a), penalty(b), solved(c), cnt(vector<int>(10)) {}
};

struct CmpTeamByNumber
{
    bool operator()(const Submission &s1, const Submission &s2) const
    {
        return s1.contestant < s2.contestant;
    }
};

struct CmpTeamByACMRules
{
    bool operator()(const Submission &s1, const Submission &s2) const
    {
        if (s1.solved != s2.solved)
            return s1.solved > s2.solved;

        if (s1.penalty != s2.penalty)
            return s1.penalty < s2.penalty;

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--)
    {
        vector<Submission> v;

        for (string in; getline(cin, in) && sz(in) != 0;)
        {
            int no, pr, pe, penalty = 0, solved = 0, trial = 0;
            char ve;

            istringstream iss(in);

            iss >> no >> pr >> pe >> ve;

            auto it = find_if(begin(v), end(v), [no](const Submission &s)
                              { return s.contestant == no; });

            if (ve == 'I')
            {
                if (it != end(v))
                    it->cnt[pr]++;

                trial = 1, solved = 0;
            }
            if (ve == 'C')
            {
                penalty = pe, solved = 1;

                if (it != end(v))
                    penalty += it->cnt[pr] * 20;
            }

            if (it != end(v))
            {
                if (!it->isSolved[pr])
                {
                    it->penalty += penalty;
                    it->solved += solved;
                    it->isSolved[pr] = solved;
                }
            }
            else
            {
                Submission sb(no, penalty, solved);
                sb.isSolved[pr] = solved;
                sb.cnt[pr] = trial;
                v.push_back(sb);
            }
        }

        sort(begin(v), end(v), CmpTeamByNumber());
        stable_sort(begin(v), end(v), CmpTeamByACMRules());

        for (auto x : v)
            cout << x.contestant << " " << x.solved << " " << x.penalty << "\n";

        if (t)
            cout << "\n";
    }
}