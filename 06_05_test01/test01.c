#define _CRT_SECURE_NO_WARNINGS
#include<md5.h>
//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void getMD5(const char * res, char * dest)
{
	MD5_CTX ctx;
	// 初始化
	MD5_Init(&ctx);
	// 添加数据
	MD5_Update(&ctx, res, strlen(res));
	// 计算结果
	unsigned char md[16] = { 0 };
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; ++i)
	{
		sprintf(&dest[i * 2], "%02x", md[i]);
	}
}

int main()
{
	char result[33] = { 0 };
	getMD5("hello MD5", result);

	printf("MD5 value:%s\n" , result);

	system("Pause");
	return 0;

}