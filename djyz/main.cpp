#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A.h"
int main() {
	Manager* accountlink = NULL;
	Animal* Animallink = NULL;
	create_user(&accountlink);
	create_AnimalInfo(&Animallink);//初始化

	Animal* p = NULL;
	p = find_animal(Animallink, 4);
	if (p != NULL) {
		printf("%s\n", p->data.name);
	}//测试按编号搜索输出
	char str[] = { "轩轩" };
	p = find_animal(Animallink, str);
	if (p != NULL) {
		printf("%s\n", p->data.habits);
	}//测试按名字搜索输出
	changeInfo(Animallink);//测试信息修改

	save_user(accountlink);
	save_AnimalInfo(Animallink);

	destory_linkA(&Animallink);
	destory_linka(&accountlink);//销毁链表
	return 0;
}