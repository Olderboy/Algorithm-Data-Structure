#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 10^100

char num1[MAX_N + 5], num2[MAX_N + 5];
int n1[MAX_N + 5], n2[MAX_N + 5], sum[MAX_N + 5];

int main() {
    scanf("%s", num1);
    scanf("%s", num2);
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    for (int i = 1, j = n1[0] - 1; j >= 0; i++, j--) {
        n1[i] = num1[j] - '0';
    }
    for (int i = 1, j = n2[0] - 1; j >= 0; i++, j--) {
        n2[i] = num2[j] - '0';
    }

    int len = max(n1[0], n2[0]);
    for (int i = 1; i <= len; i++) {
        n1[i] += n2[i];
    }

    for (int i = 1; i <= len; i++) {
        if (n1[i] > 9) {
            n1[i] = n1[i] % 10;
            n1[i + 1] += 1;
            if (i == len) {
                n1[0]++;
            }
        }
    }

    for (int i = n1[0]; i > 0; i--) {
        printf("%d", n1[i]);
    }
    return 0;
}