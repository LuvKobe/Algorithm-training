//题目链接：https://www.acwing.com/problem/content/788/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

int n, k;
int q[N];

int quick_sort(int l, int r, int k) {
    //如果数组当中只有一个数，那么直接返回即可
    if (l == r) 
        return q[l];
    
    int x = q[l], i = l - 1, j = r + 1;
    
    while (i < j)
    {
        while (q[++ i] < x);
        while (q[-- j] > x);
        
        if (i < j) 
            swap(q[i], q[j]);
    }
    
    //就算左边区间有多少个数SL
    int sl = j - l + 1;
    
    //如果k在左边区间，那么就递归左边区间
    if (k <= sl) 
        return quick_sort(l, j, k);
    //如果不在左边区间，那么就直接递归右边区间
    return quick_sort(j + 1, r, k - sl);
}

int main()
{
    //关流
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //
    
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) 
        cin >> q[i];
    
    cout << quick_sort(0, n - 1, k) << endl;

    //for (int i = 0; i < n; i ++ ) cout << q[i] << " ";
    
    return 0;
}