#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
�ַ���ƥ���㷨��BF�㷨 -> ����ƥ���㷨 

�ٶ����Ǹ����ַ��� "ababcabcdabcde"����Ϊ������
Ȼ�����Ǹ����ַ��� "abcd"����Ϊ�Ӵ�
����������Ҫ�����Ӵ��Ƿ��������г���
�����֣��򷵻������еĵ�һ��ƥ����±�
��û�г��֣�ʧ�ܷ��� -1;

���������ĳ����� M
�ִ��ĳ����� N
��ʱ�临�Ӷ�Ϊ O(M*N)
*/

/*
str������
sub���ִ�
����ֵ�������ִ����������е��±꣬��������ڷ���-1
*/

int BF(char* str, char* sub) {
	assert(str && sub);
	// �������ִ�Ϊ�գ��򲻴��ڣ�����-1
	if (str == NULL || sub == NULL) {
		return -1;
	}

	int lenStr = strlen(str); // ��������
	int lenSub = strlen(sub); // �ִ�����

	int i = 0; //ָ�������ĵ�һ���ַ����±�
	int j = 0; //ָ���ִ��ĵ�һ���ַ����±�

	while (i < lenStr && j < lenSub) { // ��iû�б���������������jҲû�б������ִ�
		//�ж�������i�±� �� �ִ���j�±��Ƿ���ͬ
		if (str[i] == sub[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1; // i���˵���j��ͬ�±��λ�ã��ټ�1
			j = 0; // j ���˵���ʼ�±�
		}
	}

	//whileѭ�����������������
	//1. i������������
	//1. j�����ִ����ȣ�˵��j�������ִ�
	if (j >= lenSub) {
		return i - j;
	}
	else {
		return -1;
	}
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd")); //����5
	printf("%d\n", BF("ababcabcdabcde", "abcdf")); //����-1
	printf("%d\n", BF("ababcabcdabcde", "ab")); //����0


	return 0;
}