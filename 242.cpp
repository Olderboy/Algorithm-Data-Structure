/*
给定一个有 N 个元素的非负序列，求长度大于等于 M 的连续子序列的最大平均值。
输入
​ 第一行输入两个数 N,M。（1≤N,M≤100000）
​ 接下来 N 行，每行输入一个数表示非负序列。

输出
​ 输出一个整数表示最大平均值乘 1000 的结果。
*/
#include <iostream>
using namespace std;

const int MAX_N = 100000; 
long long num[MAX_N + 5];
long long n;

long long check(long long x, long long m) {
    num[0] = x;
    long long pre = 0, si = 0, sj = 0;
    for (int i = 1; i <= n; i++) {
        si += (num[i] - x);
        if (i < m) continue;
        sj += (num[i - m] - x);
        pre = min(pre, sj);
        if (si - pre >= 0) return 1;
    }
    return 0;
}

int ds(long long l, long long r, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) / 2;
    long long f = check(mid, m);
    if (f) l = mid; 
    else r = mid - 1;
    return ds(l, r, m);
}

int main() {
    long long l, r, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] *= 1000;
        if (i == 1) l = r = num[i];
        l = min(num[i], l);
        r = max(num[i], r);
    }
    cout << ds(l, r, m);
    return 0;
}