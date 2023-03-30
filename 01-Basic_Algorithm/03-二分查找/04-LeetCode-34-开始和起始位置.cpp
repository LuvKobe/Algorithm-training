/*
题目链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //空数组，直接返回{-1, -1}
        if (0 == nums.size())
            return {-1, -1};

        //1.定义一个 "大于等于target" 的性质，在性质内查找【左边界】
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        //当循环结束以后，l和r就指向target的第一次出现的下标位置
        int begin = l;

        //如果要查找的target不在数组内，那么也要返回{-1, -1}
        if (nums[begin] != target) 
            return {-1, -1};
        
        //2.定义一个 "小于等于x" 的性质，在性质内查找【右边界】
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        //当循环结束以后，l和r就指向target的最后一次出现的下标位置
        int end = l;

        //返回结果
        return {begin, end};
    }
};