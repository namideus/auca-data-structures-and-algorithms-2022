#include <bits/stdc++.h>

typedef long long int lli;

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

lli sumOfDigits(lli n)
{
    int num = 0;

    while (n > 0)
    {
        num += n % 10;
        n /= 10;
    }

    return num;
}

int main()
{
    iostream::sync_with_stdio(false);

    long long int n, ans;

    while (cin >> n && n)
    {
        ans = sumOfDigits(n);

        while (ans / 10 > 0)
            ans = sumOfDigits(ans);

        cout << ans << "\n";
    }
}
