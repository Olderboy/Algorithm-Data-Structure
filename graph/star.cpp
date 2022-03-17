#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000000

struct edge {
    int e, v , next;
};

edge edg[MAX_N + 5];
int n, m, head[MAX_N + 5];

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        edg[i].e = e;
        edg[i].v = v;
        edg[i].next = head[s];
        head[s] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = head[i]; j != -1; j = edg[j].next) {
            cout << "{" << edg[j].e << "," << edg[j].v << "} , ";
        }
        cout << "\n";
    }
    return 0;
}
