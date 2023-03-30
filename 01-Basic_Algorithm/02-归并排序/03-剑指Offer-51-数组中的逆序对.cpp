//题目链接：https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
int tmp[50010];
class Solution {
public:
    LL mergeSort(vector<int>& q, int l, int r) {
        if (l >= r) return 0;
        int mid = l + ((r - l) >> 1);
        LL res = mergeSort(q, l, mid) + mergeSort(q, mid + 1, r);

        //
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (q[i] <= q[j]) tmp[k ++] = q[i ++];
            else {
                tmp[k ++] = q[j ++];
                res += mid - i + 1;
            }
        }
        //
        while (i <= mid) tmp[k ++] = q[i ++];
        while (j <= r) tmp[k ++] = q[j ++];
        for (int i = l, j = 0; i <= r; i++, j++)
        {
            q[i] = tmp[j];
        }
        
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};