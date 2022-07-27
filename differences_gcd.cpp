#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// shortening code
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define PI 3.1415926535897932384626
#define LI(i, a, b) for (int i = a; i <= b; i++)  // forloop inclusive
#define LE(i, a, b) for (int i = a; i < b; i++)   // forloop exclusive
#define LBI(i, a, b) for (int i = a; i >= b; i--) // forloop backward inclusive
#define LBE(i, a, b) for (int i = a; i > b; i--)  // forloop backward inclusive

#define LOOPVECTOR(i, v) for (auto i = v.begin(); i != v.end(); ++i)
#define LOOPVECTORBACK(i, v) for (auto i = v.rbegin(); i != v.rend(); ++i)

#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++) // traverse an STL data structure

#define in(a, b) ((b).find(a) != (b).end())
#define bit(x, i) (x & (1 << i))          // select the bit of position i of x
#define lowbit(x) ((x) & ((x) ^ ((x)-1))) // get the lowest bit of x
#define hBit(msb, n) asm("bsrl %1,%0" \
                         : "=r"(msb)  \
                         : "r"(n)) // get the highest bit of x, maybe the fastest
#define Max(a, b) ((a) < (b) ? (b) : (a))
#define Min(a, b) ((a) < (b) ? (a) : (b))

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    if (r - l + 1 < n)
    {
        cout << "NO\n";
        return;
    }
    else if (n == 1)
    {
        cout << "YES\n";
        cout << l << "\n";
        return;
    }

    vi arr(n);
    iota(arr.begin(), arr.end(), 1);
    vi res;
    int x = r;
    int c = 0;

    LOOPVECTORBACK(i, arr)
    {
        c = x - x % *i;
        while (find(res.begin(), res.end(), c) != res.end())
        {
            x--;
            c = x - x % *i;
            if (c < l)
            {
                cout << "NO\n";
                return;
            }
        }
        res.insert(res.begin(), c);
    }

    cout << "YES\n";
    LOOPVECTOR(i, res)
    {
        cout << *i << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    int count = 1;
    int i = 1;
    while (count != 2000)
    {
        i++;
        for (int j = i; j < 45; ++j)
        {
            if (count == 1081)
            {
                cout << "1 " << i << " " << j << "\n";
            }
            count++;
        }
    }

    LE(i, 0, t)
    {
        solve();
    }

    return 0;
}