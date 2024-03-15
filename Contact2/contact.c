#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//静态的版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态版本的初始化
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//	pc->data = calloc(pc->capacity, sizeof(PeoInfo));
//	if (pc->data == NULL)
//	{
//		perror("InitContact->calloc");
//		return;
//	}
//}

void CheckCapacity(Contact* pc);


void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		//检查容量是否够。
		pc->data[pc->sz]  = tmp;
		pc->sz++;
		//tmp作为一个临时变量，拷贝到pc->data里面去
		//ps->sz表示当前数组中已经存储的数据量，ps->sz++是会在存储完一个数据后自增
		//以便下一个数据存放到数组的下一个位置。
	}

	fclose(pf);
	pf = NULL;
}

//文件版本的初始化函数
void InitContact(Contact* pc)
{
	assert(pc);

	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = calloc(pc->capacity, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact->calloc");
		return;
	}
	//加载文件中的信息到通讯录
	LoadContact(pc);
}

//静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法增加\n");
//		return;
//	}
//	//增加信息
//	printf("请输入名字:");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄:");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别:");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话:");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	//
//	pc->sz++;
//	printf("增加成功\n");
//}


void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += DEFAULT_INC;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContact->realloc");
			return;
		}
	}
	//...
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void AddContact(Contact* pc)
{
	assert(pc);
	//增加容量
	CheckCapacity(pc);
	//增加信息
	printf("请输入名字:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->sz].addr);

	//
	pc->sz++;
	printf("增加成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需打印\n");
		return;
	}
	int i = 0;
	//名字  年龄  性别  电话    地址
	//xxx   xxx  xxx  xxx     xxx
	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		//打印每个人的信息
		printf("%-20s%-5d%-5s%-12s%-30s\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}

void DelContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("输入要删除人的名字:");
	scanf("%s", name);//zhangsan
	//找到名字为name的人
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除这个人
	int i = 0;
	
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要查找人的名字:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//显示出来
	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}


void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要修改人的名字:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//修改
	printf("请输入名字:");
	scanf("%s", pc->data[ret].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[ret].age));
	printf("请输入性别:");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[ret].addr);

	printf("修改成功\n");
}


void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写信息到文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		//fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pf);
		fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}




