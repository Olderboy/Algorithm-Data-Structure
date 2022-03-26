#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {             \
        __typeof(a) __temp = a;  \
        a = b; b = __temp;       \
}

typedef struct priority_queue {
    int *data;
    int cnt, size;
}priority_queue; //大顶堆

priority_queue *init(int n) {
    priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
    pq->data = (int *)malloc(sizeof(int) * (n + 1));
    pq->cnt = 0;
    pq->size = n;
    return pq;
}

void clear(priority_queue *pq) {
    if (pq == NULL) return ;
    free(pq->data);
    free(pq);
    return ;
}

int top(priority_queue *pq) {
    return pq->data[1];
}

int push(priority_queue *pq, int val) {
    if (pq == NULL) return 0;
    if (pq->cnt == pq->size) return 0;
    pq->data[++pq->cnt] = val;
    int ind = pq->cnt;
    while (ind >> 1 && pq->data[ind] > pq->data[ind >> 1]) {
        swap(pq->data[ind], pq->data[ind >> 1]);
        ind >>= 1;
    }
}

int pop(priority_queue *pq) {
    if (pq == NULL) return 0;
    if (empty(pq)) return 0;
    pq->data[1] = pq->data[pq->cnt--];
    int ind = 1;
    while ((ind << 1) < pq->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (pq->data[l] > pq->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
    }
    return 1;
}

int empty(priority_queue *pq) {
    if (pq == NULL) exit(1);
    return pq->cnt == 0;
}

int main() {

    return 0;
}