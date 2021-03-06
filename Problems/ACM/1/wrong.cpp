#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mod 998244353
#define pi acos(-1)
#define inf 0x7fffffff
#define ll long long
using namespace std;
ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll n, blo;
ll v[100005], bl[100005], atag[100005];
set<ll> st[500];
void add(ll a, ll b, ll c)
{
    for (ll i = a; i <= min(bl[a] * blo, b); i++)
    {
        st[bl[a]].erase(v[i]);
        v[i] += c;
        st[bl[a]].insert(v[i]);
    }
    if (bl[a] != bl[b])
    {
        for (ll i = (bl[b] - 1) * blo + 1; i <= b; i++)
        {
            st[bl[b]].erase(v[i]);
            v[i] += c;
            st[bl[b]].insert(v[i]);
        }
    }
    for (ll i = bl[a] + 1; i <= bl[b] - 1; i++)
        atag[i] += c;
}
ll query(ll a, ll b, ll c)
{
    ll ans = -1;
    for (ll i = a; i <= min(bl[a] * blo, b); i++)
    {
        ll val = v[i] + atag[bl[a]];
        if (val < c)
            ans = max(val, ans);
    }
    if (bl[a] != bl[b])
        for (ll i = (bl[b] - 1) * blo + 1; i <= b; i++)
        {
            ll val = v[i] + atag[bl[b]];
            if (val < c)
                ans = max(val, ans);
        }
    for (ll i = bl[a] + 1; i <= bl[b] - 1; i++)
    {
        ll x = c - atag[i];
        set<ll>::iterator it = st[i].lower_bound(x);
        if (it == st[i].begin())
            continue;
        --it;
        ans = max(ans, *it + atag[i]);
    }
    return ans;
}
int main()
{
    freopen("lln.in", "r", stdin);
    freopen("lln.out", "w", stdout);
    ll tmp;
    n = read();
    blo = sqrt(n);
    for (ll i = 1; i <= n; i++)
        v[i] = read();
    for (ll i = 1; i <= n; i++)
    {
        bl[i] = (i - 1) / blo + 1;
        st[bl[i]].insert(v[i]);
    }
    for (ll i = 1; i <= n; i++)
    {
        ll f = read(), a = read(), b = read(), c = read();
        if (f == 0)
            add(a, b, c);
        if (f == 1)
        {
            tmp = query(a, b, c);
            if (tmp == -1)
                printf("-1\n");
            else
                printf("%lld\n", tmp);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}