#include <iostream>
#include <math.h>
using namespace std;

/*
在[-1000, 1000]的范围内，给一个浮点数x，求它的三次方根。

假设 x=1000.00，现在求x的三次方根

1.先计算整个区间[-1000, 1000]的中间值mid

2.如果【mid^3 >= x】，说明x一定是在mid的左边（包括mid）
  所以更新【r=mid】

3.如果【mid^3 < x】，说明x一定是在mid的右边（包括mid）
  所以更新【l=mid】
*/

int main()
{
    double x;
    cin >> x;
    
    //l和r用来确定边界，可以不用考虑输入的数为负数还是正数的情况，因为我们是从最大的边界去找范围内的二分答案。
    double l = -10000, r = 10000;
    
    //对于精度问题：题干中要求6位小数我们用8位来保证准确性，我们所设定的精度始终要比题干要求多两位
    //（不信的话你可以试试：精度为1e-6 输入1（得到结果0.999999），再试试精度为1e-8 输入1 （得到结果1.000000）
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (pow(mid, 3) >= x) 
            r = mid;
        else 
            l = mid;
    }
    
    printf("%lf\n", l);
    return 0;
}

/*方法二
int main()
{
    double n;
    cin >> n;
    
    // cbrt 求三次方根
    // pow 求n次方函数
    printf("%.6lf\n", cbrt(n));
   
    return 0;
}
*/