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

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 100000;

struct edge {
    int e, v, next;
};

struct state{
    int p, vsum;
    bool operator< (const state& s) const {
        return vsum > s.vsum;
    }
};

class StateCompare{
public:
    StateCompare() = default;
    bool operator()(const state& s1, const state& s2) {
        return s1.vsum < s2.vsum;
    }
};

edge edg[2 * MAX_N + 5];
int n, m, s, cnt, head[2 * MAX_N + 5], ans[2 * MAX_N + 5];

void dummpEdge(int a, int b, int c) {
    edg[cnt].e = b;
    edg[cnt].v = c;
    edg[cnt].next = head[a];
    head[a] = cnt;
    cnt++;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    memset(head, -1, MAX_N + 5);
    memset(ans, 0x3f, MAX_N + 5);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        dummpEdge(a, b, c);
        dummpEdge(b, a, c);
    }

    priority_queue<state> que;
    que.push(state{s, 0});
    ans[s] = 0;
    while (!que.empty()) {
        state temp = que.top();
        que.pop();
        if (ans[temp.p] != temp.vsum) continue;
        for (int i = head[temp.p]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > temp.vsum + v) {
                ans[e] = temp.vsum + v;
                que.push((state){e, ans[e]});
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