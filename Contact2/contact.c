#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//��̬�İ汾
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬�汾�ĳ�ʼ��
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
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		//��������Ƿ񹻡�
		pc->data[pc->sz]  = tmp;
		pc->sz++;
		//tmp��Ϊһ����ʱ������������pc->data����ȥ
		//ps->sz��ʾ��ǰ�������Ѿ��洢����������ps->sz++�ǻ��ڴ洢��һ�����ݺ�����
		//�Ա���һ�����ݴ�ŵ��������һ��λ�á�
	}

	fclose(pf);
	pf = NULL;
}

//�ļ��汾�ĳ�ʼ������
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
	//�����ļ��е���Ϣ��ͨѶ¼
	LoadContact(pc);
}

//��̬�汾
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷�����\n");
//		return;
//	}
//	//������Ϣ
//	printf("����������:");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("����������:");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�:");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰:");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ:");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	//
//	pc->sz++;
//	printf("���ӳɹ�\n");
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
			printf("���ݳɹ�\n");
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
	//��������
	CheckCapacity(pc);
	//������Ϣ
	printf("����������:");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pc->sz].addr);

	//
	pc->sz++;
	printf("���ӳɹ�\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ������ӡ\n");
		return;
	}
	int i = 0;
	//����  ����  �Ա�  �绰    ��ַ
	//xxx   xxx  xxx  xxx     xxx
	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		//��ӡÿ���˵���Ϣ
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
	return -1;//�Ҳ���
}

void DelContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("����Ҫɾ���˵�����:");
	scanf("%s", name);//zhangsan
	//�ҵ�����Ϊname����
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ�������
	int i = 0;
	
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�����˵�����:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//��ʾ����
	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}


void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�޸��˵�����:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	//�޸�
	printf("����������:");
	scanf("%s", pc->data[ret].name);
	printf("����������:");
	scanf("%d", &(pc->data[ret].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[ret].sex);
	printf("������绰:");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[ret].addr);

	printf("�޸ĳɹ�\n");
}


void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д��Ϣ���ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		//fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pf);
		fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}




