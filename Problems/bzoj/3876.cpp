#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

int tot, Head[5010], Next[100010], From[100010], To[100010], Cost[100010], Val[100010];
int FLOW, Q[50100], pre[5010], n, m, S, T, dis[5010];
bool inq[5010];

void _addedge(int u, int v, int w, int c)
{
    tot++;
    Next[tot] = Head[u];
    Head[u] = tot;
    From[tot] = u;
    To[tot] = v;
    Cost[tot] = c;
    Val[tot] = w;
}

void addedge(int u, int v, int w, int c)
{
    _addedge(u, v, w, c);
    _addedge(v, u, 0, -c);
}

int calc()
{
    //printf("calc----\n");
    int res = 0, flow = 0x3f3f3f3f;
    for (int it = T; pre[it]; it = From[pre[it]])
    {
        flow = min(flow, Val[pre[it]]);
        //printf("%d->%d\n", From[pre[it]], To[pre[it]]);
    }
    FLOW += flow;
    for (int it = T; pre[it]; it = From[pre[it]])
    {
        Val[pre[it]] -= flow;
        Val[pre[it] ^ 1] += flow;
        res += flow * Cost[pre[it]];
    }
    return res;
}

bool spfa()
{
    int h = 0, t = 1;
    Q[1] = S;
    memset(pre, 0, sizeof pre);
    memset(inq, 0, sizeof inq);
    memset(dis, 0x3f3f3f3f, sizeof dis);
    inq[S] = true;
    dis[S] = 0;
    while (t != h)
    {
        h++;
        if (h == 3 * n)
            h = 1;
        int u = Q[h];
        inq[u] = false;
        for (int it = Head[u]; it; it = Next[it])
        {
            int v = To[it];
            if (Val[it] > 0 && dis[v] > dis[u] + Cost[it])
            {
                dis[v] = Cost[it] + dis[u];
                pre[v] = it;
                if (!inq[v])
                {
                    inq[v] = true;
                    t++;
                    if (t == 3 * n)
                        t = 1;
                    Q[t] = v;
                }
            }
        }
    }
    return pre[T] != 0;
}

int mcf()
{
    int res = 0;
    while (spfa())
        res += calc();
    return res;
}
int out[310];
int main()
{
    tot = 1;
    scanf("%d", &n);
    S = n + 1;
    T = n + 2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &out[i]);
        for (int j = 1; j <= out[i]; j++)
        {
            int v, f;
            scanf("%d%d", &v, &f);
            addedge(S, v, 1, f);
            addedge(i, v, 0x3f3f3f3f, f);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        addedge(i, T, out[i], 0);
        if (i != 1)
            addedge(i, 1, 0x3f3f3f3f, 0);
    }
    int ans2 = mcf();
    printf("%d\n", ans2);

    system("pause");
    return 0;
}