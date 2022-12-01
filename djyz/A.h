#pragma once
#ifndef _A_H
#define _A_H
typedef struct {
	int num;//����orֲ����
	char name[20];//����orֲ������
	int age;//����orֲ�����䣬���
	char sex[8];//��ֲ���Ա�
	char habits[100];//���ﰮ��orֲ��ϰ��
	int stars;//��ӭ�̶ȣ���������
} AnimalInfo;//�������ﴦ���ˣ���ȡ��Animal
typedef struct Animal {
	AnimalInfo data;
	Animal* next;
} Animal;
typedef struct account{
	char name[20];
	char password[20];
	bool power;//�Ƿ���й���ԱȨ��
	struct account *next;
} Manager;//�˻���Ϣ

extern Manager User;//��ǰ�˺���Ϣ
extern int Animalnum, Usernum;//�û��Ͷ�ֲ������

void create_user(Manager** head);//��ʼ���û���Ϣ
void create_AnimalInfo(Animal** head);//��ʼ����ֲ����Ϣ
void destory_linkA(Animal** head);//ɾ���ͷŶ�ֲ������
void destory_linka(Manager** head);//ɾ���ͷ��û�����
void save_user(Manager* head);
void save_AnimalInfo(Animal* head);//����������д���ĵ�
void qinkong();//��ջ�����

void login();//��¼�˺�,���ļ�¼����Ϣ
void registeruser();//ע��
void print_all_user();//��ʾ�����û���Ϣ

void printmenu1();//���˵���ʾ
void printmenu2();//���ܲ˵���ʾ
void enterInfo(Animal* head);//����������ֲ����Ϣ
void changeInfo(Animal *head);//�޸�ĳһ��ֲ����Ϣ����Ż�����
Animal* find_animal(Animal* head, char* str);//ͨ������Ѱ��
Animal* find_animal(Animal *head,int number);//ͨ�����Ѱ������

void printInfo();//ͨ�������ʾ��Ϣ
void remark();//����
void printrank();//��ӡ����
#endif
