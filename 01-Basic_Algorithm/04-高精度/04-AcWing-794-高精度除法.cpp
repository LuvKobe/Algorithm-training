/*
题目链接：https://www.acwing.com/problem/content/description/796/

思路：

按照除法的法则

设置余数r

r 一开始初始化为0

由于除法是从高位开始计算的 所以结果也是从高位开始存储的（结果需要反转）

r = r * 10 + Ai

商就是r / 10

反而余数r = r % 10 对于下一个A[i]进行计算
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Div(vector<int>& A, int& b, int& r)
{
    vector<int> C; // 商
    r = 0; // 余数
    for (int i = A.size() - 1; i >= 0; i--) // 对A从最高位开始处理
    {
        r = r * 10 + A[i]; // 将上次的余数*10在加上当前位的数字，便是该位需要除的被除数
        C.push_back(r / b); // r/b即为商在这一位的数字
        r %= b;
    }
    // 由于在除法运算中，高位到低位运算，因此C的前导零都在vector的前面而不是尾部
    // 所以vector只有删除最后一个数字，
    // 因此我们将C翻转，这样0就位于数组尾部，可以使用pop函数删除前导0
    reverse(C.begin(), C.end());
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
    
    string a; // a用字符串存储
    int b; // b用int存储
    
    cin >> a >> b;
    
    vector<int> A; // 把a转化为数字，存入数组中
    for (int i = a.size() - 1; i >= 0; i--) 
        A.push_back(a[i] - '0');
    
    int r; // 余数
    
    auto C = Div(A, b, r);
    
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i]; // 输出商
        
    cout << endl << r << endl; // 输出余数
        
    return 0;
}