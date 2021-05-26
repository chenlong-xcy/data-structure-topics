#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	unsigned  int   weight;   //Ȩֵ
	unsigned  int   parent;    //˫��
	unsigned  int    lchild, rchild; //���Һ���
}HTNode, *HuffmanTree;      //��̬��������洢�շ�����

typedef char  **HuffmanCode; //��̬��������洢�շ��������


void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);

void select(HuffmanTree t, int i, int& s1, int& s2);

int min(HuffmanTree t, int i);