#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(int i, int j)
{
    int res = 0;

    if(i>j)
        swap(i,j);
    
    for(int l = i; l <= j; ++l)
    {
        int len = 1;
        int n = l;
        while(n != 1)
        {
            len++;
            if(n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
        }
        res = max(res, len);
    }
    return res;
}

int main()
{
    iostream::sync_with_stdio(false);

    int a, b;

    while(cin >> a >> b)
    {
        cout << a << " " << b << " " << solve(a, b) << "\n";
    }
}