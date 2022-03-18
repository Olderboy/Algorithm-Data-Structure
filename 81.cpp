/*小明看完了电影，是时候回家了，可是这时他突然得知小米之家的小米9现货开卖了，
这款手机小明已经想了一个多月，知道这个消息后的他十分兴奋，一定要在回家之前先
去小米之家买手机（城市中有一个或多个小米之家），请计算小明从电影院到任意一个
小米之家买手机后回家的最短距离（只能朝上下左右四个方向行走，除了障碍物外，其
他地方都可以通过），数据保证可以买完手机后回家。
输入：
第 1 行两个数 n 和 m 表示地图有 n 行 m 列 2≤n,m≤2000​ 第 2 行至第 n+1 行为
地图 其中 S 表示电影院 T 表示家 P 表示小米之家​ . 为可以通过的点 # 为障碍物
输出：
​ 一个整数 表示小明从电影院去小米之家再回家的总距离
*/

#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 2000

typedef struct node{
    int x, y, step ,f;   //f标志是否拿到手机
}node; 

int n, m, sx, sy;
char mmap[MAX_N + 5][MAX_N + 5];
//check == 0 没走过  1(01)  没手机走过  2(10)  有手机走过  3(11) 有手机没手机都走过
char check[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    que.push(node{sx, sy, 0, 0});
    check[sx][sy] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int tx = temp.x + dir[i][0];
            int ty = temp.y + dir[i][1];
            //走到T且有手机，回家
            if (temp.f == 1 && mmap[tx][ty] == 'T') {
                cout << temp.step + 1;
                return 0;
            }
            //去重
            if(((check[tx][ty] & 1) && temp.f == 0 )|| ((check[tx][ty] & 2) && temp.f == 1)) continue;
            //走到P且没有手机
            if(mmap[tx][ty] == 'P') {
                check[tx][ty] = 3;
                que.push(node{tx, ty, temp.step + 1, 1});
            }
            //所有能走的情况
            if(mmap[tx][ty] == '.' || mmap[tx][ty] == 'S' || mmap[tx][ty] == 'T') {
                check[tx][ty] += temp.f + 1;
                que.push(node{tx, ty, temp.step + 1, temp.f});
            } 
        }
    }


    return 0;
}