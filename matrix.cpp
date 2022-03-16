#include <stdio.h>

#define MAX_N 10000

int matrix[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void print(int m) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
} 

int main() {
    int n = 0;
    scanf("%d", &n);
    int count = 1, x = 1, y = 1, d = 0;
    while (1) {
        int next_x = x + dir[d][0];
        int next_y = y + dir[d][1];
        matrix[x][y] = count;
        count++;
        if (count > n * n) break;
        //下个位置能存且能走
        if (matrix[next_x][next_y] == 0 && next_x >= 1 && next_y >= 1 && next_x <= n && next_y <= n) {
            x += dir[d][0];
            y += dir[d][1];
            // printf("x = %d, y = %d\n", x, y);
        } else {   //改变方向
            d = (d + 1) % 4;
            count--;
        }

    }

    print(n);
    return 0;
}