/*
题目链接
思路：https://www.acwing.com/problem/content/789/
1.确定分界点：mid=(l+r)>>1
2.递归排序左区间和右区间
3.归并：合二为一
*/

#include <iostream>
using namespace std;

const int N = 1e5+10;

int n;
int q[N];

int tmp[N]; //归并排序的辅助数组

void mergeSort(int q[], int l, int r)
{
    //当区间里面的元素个数只有1个或者没有的话，直接return
    if (l >= r) 
        return;
    
    //1.确定分界点（这里是数组中间位置的下标）
    int mid = (l + r) >> 1; 
    
    //2.递归排序左区间和右区间
    mergeSort(q, l, mid);
    mergeSort(q, mid+1, r);
    
    //3.归并（将排序好的左右区间按照从小到大合二为一）
    int k = 0; //表示当前tmp数组内元素个数（就是两个区间合并的时候，合并了几个数了）
    int i = l; //i指向左区间的起点
    int j = mid+1; //j指向右区间的起点
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) //如果左区间i下标指向的数小于右区间j下标指向的数
            tmp[k ++] = q[i ++]; //那么就把左区间i下标指向的数放进tmp数组中
        else //如果左区间i下标指向的数大于右区间j下标指向的数
            tmp[k ++] = q[j ++]; //那么就把右区间j下标指向的数放进tmp数组中
    }
    
    //4.当一个区间遍历完以后，还要把剩下的区间里面的数全部放进tmp数组中
    while (i <= mid) //如果左区间没有遍历完
        tmp[k ++] = q[i ++]; //那么就把左区间剩下的数放进tmp数组中
    while (j <= r) //如果右区间没有遍历完
        tmp[k ++] = q[j ++]; //那么就把右区间剩下的数放进tmp数组中
    
    //5.把tmp数组的数拷贝回原数组中
    //因为此时tmp数组中的元素已经是排序好的，所以还需要拷贝回原来的q数组中
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    //关流
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //    
    
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    
    mergeSort(q, 0, n-1);
    
    for (int i = 0; i < n; i ++ ) cout << q[i] << " ";
    
    return 0;
}
