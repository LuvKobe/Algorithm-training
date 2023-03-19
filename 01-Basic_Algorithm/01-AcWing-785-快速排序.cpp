//题目链接：https://www.acwing.com/problem/content/787/

#include <iostream>
using namespace std;

const int N = 1e6+10;

int n;
int q[N];

void quickSort(int q[], int l, int r)
{
    //如果数组中就一个数,就已经排好了,直接返回
    if (l >= r) 
        return;
    
    //选取分界线,选择数组最中间的那个数
    /*
    1.第一趟: i找比x大的数,j找比x小的数,
              找到以后，就交换两个数的位置:swap(i, j)
      当i和j相遇或者错过以后,就把整个区间一分为二了,
      那么这时候,左区间的数是小于等于x的,右区间的数是小于等于x的
    */
    int x = q[l + r >> 1];
    int i = l - 1; 
    int j = r + 1; 
    
    //划分成左右两个区间
    //左区间是小于等于x的数
    //右区间是大于等于x的数
    while (i < j)
    {
        //i在循环中如果找到比x大的数就停下来
        while (q[++ i] < x);

        //j在循环中如果找到比x小的数就停下来
        while (q[-- j] > x);

        //这里为什么要判断i<j呢？
        //因为i始终在左边，j始终在右边，如何i<j，才进行交换
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    
    //然后对左区间进行排序
    //注意,因为第一趟相遇以后,j就变成了左区间的最右边界
    quickSort(q, l, j);
    
    //第一趟相遇以后,j+1就变成了右区间的最左边界
    quickSort(q, j+1, r);
}

int main()
{
    //
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //
    
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) 
        cin >> q[i];
    
    quickSort(q, 0, n-1);
    
    for (int i = 0; i < n; i ++ ) 
        cout << q[i] << " ";
    
    return 0;
}