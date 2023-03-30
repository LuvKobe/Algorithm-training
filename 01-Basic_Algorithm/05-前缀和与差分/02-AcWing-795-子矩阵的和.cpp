/*
题目链接：https://www.acwing.com/problem/content/description/798/

1.题目描述
给你二维数组中两个坐标 （x1 , y1）和 （x2 , y2）
以它们作为一个子矩阵的左上角坐标和右下角坐标，求所围成的矩阵中所有元素之和。


2.算法思路

注意：我们下面都是从[1,1]点开始的，而数组的下标是从[0,0]开始的

1) S[i, j]的前缀和：s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    也就是从[1,1]点开始到[i, j]直接的所有和


2) 任意两点(x1,y1)和(x2,y2)围成的一子矩阵中的所有数之和为：
{(x1,y1) (x2,y2)}围成的子矩阵中所有的和：s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]

*/


#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3+10;

int n, m; // n行m列
int q; // 询问次数

int a[N][N]; // 原数组
int s[N][N]; // 前缀和

int main()
{
    //关流
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    //
    
    //scanf("%d%d%d", &n, &m, &q);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++ )
        for (int j = 1; j <= m; j++ )
            cin >> a[i][j];
            //scanf("%d", &a[i][j]);
    
    // 初始化前缀和数组，也就是计算a数组当中每个数的前缀和
    for (int i = 1; i <= n; i++ )
        for (int j = 1; j <= m; j++ )
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    
    // 询问次数
    while (q --)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        //scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        //printf("%d\n", s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
        cout << s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] << "\n";
    }
    return 0;
}