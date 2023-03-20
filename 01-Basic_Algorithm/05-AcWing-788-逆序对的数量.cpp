/*
题目链接：

1. 题目解释

什么叫做逆序对？
在数组中，如果前一个数比后一个数大，那么这两个数被称为逆序对。

2. 算法思想

先来回顾一下归并排序的思想：
（1）划分区间：[L, R] ==> [L, mid] 和 [mid+1, R]
（2）递归排序：[L, mid] 和 [mid+1, R]
（3）归并，将左右两个有序序列合并成一个有序序列

那么用归并的思想把区间的逆序对分为3类：
（1）两个数同时出现在左区间
（2）两个数同时出现在右区间
（3）第一个数出现在左区间，第二个数出现在右区间

现在我们假设归并排序可以把整个区间排好序，并且可以返回逆序对的个数：
（1）左半边内部的逆序对数量：mergeSort(L, mid)
（2）右半边内部的逆序对数量：mergeSort(mid+1, R)
（3）逆序对在不同的两个区间：一个数在左区间，一个数在右区间，可以讨论一下：
    对于R区间里面的第一个数a，计算一下在L区间里面有多少个数大于A，假设记为S1个数，那么此时在L区间内，和a构成逆序对的个数就是S1
    对于R区间里面的第二个数b，计算一下在L区间里面有多少个数大于b，假设记为S2个数，那么此时在L区间内，和b构成逆序对的个数就是S2
    .......
    对于R区间里面的最后一个数n，计算一下在L区间里面有多少个数大于n，假设记为Sn个数，那么此时L区间内，和n构成逆序对的个数就是Sn
    所以对于一个数在左区间，一个数在右区间，那么它们可以构成的逆序对的个数就为：S1+S2+...+Sn

那么如何快速的计算出S1+S2+...+Sn呢？
很简单，我们归并排序的第3步是用两个指针分别指向左右区间的起点的，
每一次都是选择这两个指针指向的较小的那个数，然后拿出来，当作整个序列里面当前的最小数
我们现在定义两个指针：i指向L区间，j指向R区间
当q[i]>q[j]的时候，说明L区间里面从q[i]开始，到后面所有的数，都是大于q[j]的，并且q[i]之前的数一定是小于等于q[j]的。
那么此时Sj就等于从i开始到后面所有数的个数
我们知道L左区间的范围是[L, mid]，R右区间的范围是：[mid+1, R]
因此：Sj=mid-i+1
所以，当逆序对的两个数，一个数在左区间，一个数在右区间的时侯，我们只需要每次归并的时候，把输出的结果加上一个Sj，也就是(mid-i+1)
*/

#include <iostream>
using namespace std;

typedef long long LL; //逆序对的数量会存在溢出，所以用long long来存

const int N = 1e5+10;

int n;
int q[N];
int tmp[N];

LL mergeSort(int l, int r)
{   
    if (l >= r) 
        return 0;
    
    int mid = l + ((r - l) >> 1);
    LL res = mergeSort(l, mid) + mergeSort(mid + 1, r);
    
    //归并的过程
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) {
            tmp[k ++] = q[i ++];
        }
        else { //如果左区间i下标指向的数大于右区间j下标指向的数
            tmp[k ++] = q[j ++]; //那么就把右区间j下标指向的数放进tmp数组中
            res += mid - i + 1; //也就是从q[i]开始，到后面所有的数，都是大于q[j]的，说明q[i]和q[j]构成逆序对
        }
    }
    
    //当一个区间遍历完以后，还要把剩下的区间里面的数全部放进tmp数组中
    while (i <= mid) 
        tmp[k ++] = q[i ++];
    while (j <= r)
        tmp[k ++] = q[j ++];
    
    //把tmp数组的数拷贝回原数组中
    //i指向原数组，j指向tmp数组
    for(int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
    
    //返回逆序对的结果
    return res;
}

int main()
{
    //关流
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //
    
    cin >> n;
    for (int i = 0; i < n; i++ ) cin >> q[i];
    
    cout << mergeSort(0, n-1) << endl;
    
    return 0;
}
