#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class World
{

    friend ostream &operator<<(ostream &out, const World &world);
    vector<vector<int>> columns;
    int N;

private:
    bool is_bad(int a, int b)
    {
        for (auto c : columns)
            if (find(c.begin(), c.end(), a) != c.end() && find(c.begin(), c.end(), b) != c.end())
                return true;

        return a == b;
    }
    vector<int> find_block_positions(int a, int b)
    {
        int cp1 = 0, cp2 = 0, p1 = 0, p2 = 0;
        for (int i = 0; i < N; i++)
        {
            auto c = columns[i];
            for (int j = 0; j < sz(c); ++j)
                if (c[j] == a)
                {
                    p1 = j;
                    cp1 = i;
                    break;
                }
                else if (c[j] == b)
                {
                    p2 = j;
                    cp2 = i;
                    break;
                }
        }
        return {p1, cp1, p2, cp2};
    }
    void reset(vector<int> &v, int p)
    {
        while (sz(v) > p + 1)
        {
            int d = v.back();
            columns[d].push_back(d);
            v.pop_back();
        }
    }

public:
    World(int n);

    void moveOnto(int a, int b)
    {
        if (is_bad(a, b))
            return;
        auto pos = find_block_positions(a, b);
        auto cp1 = pos[1], cp2 = pos[3], p1 = pos[0], p2 = pos[2];
        auto &v1 = columns[cp1], &v2 = columns[cp2];
        reset(v1, p1);
        reset(v2, p2);
        v2.push_back(v1.back());
        v1.pop_back();
    }
    void moveOver(int a, int b)
    {
        if (is_bad(a, b))
            return;
        auto pos = find_block_positions(a, b);
        auto cp1 = pos[1], cp2 = pos[3], p1 = pos[0], p2 = pos[2];
        auto &v1 = columns[cp1], &v2 = columns[cp2];
        reset(v1, p1);
        v2.push_back(v1.back());
        v1.pop_back();
    }
    void pileOnto(int a, int b)
    {
        if (is_bad(a, b))
            return;
        auto pos = find_block_positions(a, b);
        auto cp1 = pos[1], cp2 = pos[3], p1 = pos[0], p2 = pos[2];
        auto &v1 = columns[cp1], &v2 = columns[cp2];
        reset(v2, p2);
        v2.insert(v2.end(), v1.begin() + p1, v1.end());
        v1.erase(v1.begin() + p1, v1.end());
    }
    void pileOver(int a, int b)
    {
        if (is_bad(a, b))
            return;
        auto pos = find_block_positions(a, b);
        auto cp1 = pos[1], cp2 = pos[3], p1 = pos[0], p2 = pos[2];
        auto &v1 = columns[cp1], &v2 = columns[cp2];
        v2.insert(v2.end(), v1.begin() + p1, v1.end());
        v1.erase(v1.begin() + p1, v1.end());
    }
};

World::World(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
        columns.push_back(vector<int>{i});
}
ostream &operator<<(ostream &out, const World &world)
{
    for (int i = 0; i < world.N; ++i)
    {
        out << i << ":";
        auto c = world.columns[i];
        out << (sz(c) > 0 ? " " : "");
        for (int j = 0; j < sz(c); ++j)
            out << c[j] << (j < sz(c) - 1 ? " " : "");
        out << "\n";
    }
    return out;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string cmd1, cmd2;
    int n, a, b;

    cin >> n;

    World world(n);

    while (cin >> cmd1 && cmd1 != "quit")
    {
        cin >> a >> cmd2 >> b;

        switch (cmd1[0])
        {
        case 'm':
            if (cmd2 == "onto")
                world.moveOnto(a, b);
            else
                world.moveOver(a, b);
            break;
        case 'p':
            if (cmd2 == "onto")
                world.pileOnto(a, b);
            else
                world.pileOver(a, b);
            break;
        default:
            break;
        }
    }

    cout << world;
}