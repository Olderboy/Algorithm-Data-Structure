#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct edge {
    int s, e, v, next;
};

int n, m, s, edg_cnt, ans[100005], head[100005];
edge edg[200005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].s = a;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt;
    edg_cnt++;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    ans[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < edg_cnt; j++) {
            ans[edg[j].e] = min(ans[edg[j].e], ans[edg[j].s] + edg[j].v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            printf("-1\n");
        } else {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}