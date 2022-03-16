/*
n行m列走地图，求出最少步数或者不可达输出No
4 5
s####
....#
#####
#...g
*/

#include <stdio.h>
#include <queue>
#include <iostream>

#define max_n 500

typedef struct state {
    int x, y;
    int step;
}state;

int n, m;
char sx, sy;
char map[max_n + 5][max_n + 5], check[max_n + 5][max_n + 5];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


int main() {
    // scanf("%d%d", &n, &m);
    // // printf("%d%d", n, m);
    // getchar();
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // printf("(i ,j) : %d ,%d\n", i, j);
            // scanf("%c", &map[i][j]);
            std::cin >> map[i][j];
            if (map[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }
    std::queue<state> que;
    que.push((state){sx, sy, 0});
    while (!que.empty()) {
        state temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int tx = temp.x + dir[i][0];
            int ty = temp.y + dir[i][1];
            if (map[tx][ty] == '.' && check[tx][ty] != 1) {
                check[tx][ty] = 1;
                que.push((state){tx, ty, temp.step + 1});
                continue;
            } 
            if (map[tx][ty] == 'g') {
                printf("%d", temp.step + 1);
                return 0;
            }
        }
    }
    printf("no");
    return 0;
}