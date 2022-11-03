#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Game
{
private:
    string cnf;
    char b[8][8];
    void populate_board()
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                b[i][j] = ' ';
        string row;
        stringstream ss(cnf);
        int row_id = 0, i;
        while (getline(ss, row, '/'))
        {
            i = 0;
            for (auto c : row)
                if (isdigit(c))
                    i += c - '0';
                else if (isalpha(c) && islower(c))
                    b[row_id][i] = c, i++;
                else
                    b[row_id][i] = c, i++;
            row_id++;
        }
    }
    void king(int i, int j)
    {
        int x[8] = {1, -1, -1, 1, 0, 1, 0, -1};
        int y[8] = {1, -1, 1, -1, 1, 0, -1, 0};
        for (int k = 0; k < 8; k++)
        {
            int xi = i + x[k], yj = j + y[k];
            if (xi >= 0 && xi < 8 && yj >= 0 && yj < 8)
                if (b[xi][yj] == ' ')
                    b[xi][yj] = 'M';
                else
                    continue;
        }
    }
    void bishop(int i, int j)
    {
        int xi = i + 1, yj = j + 1;
        while (xi < 8 && yj < 8)
        {
            if (b[xi][yj] == ' ' || b[xi][yj] == 'M')
                b[xi][yj] = 'M';
            else
                break;
            xi++, yj++;
        }
        xi = i - 1, yj = j + 1;
        while (xi >= 0 && yj < 8)
        {
            if (b[xi][yj] == ' ' || b[xi][yj] == 'M')
                b[xi][yj] = 'M';
            else
                break;
            xi--, yj++;
        }
        xi = i + 1, yj = j - 1;
        while (xi < 8 && yj >= 0)
        {
            if (b[xi][yj] == ' ' || b[xi][yj] == 'M')
                b[xi][yj] = 'M';
            else
                break;
            xi++, yj--;
        }
        xi = i - 1, yj = j - 1;
        while (xi >= 0 && yj >= 0)
        {
            if (b[xi][yj] == ' ' || b[xi][yj] == 'M')
                b[xi][yj] = 'M';
            else
                break;
            xi--, yj--;
        }
    }
    void rook(int i, int j)
    {
        int xi = i + 1, xj;
        while (xi < 8)
        {
            if (b[xi][j] == ' ' || b[xi][j] == 'M')
                b[xi][j] = 'M';
            else
                break;
            xi++;
        }
        xi = i - 1;
        while (xi >= 0)
        {
            if (b[xi][j] == ' ' || b[xi][j] == 'M')
                b[xi][j] = 'M';
            else
                break;
            xi--;
        }
        xj = j + 1;
        while (xj < 8)
        {
            if (b[i][xj] == ' ' || b[i][xj] == 'M')
                b[i][xj] = 'M';
            else
                break;
            xj++;
        }
        xj = j - 1;
        while (xj >= 0)
        {
            if (b[i][xj] == ' ' || b[i][xj] == 'M')
                b[i][xj] = 'M';
            else
                break;
            xj--;
        }
    }
    void pawn(int i, int j, bool up)
    {
        int xi, yj;
        if (!up)
        {
            xi = i + 1, yj = j - 1;
            if (xi < 8 && yj >= 0 && (b[xi][yj] == ' ' || b[xi][yj] == 'M'))
                b[xi][yj] = 'M';
            yj = j + 1;
            if (xi < 8 && yj < 8 && (b[xi][yj] == ' ' || b[xi][yj] == 'M'))
                b[xi][yj] = 'M';
        }
        else
        {
            xi = i - 1, yj = j - 1;
            if (xi >= 0 && yj >= 0 && (b[xi][yj] == ' ' || b[xi][yj] == 'M'))
                b[xi][yj] = 'M';
            yj = j + 1;
            if (xi >= 0 && yj < 8 && (b[xi][yj] == ' ' || b[xi][yj] == 'M'))
                b[xi][yj] = 'M';
        }
    }
    void knight(int i, int j, bool up)
    {
        int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; k++)
        {
            int xi = i + x[k], yj = j + y[k];
            if (xi >= 0 && yj >= 0 && xi < 8 && yj < 8)
                if (b[xi][yj] == ' ' || b[xi][yj] == 'M')
                    b[xi][yj] = 'M';
                else
                    continue;
        }
    }
    void queen(int i, int j)
    {
        rook(i, j);
        bishop(i, j);
        king(i, j);
    }

public:
    Game(string s);
    int solve()
    {
        int res = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
            {
                char c = b[i][j];
                switch (tolower(c))
                {
                case 'k':
                    king(i, j);
                    break;
                case 'b':
                    bishop(i, j);
                    break;
                case 'r':
                    rook(i, j);
                    break;
                case 'p':
                    pawn(i, j, isupper(c));
                    break;
                case 'n':
                    knight(i, j, isupper(c));
                    break;
                case 'q':
                    queen(i, j);
                    break;
                }
            }
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (b[i][j] == ' ')
                    res++;
        return res;
    }
};
Game::Game(string s)
{
    cnf = s;
    populate_board();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (string cnf; getline(cin, cnf);)
    {
        Game game(cnf);
        cout << game.solve() << "\n";
    }
}