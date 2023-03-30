/*
题目链接：https://www.acwing.com/problem/content/793/

1. 模拟手动加法计算
例如计算：567 + 28
先个位相加： 7 + 8 = 15，所以结果的个位是5，向十位进 1
再十位相加： 6 + 2 + 1（进位）= 9， 所以十位是 9，向百位进 0
在百位相加： 5 + 0 = 5， 所以结果的百位是 5
综上，计算结果为 595

2. 计算 567 + 28
用 a, b 两个字符串存储输入。a = 567, b = 28
为了方便计算，将两个数分别【倒序】存放在 A， B 两个整数数组中。 A = [7, 6, 5], B = [8, 2]
新建整数数组 C 保存结果，整型变量 t 保存进位，初始 t = 0.
将各个位上的数字相加，求出结果对应位上的数字和进位。
例如对个位计算： A[0] + B[0] = 7 + 8 = 15, 结果个位上是 5，进位是 1. 所以 C[0] = 5, 进位 t = 1
最后把结果数组 C 中就保存了计算倒序结果，倒序输出就是答案

3. 其他
假设A是非负数，那么【A <= 10】和【len(A) <= 10】有什么区别呢？
【A <= 10】表示A的取值范围是：[0, 10]
【len(A) <= 10】表示A的位数的取值范围是：[0, 9999999999]
也就是：一个是数值，一个是位数

4. 代码解释

if (i < B.size()) 
    t += B[i]; 

因为我们默认是让A数组的内容大于B数组的内容
所以我们i下标必定会超过B数组的下标，所以需要判断一下
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// C = A + B
vector<int> Add(vector<int>& A, vector<int>& B)
{
    // 为了方便计算，让A中保存较长的数字， B中保存较短的数字
    if (A.size() < B.size()) // 如果A中的数字长度小于B，那么就交换
        return Add(B, A);
    
    vector<int> C; // 保存结果的数组
    int t = 0; // 设置进位符，最开始为0
    for (int i = 0; i < A.size(); i++ ) {
        t += A[i];
        if (i < B.size()) // 如果i没有超过B数组的范围
            t += B[i]; // 那么加上 B 的第 i 位上的数字
        C.push_back(t % 10); // 把结果放入 C 中
        t /= 10; // t 更新成进位
    }
    if (t)  // 当循环结束以后，如果进位符为1，那么就放进C数组中
        C.push_back(t);
    return C; // 返回结果
}

int main()
{
    //
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    //
    
    string a, b; // 以字符串形式保存输入的两个整数
    vector<int> A, B; //保存两个整数的数组
    
    // a:"12345"
    // b:"567"
    cin >> a >> b; // 输入两个大整数
    
    // A:[5, 4, 3, 2, 1]
    for (int i = a.size()-1; i >= 0; i-- ) //以倒序的形式存储每一个数
        A.push_back(a[i] - '0'); // 先把每个字符转化为数字
    
    // B:[7, 6, 5]
    for (int i = b.size()-1; i >= 0; i-- ) //以倒序的形式存储每一个数
        B.push_back(b[i] - '0'); // 先把每个字符转化为数字
    
    // 调用加函数
    auto C = Add(A, B);
    
    // 倒序输出C中的数字
    for (int i = C.size()-1; i >= 0; i-- )
        cout << C[i];
        
    return 0;
}