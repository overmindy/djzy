#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A.h"
int main() {
	Manager* accountlink = NULL;
	Animal* Animallink = NULL;
	create_user(&accountlink);
	create_AnimalInfo(&Animallink);//��ʼ��

	Animal* p = NULL;
	p = find_animal(Animallink, 4);
	if (p != NULL) {
		printf("%s\n", p->data.name);
	}//���԰�����������
	char str[] = { "����" };
	p = find_animal(Animallink, str);
	if (p != NULL) {
		printf("%s\n", p->data.habits);
	}//���԰������������
	changeInfo(Animallink);//������Ϣ�޸�

	save_user(accountlink);
	save_AnimalInfo(Animallink);

	destory_linkA(&Animallink);
	destory_linka(&accountlink);//��������
	return 0;
}