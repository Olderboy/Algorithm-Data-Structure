#include <stdio.h>

#define MAX_N 10000000

int primer[MAX_N + 5];
int a, b;


//1s
namespace p1{
    void init() {
        for (int i = 2; i < MAX_N; i++) {
            if (primer[i] != 1) primer[++primer[0]] = i;
            for (int j = 1; j <= primer[0]; j++) {
                if (primer[j] * i > MAX_N) break;
                primer[primer[j] * i] = 1;
                if (i % primer[j] == 0) break;
            }
        }
    }

    void print(int a, int b) {
        for (int i = 1; i <= primer[0]; i++) {
            if (primer[i] >= a) {
                if (primer[i] > b) return;
                printf("%d\n", primer[i]);
            }
        }
    }
}

//2s
namespace p2 {
    void init() {
        for (int i = 2; i < MAX_N; i++) {
            if (primer[i] == 1) continue;
            for (int j = i; j <= MAX_N / i; j++) {
                primer[i * j] = 1;
            }
        }
    }    

    void print(int a, int b) {
        for (int i = a; i <= b; i++) {
            if (primer[i] == 0) printf("%d\n", i);
        }
    }
} // namespace p2 

int main() {
    p2::init();
    scanf("%d%d", &a, &b);
    p2::print(a, b);
    return 0;
}