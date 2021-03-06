//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char STDataType;//ջ�д洢��Ԫ������

typedef struct Stack
{
	STDataType* a;//ջ
	int top;//ջ��
	int capacity;//��������������
}Stack;

//��ʼ��ջ
void StackInit(Stack* pst)
{
	assert(pst);

	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);//��ʼ��ջ�ɴ洢4��Ԫ��
	pst->top = 0;//��ʼʱջ����Ԫ�أ�ջ��Ϊ0
	pst->capacity = 4;//����Ϊ4
}

//����ջ
void StackDestroy(Stack* pst)
{
	assert(pst);

	free(pst->a);//�ͷ�ջ
	pst->a = NULL;//��ʱ�ÿ�
	pst->top = 0;//ջ����0
	pst->capacity = 0;//������0
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)//ջ������������
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity *= 2;//ջ��������Ϊԭ��������
	}
	pst->a[pst->top] = x;//ջ��λ�ô��Ԫ��x
	pst->top++;//ջ������
}

//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));//���ջ�Ƿ�Ϊ��

	pst->top--;//ջ������
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));//���ջ�Ƿ�Ϊ��

	return pst->a[pst->top - 1];//����ջ��Ԫ��
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;//top��ֵ����ջ����ЧԪ�صĸ���
}

bool isValid(char * s){
	Stack st;//����ջ
	StackInit(&st);//��ʼ��ջ
	char* cur = s;
	while (*cur)//�����ַ���
	{
		if (*cur == '(' || *cur == '{' || *cur == '[')//ǰ���ţ�ѹջ
		{
			StackPush(&st, *cur);
			cur++;
		}
		else//������
		{
			if (StackEmpty(&st))//ջΪ�գ�����false
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackTop(&st);
			if ((top == '('&&*cur != ')')
				|| (top == '{'&&*cur != '}')
				|| (top == '['&&*cur != ']'))//������δ��ջ��λ�õ�������ʽƥ��
			{
				StackDestroy(&st);
				return false;
			}
			else//����ƥ��
			{
				StackPop(&st);
				cur++;
			}
		}
	}
	bool ret = StackEmpty(&st);//ջ�Ƿ�Ϊ��
	StackDestroy(&st);
	return ret;//����
}