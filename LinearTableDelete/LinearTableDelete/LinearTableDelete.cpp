// LinearTableDelete.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK   1
typedef struct
{
	int *elem;
	int length;
	int Listsize;
} Sqlist;
int initList_Sq(Sqlist *LA, int len)
{
	LA->elem = (int *)malloc(sizeof(int)* len);
	if (!LA->elem)return ERROR;
	LA->length = 0;
	LA->Listsize = len;
	return OK;
}
int delList_Sq(Sqlist *LA, int location)
{
	int j;
	if (location<1 && location>LA->length + 1) return ERROR;
	for (j = location; j<LA->length; j++)
	{
		LA->elem[j - 1] = LA->elem[j];

	}
	LA->length--;
	return OK;
}
int main()
{
	Sqlist *LA;
	int a_len, i;
	printf("请输入数组长度：\n");
	scanf("%d", &a_len);
	LA = (Sqlist *)malloc(sizeof(Sqlist));
	initList_Sq(LA, a_len);
	printf("请输入数组：\n");
	for (i = 0; i<a_len; i++)
	{
		scanf("%d", &LA->elem[i]);
		LA->length++;
	}
	int location;
	printf("请输入删除的位置：\n");
	scanf("%d", &location);
	delList_Sq(LA, location);
	for (i = 0; i<LA->length; i++)
	{
		printf("%d ", LA->elem[i]);
	}
	system("pause");
}
