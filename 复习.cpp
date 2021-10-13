#include<stdio.h>
void swap(int & a, int & b) {
	int t = a;
	a = b;
	b = t;
}

int partation(int num[], int low, int high) {
	int i = low, j = high, pivot = num[low];
	while(i < j) {
		while(i < j && num[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(num[i++], num[j]);
		}
		while(i < j && num[i] < pivot) {
			i++;
		}
		if (i < j) {
			swap(num[i], num[j--]);
		}
	}	
	
	return i;
}

void QuickSort(int num[], int low, int high) {
	if (low < high) {
		int mid = partation(num, low, high);
		QuickSort(num, low, mid);
		QuickSort(num, mid + 1, high);
	}
}

int main()
{
	int num[10], i;
	printf("������ʮ������:\n");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	
	QuickSort(num, 0, 9);
	printf("�����:\n");
	for(i = 0; i < 10; i++) {
		printf("%d	",num[i]); 
	} 
	return 0;
}
#include<stdio.h>
void swap(int & a, int & b) {
	int t = a;
	a = b;
	b = t;	
}

int  partation (int num[], int low, int high) {
	int i = low, j = high, pivot = num[low];
	while(i < j) {
		while(i < j && num[j] >= pivot) {
			j--;
		} 
		if (i < j) {
			swap(num[i++],num[j]);
		}
		while(i < j && num[i] < pivot) {
			i++;
		}
		if (i < j) {
			swap(num[i], num[j--]);	
		}
	}	
	return i;
}

void QuickSort(int num[], int low, int high) {
	if (low < high) {
		int mid = partation(num,0, 9);
		QuickSort(num,low,mid);
		QuickSort(num,mid + 1, high);
	}
}

int main()
{
	int num[10], i;
	printf("������ʮ�����֣�");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	QuickSort(num,0,9);
	printf("�����:\n"); 
	for(i = 0; i < 10; i++) {
		printf("%d	",&num[i]);
	}
	return 0;
}


//ѯ�ʷ�����������(��ϰ)
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode,*BNode_pioner;

void Creat(BNode_pioner & root) {
	BNode_pioner p = (BNode*)malloc(sizeof(BNode));
	ElemType value;
	char ch;
	printf("������ý���ֵ:\n");
	scanf("%c",&value);
	getchar();
	p->data = value;
	printf("�Ƿ�Ը�ⴴ��%c������?\n",p->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(p->lchild);
	}
	else {
		p->lchild = NULL;
	}
	printf("�Ƿ�Ը�ⴴ��%c���Һ��ӣ�\n",p->data);
	scanf("%c",&ch); 
	getchar();
	if ('Y' == ch) {
		Creat(p->rchild);
	}
	else {
		p->rchild = NULL;
	}
}

int main()
{
	char ch;
	printf("�Ƿ�Ը�ⴴ��һ�ÿ���?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		BNode_pioner root = NULL;
		Creat(root);
	}
	else {
		exit(-1);
	}
	return 0;
}
//ѯ�ʷ�����������(�ٴθ�ϰ)
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode,*BNode_pioner;

void Creat(BNode_pioner& root) {
	root = (BNode_pioner)malloc(sizeof(BNode));
	char ch;
	printf("������ýڵ��ֵ:\n");
	scanf("%c",&ch);
	getchar();
	root->data = ch;
	printf("��Ը�ⴴ��%c����������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}
	printf("��Ը�ⴴ��%c����������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->rchild);
	}
	else {
		root->rchild = NULL;
	}
}

int main()
{	
	char ch;
	printf("��Ը�ⴴ��һ�ÿյĶ�������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		BNode_pioner p = NULL;
		Creat(p);
	}
	else {
		exit(-1);
	}	
	return 0;
} 
//ѯ�ʷ�����������
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode { 
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;	
}BNode,*BNode_pioner;

void Creat(BNode_pioner& root) {
	root = (BNode_pioner)malloc(sizeof(BNode));
	ElemType value;
	char ch;
	printf("������ý���ֵ:\n");
	scanf("%c",value);
	getchar();
	root->data = value;
	printf("�Ƿ�Ը�ⴴ��%c��������?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}
	printf("�Ƿ�Ը�ⴴ��%c��������?\n");
	scanf("%c",&ch);
	if ('Y' == ch) {
		Creat(root->rchild);
	}
	else {
		root->rchild = NULL;
	}
}

int main()
{
	char ch;
	printf("��Ը�ⴴ��һ�ÿյĶ�������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		BNode_pioner root = NULL;
		Creat(root);
	}
	else {
		exit(-1);
	}
	return 0;
} 

//---------------------------------------------------------------------------
//ѯ�ʷ������������Լ���������ϰ
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode, *BNode_pioner;

void Creat(BNode_pioner& root) {
	char ch;
	root = (BNode_pioner)malloc(sizeof(BNode));
	printf("������ý���ֵ:\n");
	scanf("%c",& (root->data));
	getchar();
	printf("��Ը�ⴴ��%c����������?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->rchild = NULL;
	}
	printf("��Ը�ⴴ��%c����������?\n",root->data);
	scanf("%c",&ch);
	if ('Y' == ch) {
		Creat(root->rchild);
	}
	else {
		root->rchild = NULL;
	}
} 

int main()
{
	char ch;
	printf("��Ը�ⴴ��һ�ÿյĶ�������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch){
		BNode_pioner root;
		Creat(root);
	}
	else {
		exit(-1);
	}
	return 0;
}
//���շ����������� 
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode,*BNode_pioner;

void Creat(BNode_pioner& root) {
	printf("�밴ǰ������������룬��Ϊ�յĽ��Ļ���������'#'\n");
	char sign;
	scanf("%c",&sign);
	getchar();
	if ('#' == sign) {
		root = NULL;
	}
	else {
		root = (BNode_pioner)malloc(sizeof(BNode));
		root->data = sign;
		Creat(root->lchild);
		Creat(root->rchild);
	}
	
}

int main()
{
	char ch;
	printf("����Ҫ����һ�ÿյĶ�������?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		BNode_pioner root = NULL;
		Creat(root);
	}	
	else {
		exit(-1);
	}
	return 0;
}
�����������ϸ�ϰ
#include<stdio.h>
#include<stdlib.h>
void swap(int & a, int & b) {
	int t = a;
	a = b;
	b = t;	
}

int partation(int num[], int low, int high) {
	int i = low, j = high, pivot = num[low];
	while(i < j) {
		while(i < j && num[j] >= pivot) {
			j--;
		}
		if (i < j) {
			swap(num[i++], num[j]);	
		}
		while(i < j && num[i] < pivot) {
			i++;
		}
		if (i < j) {
			swap(num[j--], num[i]);
		}
	}
	return i;
}

void QuickSort(int num[], int low, int high) {
	if (low < high) {
		int mid = partation(num, low, high);
		QuickSort(num, low , mid);
		QuickSort(num, mid + 1, high);
	}	
}

int main()
{
	int num[10], i;
	printf("������ʮ������:\n");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	QuickSort(num, 0, 9);
	printf("�����\n");
	for(i = 0; i < 10; i++) {
		printf("%d	",num[i]);
	}
	return 0;
 } 
ѯ�ʷ�����������
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode,*BNode_pioner;

void Creat(BNode_pioner& root) {
	char ch;
	root = (BNode_pioner)malloc(sizeof(BNode));
	printf("������ý���ֵ:\n");
	scanf("%d",&root->data);
	getchar();
	printf("��Ը�ⴴ��%c����������?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}	
	printf("��Ը�ⴴ��%c����������?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->rchild);
	}
	else {
		root->rchild = NULL;
	}
}


int main()
{
	char ch;
	printf("���Ƿ�Ը�ⴴ��һ�ÿյĶ�����?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		BNode_pioner root = NULL;
		Creat(root);
	}
	else {
		exit(-1);
	}
	
	
	return 0;
} 









