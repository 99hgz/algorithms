#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
ll MOD = 1000003;
ll fac[1000013], inv[1000013];
ll n, l, r;
void init(ll MOD)
{
    fac[0] = 1;
    for (ll i = 1; i <= MOD; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[1] = inv[0] = 1;
    for (ll i = 2; i < MOD; i++)
    {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (ll i = 1; i < MOD; i++)
    {
        inv[i] = inv[i] * inv[i - 1] % MOD; //阶乘求逆
    }
}

ll lucas(ll n, ll m)
{
    if (m > n)
        return 0;
    if (n < MOD && m < MOD)
        return fac[n] * inv[n - m] % MOD * inv[m] % MOD;
    return lucas(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}

int main()
{
    ll t;
    scanf("%lld", &t);
    init(MOD);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &l, &r);
        ll m = r - l + 1;
        printf("%lld\n", (lucas(n + m, m) + MOD - 1) % MOD);
    }
    system("pause");
    return 0;
}