#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void computeDigits(int n, int& sum, int& count) 
{
    while (n > 0)
    {
        sum += n % 10;
        count++;
        n /= 10;
    }
}

int sumOfDigits(int n)
{
    int sum = 0;
    int newSum = 0;
    int count = 0;

    computeDigits(n, sum, count);

    newSum = sum;

    while (newSum / 10 > 0)
    {
        newSum = 0;
        computeDigits(sum, newSum, count);
        sum = newSum;
    }

    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);

    int n, ans;

    while (cin >> n && n)
        cout << sumOfDigits(n) << "\n";
}
