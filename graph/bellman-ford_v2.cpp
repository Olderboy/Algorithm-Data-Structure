#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int s, e, v, next;
};

//vector<vector<edge>> vec;
int n, m, s, edg_cnt, ans[100005], head[100005], mark[100005];
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
    queue<int> state;
    state.push(s);
    while (!state.empty()) {
        int temp = state.front();
        state.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    state.push(e);
                    mark[e] = 1;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     int f = 0;
    //     for (int j = 0; j < edg_cnt; j++) {
    //         // ans[edg[j].e] = min(ans[edg[j].e], ans[edg[j].s] + edg[j].v);
    //         if (ans[edg[j].e] > ans[edg[j].s] + edg[j].v) {
    //             ans[edg[j].e] = min(ans[edg[j].e], ans[edg[j].s] + edg[j].v);
    //             f = 1;
    //         }
    //     }
    //     if (f == 0) {
    //         break;
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            printf("-1\n");
        } else {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}