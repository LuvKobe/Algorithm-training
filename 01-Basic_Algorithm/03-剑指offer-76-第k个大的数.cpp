//题目链接：https://leetcode.cn/problems/xx4gT2/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int quickSort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];
        int x = nums[(l + r) >> 1];
        int i = l - 1;
        int j = r + 1;

        //排升序
        while (i < j)
        {
            while (nums[++ i] > x);
            while (nums[-- j] < x);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        int sl = j - l + 1;
        if (k <= sl)
            return quickSort(nums, l, j, k);
        return quickSort(nums, j + 1, r, k-sl);

    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, k);
    }
};