#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<vector<int>> readShuffles();
vector<int> createDeck();
void applyShuffleDeck(vector<int> &deck, const vector<int> &shuffle);
void printDeck(const vector<int> &deck);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            applyShuffleDeck(deck, shuffles[m - 1]);
        }

        if (test != 0)
        {
            cout << "\n";
        }

        printDeck(deck);
    }
}