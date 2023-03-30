/*
题目链接：https://leetcode.cn/problems/binary-search/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        //定义一个 "大于等于x" 的性质,在性质内查找【左边界】
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) 
                r = mid;
            else 
                l = mid + 1;
        }
        if (nums[l] != target) 
            return -1;
        else 
            return l;
    }
};