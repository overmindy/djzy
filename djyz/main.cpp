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
	//测试
	Manager* mov1 = accountlink;
	mov1 = mov1->next->next;
	printf("%s\t%s\t%d\n", mov1->name, mov1->password, mov1->power);

	Animal* mov2 = Animallink;
	mov2 = mov2->next->next;
	printf("%d %s %d %s %s %d\n",
		(mov2->data).num, (mov2->data).name, (mov2->data).age, (mov2->data).sex,
		(mov2->data).habits, &(mov2->data).stars);

	destory_linkA(&Animallink);
	destory_linka(&accountlink);//销毁链表
	return 0;
}