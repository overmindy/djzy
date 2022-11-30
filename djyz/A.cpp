#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A.h"
Manager User = { "Ding_Yuhe","666666",1,NULL};
int Usernum = 0,Animalnum=0;
void create_user(Manager** head) {
	*head = (Manager*)malloc(sizeof(Manager));
	Manager* mov = NULL, * mov1 = *head;
	FILE* fp = NULL;
	fp = fopen("account.txt", "r");
	do {
		mov = (Manager*)malloc(sizeof(Manager));
		fscanf(fp, "%s %s %d\n",
			mov->name, mov->password, &(mov->power));
		mov1->next = mov;
		mov1 = mov;
		mov1->next = NULL;
		mov = NULL;
		Usernum++;
	} while (!feof(fp));
	fclose(fp);
}//初始化用户链表
void create_AnimalInfo(Animal** head) {
	*head = (Animal*)malloc(sizeof(Animal));
	Animal* mov = NULL, * mov1 = *head;
	FILE* fp = NULL;
	fp = fopen("AnimalInfo.txt", "r");
	do {
		mov = (Animal*)malloc(sizeof(Animal));
		fscanf(fp, "%d %s %d %s %s %d\n",
			&(mov->data).num, (mov->data).name, &(mov->data).age, (mov->data).sex,
			(mov->data).habits, &(mov->data).stars);
		mov1->next = mov;
		mov1 = mov;
		mov1->next = NULL;
		mov = NULL;
		Animalnum++;
	} while (!feof(fp));
	fclose(fp);
}//初始化动植物链表
void destory_linka(Manager** head) {
	Manager* des = *head;
	while (*head != NULL) {
		*head = (*head)->next;
		free(des);
		des = *head;
	}
	Usernum = 0;
}//释放用户链表
void destory_linkA(Animal** head) {
	Animal* des = *head;
	while (*head != NULL) {
		*head= (*head)->next;
		free(des);
		des = *head;
	}
	Animalnum = 0;
}//释放动植物链表