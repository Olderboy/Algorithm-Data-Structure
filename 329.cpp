/*
题目描述
​ 给定长度为N(N≤100000)的序列A(0≤Ai≤100000)，然后输入m(m≤10^5) 行操作指令

​ 第一类指令形如C l r d(1≤l≤r≤N)，表示把数列中第l...r之间的数都加d(0≤d≤100000)
​ 第二类指令形如Q x(x≤N)，表示询问序列中第x个数的值。

输入
​ 第一行一个整数N,代表序列A的长度

​ 第二行是由空格分隔开的N个数，分别代表A1，A2……An
​ 接下来一行是一个整数m，代表操作的次数。

​ 接下来m行，每行代表这一条指令如题目所述

输出
​ 对于每次Q查询，输出一行为查询的值。
*/
#include <iostream>
using namespace std;
#define MAX_N 100000

int c[MAX_N + 5];
#define lowbit(x) (x & (-x))

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int n, pre = 0, a, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a - pre, n);
        pre = a;
    }
    cin >> m;
    char s[10];
    int l, r, x;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (s[0]) {
            case 'C': {
                cin >> l >> r >> x;
                add(l, x, n);
                add(r + 1, -x, n);
            }break;
            case 'Q': {
                cin >> x;
                printf("%d\n", query(x));
            }break;
        }
    }
    return 0;
}
