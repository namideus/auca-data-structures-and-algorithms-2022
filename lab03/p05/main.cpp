#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Computer
{
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

    // private methods
public:
    Computer() : registers(10, 0),
                 memory(1000, 0),
                 instructionPointer(0)
    {
    }

    // other public methods
    void store(int c)
    {
        memory[instructionPointer++] = c;
    }

    const int count_instructions()
    {
        int cnt = 1, ram_id = 0, c, d, n, w;

        while (ram_id < 1000 && memory[ram_id] != 100)
        {
            cnt++;

            w = memory[ram_id];
            c = w / 100;
            d = w % 100 / 10;
            n = w % 10;

            switch (c)
            {
            case 2:
                registers[d] = n;
                break;
            case 3:
                registers[d] = (n + registers[d]) % 1000;
                break;
            case 4:
                registers[d] = (n * registers[d]) % 1000;
                break;
            case 5:
                registers[d] = registers[n];
                break;
            case 6:
                registers[d] = (registers[d] + registers[n]) % 1000;
                break;
            case 7:
                registers[d] = (registers[d] * registers[n]) % 1000;
                break;
            case 8:
                registers[d] = memory[registers[n]];
                break;
            case 9:
                memory[registers[n]] = registers[d];
                break;
            case 0:
                if (registers[n] != 0)
                {
                    ram_id = registers[d] - 1;
                }
                break;
            default:
                break;
            }

            ++ram_id;
        }

        return cnt;
    }

    void print()
    {
        for (int i = 0; i < instructionPointer; i++)
            cout << memory[i] << " ";

        cout << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;

    cin >> test;

    cin.ignore(1024, '\n');
    cin.ignore(1024, '\n');

    for (int t = 1; t <= test; t++)
    {
        Computer comp;

        if (t > 1)
            cout << "\n";

        for (string ram; getline(cin, ram, '\n') && isdigit(ram[0]);)
            comp.store(stoi(ram));

        cout << comp.count_instructions() << "\n";
    }
}