#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

class Point{
public:
    Point(int x, int y):_x(x), _y(y){}
    bool operator< (const Point& p) const {
        if (_x == p._x) {
            return _y < p._y;
        }
        return _x < p._x;
    }
    virtual ~Point(){}
private:
    int _x, _y;
};

priority_queue<int, vector<int>, greater<int>> pq;
pq.push(10);
#define swap(a, b) {\
        __typeof(a) __temp = a;\
        a = b; b = __temp;\
}

struct priority_queue {
    int *data;
    int capcity, cnt;
};

priority_queue* init(int n) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->data = (int *)malloc(n * sizeof(int));
    p->capcity = n;
    p->cnt = 0;
    return p;
}

int empty(priority_queue* p) {
    if (p == NULL) return 0;
    return p->cnt == 0;
}

int top(priority_queue *p) {
    if (empty(p)) return -1;
    return p->data[1];
}


namespace l {
struct less{
    bool operator()(int a, int b) {
        return a < b;
    }
};
}
l::less __comp;
void push(priority_queue *p, int val) {
    if (p == NULL) return;
    if (p->cnt == p->capcity) return;
    int ind = ++p->cnt, parent = ind >> 1;
    while (parent > 0 && __comp(p->data[parent], val)) {
        p->data[ind] = p->data[parent];
        ind = ind >> 1;
        parent = ind >> 1;
    }
    p->data[ind] = val;
}

void pop(priority_queue *p) {
    if (p == NULL) return;
    if (p->cnt == 0) return;
    p->data[1] = p->data[p->cnt];
    p->cnt--;
    int ind = 1;
    while ((ind << 1) <= p->cnt) {
        int temp = ind, l = ind << 1, r = (ind << 1) + 1;
        if (p->data[temp] < p->data[l]) temp = l;
        if (r <= p->cnt && p->data[temp] < p->data[r]) temp = r;
        if (temp == ind) break;
        swap(p->data[temp], p->data[ind]);
        ind = temp;
    }
}


int main() {
    priority_queue *p = init(10);
    for (int i = 1; i <= 5; i++) {
        int a;
        cin >> a;
        push(p, a);
    }
    for (int i = 1; i <= 5; i++) {
        cout << top(p) << endl;
        pop(p);
    }

    return 0;
}
