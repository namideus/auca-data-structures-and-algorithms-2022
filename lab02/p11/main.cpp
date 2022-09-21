#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int sumOfDigits(int n)
{
    int num = 0;

    while (n > 0)
    {
        num += n % 10;
        n /= 10;
    }

    return num;
}

int sumOfLetters(const string &str)
{
    int sum = 0;
    char c;

    for (int i = 0; i < sz(str); ++i)
    {
        c = str[i];

        if (isalpha(c))
            sum += ((int)tolower(c) - 96);
    }

    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);

    int a, b;

    string name1, name2;

    while (getline(cin, name1))
    {
        getline(cin, name2);

        a = sumOfDigits(sumOfLetters(name1));
        b = sumOfDigits(sumOfLetters(name2));

        while (sz(to_string(a)) > 1)
            a = sumOfDigits(a);

        while (sz(to_string(b)) > 1)
            b = sumOfDigits(b);

        cout << fixed << setprecision(2);

        if (b > a)
            swap(b, a);

        cout << ((double)b / a) * 100.0 << " %\n";
    }
}