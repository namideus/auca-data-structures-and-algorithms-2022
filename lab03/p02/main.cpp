#include <bits/stdc++.h>
#define INF 1e9
typedef long long int lli;

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool read_puzzle(char (&)[5][5]);
void solve_puzzle(char (&)[5][5], string &, int);
void read_moves(string &);

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    char puzzle[5][5];
    string moves;

    while (read_puzzle(puzzle))
    {
        read_moves(moves);

        solve_puzzle(puzzle, moves, t);

        t++;
    }
}

bool read_puzzle(char (&puzzle)[5][5])
{
    string line;

    for (int i = 0; i < 5; i++)
    {
        getline(cin, line);

        if (line == "Z")
            return false;

        for (int j = 0; j < 5; ++j)
            puzzle[i][j] = (line[j] == 0 ? ' ' : line[j]);
    }
    return true;
}

void solve_puzzle(char (&puzzle)[5][5], string &moves, int test)
{
    bool is_correct = true;
    int e_i, e_j;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; ++j)
            if (puzzle[i][j] == ' ')
            {
                e_i = i;
                e_j = j;
                break;
            }
    }

    if (test > 1)
        cout << "\n";

    for (int i = 0; i < moves.size(); ++i)
    {
        switch (moves[i])
        {
        case 'A':
            swap(puzzle[e_i][e_j], puzzle[e_i - 1][e_j]);
            --e_i;
            break;
        case 'B':
            swap(puzzle[e_i][e_j], puzzle[e_i + 1][e_j]);
            ++e_i;
            break;
        case 'L':
            swap(puzzle[e_i][e_j], puzzle[e_i][e_j - 1]);
            --e_j;
            break;
        case 'R':
            swap(puzzle[e_i][e_j], puzzle[e_i][e_j + 1]);
            ++e_j;
            break;
        default:
            is_correct = false;
            break;
        }
        if (e_i < 0 || e_i > 4 || e_j < 0 || e_j > 4)
            is_correct = false;
    }

    cout << "Puzzle #" << test << ":\n";

    if (is_correct)
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
                cout << puzzle[i][j] << (j < 4 ? " " : "");

            cout << "\n";
        }
    else
        cout << "This puzzle has no final configuration.\n";

    // cout << "\n";
}

void read_moves(string &moves)
{
    moves = "";
    char m;

    while (cin >> m && m != '0')
    {
        moves += m;
    }

    cin.ignore();
}