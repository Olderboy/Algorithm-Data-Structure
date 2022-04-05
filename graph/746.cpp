/*
题目描述
​ 给定一个有 n 个点 m 条边的无向图及一个起点 s，现求从起点出发，到达其他点的最短路权值。题目保证边的权值为正数。

输入格式
​ 输入第一行三个整数 n,m,s，表示点的数量与边的数量及起点编号。（1≤n,m≤100000）
​ 接下来 m 行，每行 3 个正整数 a,b,c，表示 a 点与 b 点之间有一条权值为 c 的边。（1≤a,b,c≤100000）
​ 注意，可能有重边。

输出格式
​ 输出共 n 行，每行一个数字 ai，表示从起点到 i 点的最短路权值，若某点不可达输出 −1，答案保证在 int 范围内。
*/

//djsk算法
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 100000;

struct edge {
    int e, v, next;
};

struct state{
    int p, vsum;
    bool operator< (const state& s1) const {
        return vsum > s1.vsum;
    }
};

// class StateCompare{
// public:
//     StateCompare() = default;
//     bool operator()(const state& s1, const state& s2) {
//         return s1.vsum < s2.vsum;
//     }
// };

edge edg[2 * MAX_N + 5];
int n, m, s, cnt = 1, head[MAX_N], ans[MAX_N];
priority_queue<state> que;

void dummpEdge(int a, int b, int c) {
    edg[cnt].e = b;
    edg[cnt].v = c;
    edg[cnt].next = head[a];
    head[a] = cnt;
    cnt++;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    memset(head, -1, MAX_N);
    memset(ans, 0x3f, MAX_N);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        dummpEdge(a, b, c);
        dummpEdge(b, a, c);
    }
    que.push(state{s, 0});
    ans[s] = 0;
    while (!que.empty()) {
        state temp = que.top();
        que.pop();
        if (temp.vsum != ans[temp.p]) {
            continue;
        }
        for (int i = head[temp.p]; i != -1; i = edg[i].next) {
            if (ans[edg[i].e] > temp.vsum + edg[i].v) {
                ans[edg[i].e] = temp.vsum + edg[i].v;
                que.push((state){edg[i].e, temp.vsum + edg[i].v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0x3f3f3f3f) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}