/*
1. 思路
和高精度加法差不多，值得注意的是
减法的借位处理
相减为负数的处理
前导0的处理

2. 收获
对于 t = A[i] - B[i] - t； 可以拆为 t = A[i] - t，如果B[i]合法，再t -= B[i] 这么两步来做
相减后t的处理 ，把 t >=0 和 t < 0 用一个式子来表示 t = (t + 10) % 10 这个木有想到
A B大小判断，自己写的太冗余，不如单独拎出来
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 判断A是否大于等于B (A >= B)
bool cmp(vector<int>& A, vector<int>& B)
{
    // 如果A和B的位数不相等,长度长的那个数大
    if (A.size() != B.size())
        return A.size() > B.size();
    
    //如果A和B的位数相等(比如:123和456)
    for (int i = A.size() - 1; i >= 0; i--)
    {
        // 那么就判断A和B的每个位数上面的值
        if (A[i] != B[i])
            return A[i] > B[i]; // 如果A[i] > B[i]返回true，反之，返回false
    }
    
    //当循环走到这里,说明A=B,那么直接返回true
    return true;
}

// C = A - B
vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> C; // 用来存储最后的答案
    
    int t = 0; // 每一位上相减得到的数
    for (int i = 0; i < A.size(); i++) // 遍历一遍，和高精度加法不一样的是，只要遍历完A就行了，因为这里A肯定比B长
    {
        t = A[i] - t; // t要等于: 【A的当前位】减掉【自己】，因为上一位有可能出现借位的情况
        
        if (i < B.size()) // 如果没有遍历完B，那么t减掉B的当前位
            t -= B[i];
        
        // 这里如果没有借位，(t + 10) % 10就刚好等于t
        // 如果这里有借位，(t + 10) % 10就会借一个10下来
        C.push_back((t + 10) % 10); // 更新C数组
        
        if (t < 0) // 如果t < 0，说明不够减，需要借位，把t赋值为1，就是在下一次执行中，A的当前位会减掉t
            t = 1;
        else // 否则够减，赋值为0，不用借位
            t = 0;
    }
    // 去除前导0的情况
    // 当C的位数大于1,并且最后一位等于0时,就pop掉
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    
    return C;
}

int main()
{
    //
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //
    
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) 
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) 
        B.push_back(b[i] - '0');
    
    if (cmp(A, B)) { // 如果A>B,那么直接相减即可
        auto C = sub(A, B);
        
        for (int i = C.size() - 1; i >= 0; i--) 
            cout << C[i];
    }
    else { // 如果A<B,那么转换成B-A,然后再添加一个负号
        auto C = sub(B, A); // 计算B - A
        cout << "-"; // 给前面加上一个负号
        for (int i = C.size() - 1; i >= 0; i--) // 反向输出C数组
            cout << C[i];
    }
    return 0;
}