#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
字符串匹配算法：BF算法 -> 暴力匹配算法 

假定我们给出字符串 "ababcabcdabcde"，作为主串，
然后我们给出字符串 "abcd"，作为子串
现在我们需要查找子串是否在主串中出现
若出现，则返回主串中的第一个匹配的下标
若没有出现，失败返回 -1;

假设主串的长度是 M
字串的长度是 N
则时间复杂度为 O(M*N)
*/

/*
str：主串
sub：字串
返回值：返回字串在主串当中的下标，如果不存在返回-1
*/

int BF(char* str, char* sub) {
	assert(str && sub);
	// 主串和字串为空，则不存在，返回-1
	if (str == NULL || sub == NULL) {
		return -1;
	}

	int lenStr = strlen(str); // 主串长度
	int lenSub = strlen(sub); // 字串长度

	int i = 0; //指向主串的第一个字符的下标
	int j = 0; //指向字串的第一个字符的下标

	while (i < lenStr && j < lenSub) { // 当i没有遍历完主串，并且j也没有遍历完字串
		//判断主串的i下标 和 字串的j下标是否相同
		if (str[i] == sub[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1; // i回退到和j相同下标的位置，再加1
			j = 0; // j 回退到起始下标
		}
	}

	//while循环走完有两种情况：
	//1. i超过主串长度
	//1. j超过字串长度，说明j走完了字串
	if (j >= lenSub) {
		return i - j;
	}
	else {
		return -1;
	}
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd")); //返回5
	printf("%d\n", BF("ababcabcdabcde", "abcdf")); //返回-1
	printf("%d\n", BF("ababcabcdabcde", "ab")); //返回0


	return 0;
}