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
void save_AnimalInfo(Animal* head) {
	Animal* mov = head;
	FILE* fp = NULL;
	fp = fopen("AnimalInfo.txt", "w");
	int i = 0;
	while(mov->next !=NULL) {
		i++;
		mov = mov->next;
		fprintf(fp, "%d %s %d %s %s %d\n",
			i, (mov->data).name, (mov->data).age, (mov->data).sex,
			(mov->data).habits, (mov->data).stars);
	}
	fclose(fp);
}
void save_user(Manager* head) {
	Manager* mov = head;
	FILE* fp = NULL;
	fp = fopen("account.txt", "w");
	while (mov->next != NULL) {
		mov = mov->next;
		fprintf(fp, "%s %s %d\n",
			mov->name, mov->password, mov->power
		);
	}
	fclose(fp);
}


//ding_yuhe
void printmenu2(void) {
	printf("----------------功能菜单----------------\n");
	printf("1.查看动植物排行榜\n 2.搜索动植物信息\n3.录入新的动植物信息\n");
}

void enterInfo(Animal* head)
{
	Animal* mov = head;
	while (mov->next != NULL) {
		mov = mov->next;
	};//移动到最后一个节点
	Animal* new_node;
	new_node = (Animal*)malloc(sizeof(Animal));
	printf("请输入动物/植物的名字:");
	rewind(stdin);
	scanf("%s", new_node->data.name);
	printf("请输入动物/植物的年龄:");
	rewind(stdin);
	scanf("%d", &(new_node->data.age));
	printf("请输入动物/植物的性别:");
	rewind(stdin);
	scanf("%s", new_node->data.sex);
	printf("请输入动物的爱好/植物的习性:");
	rewind(stdin);
	scanf("%s", new_node->data.habits);
	new_node->data.stars = 0;
	new_node->data.num=Animalnum+1;
	mov->next = new_node;
	mov = mov->next;
	mov->next = NULL;
	FILE* fp = fopen("AnimalInfo.txt","r+");
	fseek(fp,0,SEEK_END);
	fprintf(fp,"\n%d %s %d %s %s 0", (mov->data).num, (mov->data).name, (mov->data).age, (mov->data).sex,
		(mov->data).habits);
	fclose(fp);
	Animalnum++;
}
Animal* find_animal(Animal *head,int number){
	struct Animal* p=NULL;
	for (p = head->next;p != NULL && p->data.num!=number;p = p->next);
	if (p->data.num==number) return p;
	else {
		printf("未找到");
		return NULL;
	}
}
Animal* find_animal(Animal* head, char* str) {
	struct Animal* p = NULL;
	for (p = head->next; p->next != NULL && strcmp(str,p->data.name)!=0; p = p->next);
	if (strcmp(str, p->data.name) == 0) return p;
	else {
		printf("未找到");
		return NULL;
	}
}
void changeInfo(Animal *head)
{
	int number, choice;
	int flag = 1;
	char ch='N';
	Animal* p=NULL;
	/*写不会了 此处应有一个编号与名称对应的数据表*/
	printf("请输入你想要修改的动植物的编号：");
	rewind(stdin);
	scanf("%d", &number);
	p = find_animal(head,number);
	printf("请确认需要修改的动植物编号/名称。\n该编号下的信息如下: ");
	printf("先不写信息了。");
	/*此处应有一个通过结构体指针显示信息的函数*/
	printf("请选择您要修改的部分:\n");
	printf("1.修改动植物的名称 \n2.修改动植物的年龄 \n3.修改动植物的性别 \n4.修改动物的爱好或植物的习性\n");

	while (flag){
		rewind(stdin);
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("请输入修改后的名称：");
			rewind(stdin);
			scanf("%s", p->data.name);
			break;
		case 2:
			printf("请输入修改后的年龄：");
			rewind(stdin);
			scanf("%d", &(p->data.age));
			break;
		case 3:
			printf("请输入修改后的性别：");
			rewind(stdin);
			scanf("%s", p->data.sex);
			break;
		case 4:
			printf("请输入修改后的爱好/习性：");
			rewind(stdin);
			scanf("%s", p->data.habits);
		default:
			break;
		}
		printf("是否继续修改:(Y/N):");
		rewind(stdin);
		scanf("%c", &ch);
		if (ch == 'Y')
			flag = 1;
		else
			flag = 0;
	}
}