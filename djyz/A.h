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

void login();//��¼�˺�,���ļ�¼����Ϣ
void registeruser();//ע��
void print_all_user();//��ʾ�����û���Ϣ

void printmenu();//���˵���ʾ
void enterInfo();//����������ֲ����Ϣ
void chageInfo();//�޸�ĳһ��ֲ����Ϣ����Ż�����
AnimalInfo searchInfo();//ͨ����Ż���������

void printInfo();//ͨ�������ʾ��Ϣ
void remark();//����
void printrank();//��ӡ����
#endif
