#pragma once
#ifndef _A_H
#define _A_H
typedef struct {
	int num;//动物or植物编号
	char name[20];//动物or植物名字
	int age;//动物or植物年龄，年份
	char sex[8];//动植物性别
	char habits[100];//动物爱好or植物习性
	int stars;//欢迎程度，用来排名
} AnimalInfo;//都当动物处理了，就取了Animal
typedef struct Animal {
	AnimalInfo data;
	Animal* next;
} Animal;
typedef struct account{
	char name[20];
	char password[20];
	bool power;//是否具有管理员权限
	struct account *next;
} Manager;//账户信息

extern Manager User;//当前账号信息
extern int Animalnum, Usernum;//用户和动植物数量

void create_user(Manager** head);//初始化用户信息
void create_AnimalInfo(Animal** head);//初始化动植物信息
void destory_linkA(Animal** head);//删除释放动植物链表
void destory_linka(Manager** head);//删除释放用户链表

void login();//登录账号,从文件录入信息
void registeruser();//注册
void print_all_user();//显示所有用户信息

void printmenu();//主菜单显示
void enterInfo();//输入新增动植物信息
void chageInfo();//修改某一动植物信息，编号或名字
AnimalInfo searchInfo();//通过编号或名字搜索

void printInfo();//通过编号显示信息
void remark();//评论
void printrank();//打印排名
#endif
