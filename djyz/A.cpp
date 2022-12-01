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
}//��ʼ���û�����
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
}//��ʼ����ֲ������
void destory_linka(Manager** head) {
	Manager* des = *head;
	while (*head != NULL) {
		*head = (*head)->next;
		free(des);
		des = *head;
	}
	Usernum = 0;
}//�ͷ��û�����
void destory_linkA(Animal** head) {
	Animal* des = *head;
	while (*head != NULL) {
		*head= (*head)->next;
		free(des);
		des = *head;
	}
	Animalnum = 0;
}//�ͷŶ�ֲ������
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
	printf("----------------���ܲ˵�----------------\n");
	printf("1.�鿴��ֲ�����а�\n 2.������ֲ����Ϣ\n3.¼���µĶ�ֲ����Ϣ\n");
}

void enterInfo(Animal* head)
{
	Animal* mov = head;
	while (mov->next != NULL) {
		mov = mov->next;
	};//�ƶ������һ���ڵ�
	Animal* new_node;
	new_node = (Animal*)malloc(sizeof(Animal));
	printf("�����붯��/ֲ�������:");
	rewind(stdin);
	scanf("%s", new_node->data.name);
	printf("�����붯��/ֲ�������:");
	rewind(stdin);
	scanf("%d", &(new_node->data.age));
	printf("�����붯��/ֲ����Ա�:");
	rewind(stdin);
	scanf("%s", new_node->data.sex);
	printf("�����붯��İ���/ֲ���ϰ��:");
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
		printf("δ�ҵ�");
		return NULL;
	}
}
Animal* find_animal(Animal* head, char* str) {
	struct Animal* p = NULL;
	for (p = head->next; p->next != NULL && strcmp(str,p->data.name)!=0; p = p->next);
	if (strcmp(str, p->data.name) == 0) return p;
	else {
		printf("δ�ҵ�");
		return NULL;
	}
}
void changeInfo(Animal *head)
{
	int number, choice;
	int flag = 1;
	char ch='N';
	Animal* p=NULL;
	/*д������ �˴�Ӧ��һ����������ƶ�Ӧ�����ݱ�*/
	printf("����������Ҫ�޸ĵĶ�ֲ��ı�ţ�");
	rewind(stdin);
	scanf("%d", &number);
	p = find_animal(head,number);
	printf("��ȷ����Ҫ�޸ĵĶ�ֲ����/���ơ�\n�ñ���µ���Ϣ����: ");
	printf("�Ȳ�д��Ϣ�ˡ�");
	/*�˴�Ӧ��һ��ͨ���ṹ��ָ����ʾ��Ϣ�ĺ���*/
	printf("��ѡ����Ҫ�޸ĵĲ���:\n");
	printf("1.�޸Ķ�ֲ������� \n2.�޸Ķ�ֲ������� \n3.�޸Ķ�ֲ����Ա� \n4.�޸Ķ���İ��û�ֲ���ϰ��\n");

	while (flag){
		rewind(stdin);
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("�������޸ĺ�����ƣ�");
			rewind(stdin);
			scanf("%s", p->data.name);
			break;
		case 2:
			printf("�������޸ĺ�����䣺");
			rewind(stdin);
			scanf("%d", &(p->data.age));
			break;
		case 3:
			printf("�������޸ĺ���Ա�");
			rewind(stdin);
			scanf("%s", p->data.sex);
			break;
		case 4:
			printf("�������޸ĺ�İ���/ϰ�ԣ�");
			rewind(stdin);
			scanf("%s", p->data.habits);
		default:
			break;
		}
		printf("�Ƿ�����޸�:(Y/N):");
		rewind(stdin);
		scanf("%c", &ch);
		if (ch == 'Y')
			flag = 1;
		else
			flag = 0;
	}
}