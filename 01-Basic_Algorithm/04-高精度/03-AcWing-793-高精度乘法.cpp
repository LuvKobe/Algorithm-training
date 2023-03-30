/*
题目链接：https://www.acwing.com/problem/content/795/

首先我们看一下，这道题似乎很难
其实也不难，我们只需要先输入两个字符串类型的a和b
然后用数组倒着存一下
每一位都进行高精乘
然后如果乘出来的数大于10
就给下一位加上这一位除以10
当前这位取模10
最后因为存的是倒着的
所以输出倒着的数组

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// C = A * b
// A:很长的整数
// b:一个int变量
vector<int> Mul(vector<int>& A, int b)
{
    vector<int> C;
    
    int t = 0; // 最开始的进位是0
    for (int i = 0; i < A.size() || t; i ++) 
    {
        if (i < A.size()) 
            t += A[i] * b;
        C.push_back(t % 10); // 取出个位尾插进C中
        t /= 10; // 表示要进位的数
    }
    
    //去除前导0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    string a; // a用字符串存储
    int b; // b用int存储
    
    cin >> a >> b;
    
    vector<int> A; // 把A转化为数字
    for (int i = a.size()-1; i >= 0; i-- )
        A.push_back(a[i] - '0');
    
    // 乘法函数
    auto C = Mul(A, b);
    
    for (int i = C.size()-1; i >= 0; i-- )
        cout << C[i];
    
    return 0;
}