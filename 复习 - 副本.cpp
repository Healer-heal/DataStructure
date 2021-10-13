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
	printf("请输入十个数字:\n");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	
	QuickSort(num, 0, 9);
	printf("排序后:\n");
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
	printf("请输入十个数字：");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	QuickSort(num,0,9);
	printf("排序后:\n"); 
	for(i = 0; i < 10; i++) {
		printf("%d	",&num[i]);
	}
	return 0;
}


//询问法创建二叉树(复习)
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
	printf("请输入该结点的值:\n");
	scanf("%c",&value);
	getchar();
	p->data = value;
	printf("是否愿意创建%c的左孩子?\n",p->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(p->lchild);
	}
	else {
		p->lchild = NULL;
	}
	printf("是否愿意创建%c的右孩子？\n",p->data);
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
	printf("是否愿意创建一棵空树?\n");
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
//询问法创建二叉树(再次复习)
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
	printf("请输入该节点的值:\n");
	scanf("%c",&ch);
	getchar();
	root->data = ch;
	printf("你愿意创建%c的左子树吗?\n");
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}
	printf("你愿意创建%c的右子树吗?\n");
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
	printf("你愿意创建一棵空的二叉树吗?\n");
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
//询问法创建二叉树
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
	printf("请输入该结点的值:\n");
	scanf("%c",value);
	getchar();
	root->data = value;
	printf("是否愿意创建%c的左子树?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}
	printf("是否愿意创建%c的右子树?\n");
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
	printf("你愿意创建一棵空的二叉树吗?\n");
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
//询问法创建二叉树以及快速排序复习
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
	printf("请输入该结点的值:\n");
	scanf("%c",& (root->data));
	getchar();
	printf("你愿意创建%c的左子树吗?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->rchild = NULL;
	}
	printf("你愿意创建%c的右子树吗?\n",root->data);
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
	printf("你愿意创建一棵空的二叉树吗?\n");
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
//补空法创建二叉树 
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BNode {
	ElemType data;
	struct BNode* lchild;
	struct BNode* rchild;
}BNode,*BNode_pioner;

void Creat(BNode_pioner& root) {
	printf("请按前序遍历序列输入，若为空的结点的话，则输入'#'\n");
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
	printf("你想要创建一棵空的二叉树吗?\n");
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
快速排序晚上复习
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
	printf("请输入十个数字:\n");
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}
	QuickSort(num, 0, 9);
	printf("排序后：\n");
	for(i = 0; i < 10; i++) {
		printf("%d	",num[i]);
	}
	return 0;
 } 
询问法创建二叉树
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
	printf("请输入该结点的值:\n");
	scanf("%d",&root->data);
	getchar();
	printf("你愿意创建%c的左子树吗?\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->lchild);
	}
	else {
		root->lchild = NULL;
	}	
	printf("你愿意创建%c的右子树吗?\n",root->data);
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
	printf("你是否愿意创建一棵空的二叉树?\n");
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









