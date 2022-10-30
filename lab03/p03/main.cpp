#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool dealDeck(vector<string> &, vector<string> &);
int playGame(vector<string> &, vector<string> &);

main()
{
    ios::sync_with_stdio(0);

    vector<string> hand1;
    vector<string> hand2;

    while (dealDeck(hand1, hand2))
    {
        int winner = playGame(hand1, hand2);

        cout << winner << setw(3) << (winner == 1 ? sz(hand1) : sz(hand2)) << "\n";
    }
}

bool dealDeck(vector<string> &hand1, vector<string> &hand2)
{
    string card;

    hand1.clear();
    hand2.clear();

    for (int i = 0; i < 52; i++)
    {

        cin >> card;

        if (card == "#")
            return false;

        if (i % 2 == 0)
            hand2.push_back(card);
        else
            hand1.push_back(card);
    }

    return true;
}

int playGame(vector<string> &hand1, vector<string> &hand2)
{
    static const string faces = "JQKA";

    vector<string> table_cards;
    string card;

    int winner = 1, turn = 2, pos, cover;
    bool covering = false;

    while ((!hand1.empty() && turn == 1) || (!hand2.empty() && turn == 2))
    {
        if (turn == 1)
        {
            card = hand1.back();
            hand1.pop_back();
        }
        else
        {
            card = hand2.back();
            hand2.pop_back();
        }

        table_cards.push_back(card);

        if (covering)
            cover--;

        if ((pos = faces.find(card[1])) != string::npos)
        {
            cover = pos + 1;
            winner = turn;
            turn = (turn == 1 ? 2 : 1);
            covering = true;
        }

        if (cover == 0 && covering)
        {
            covering = false;

            for (auto x : table_cards)
                if (turn == 2)
                    hand1.insert(hand1.begin(), x);
                else
                    hand2.insert(hand2.begin(), x);

            table_cards.clear();
        }

        if (cover == 0)
            turn = (turn == 1 ? 2 : 1);
    }

    return winner;
}
