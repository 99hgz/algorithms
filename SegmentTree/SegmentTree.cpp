/*
 * @key word:线段树
 * @已测试:HDU - 1754
 * @Author: hgz 
 * @Date: 2017-04-24 19:09:25 
 * @Last Modified by:   hgz 
 * @Last Modified time: 2017-04-24 19:09:25 
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200009;

struct line
{
    int l;
    int r;
    int cmin;
} Tree[MAXN * 4];

void pushUp(int t)
{
    int x = t << 1;
    Tree[t].cmin = min(Tree[x + 1].cmin, Tree[x + 2].cmin);
}

void buildTree(int l, int r, int t)
{
    Tree[t].l = l;
    Tree[t].r = r;
    Tree[t].cmin = INT_MAX;
    if (l == r)
    {
        scanf("%d", &Tree[t].cmin);
        return;
    }
    int x = (l + r) >> 1;
    buildTree(l, x, t << 1 | 1);
    buildTree(x + 1, r, (t << 1) + 2);
    pushUp(t);
}

void updateTree(int v, int cn, int t)
{
    if (Tree[t].l == v && Tree[t].r == v)
    {
        Tree[t].cmin = cn;
        return;
    }
    int m = (Tree[t].l + Tree[t].r) >> 1;
    if (v <= m)
    {
        updateTree(v, cn, t << 1 | 1);
    }
    else
    {
        updateTree(v, cn, (t << 1) + 2);
    }
    pushUp(t);
}

int queryTree(int l, int r, int t)
{
    if (Tree[t].l == l && Tree[t].r == r)
    {
        return Tree[t].cmin;
    }
    int m = (Tree[t].l + Tree[t].r) >> 1;
    if (l > m)
    {
        return queryTree(l, r, (t << 1) + 2);
    }
    else if (r <= m)
    {
        return queryTree(l, r, t << 1 | 1);
    }
    else
    {
        int ret1 = queryTree(l, m, t << 1 | 1);
        int ret2 = queryTree(m + 1, r, (t << 1) + 2);
        return min(ret1, ret2);
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        buildTree(1, n, 0);
        while (m--)
        {
            char op[2];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'Q')
            {
                printf("%d\n", queryTree(a, b, 0));
            }
            else
            {
                updateTree(a, b, 0);
            }
        }
    }
    return 0;
}