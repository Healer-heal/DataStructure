////QuickSort
//#include<stdio.h>
//void swap(int& a, int& b) {
//	int t = a;
//	a = b;
//	b = t;	
//}
//
//int Partation(int num[], int left, int right) {
//	int i = left, j = right, pivot = num[left];
//	while (i < j) {
//		while(i < j && num[j] >= pivot) {
//			j--;
//		}
//		if (i < j) {
//			swap(num[i++], num[j]);
//		}
//		while(i < j && num[i] < pivot) {
//			i++;
//		}
//		if (i < j) {
//			swap(num[i], num[j--]);
//		}
//	}
//	return i;
//}
//
//void QuickSort(int num[], int left, int right) {
//	if (left < right) {
//		int mid = Partation(num, left, right);
//		QuickSort(num,0,mid);
//		QuickSort(num, mid + 1, right);
//	}
//}
//
//int main()
//{
//	int num[10], i;
//	printf("Please input ten numbers:\n");
//	for(i = 0; i < 10; i++) {
//		scanf("%d",&num[i]);
//	}
//	QuickSort(num,0,9);
//	printf("After sort:\n");
//	for(i = 0; i < 10; i++) {
//		printf("%d	",num[i]);
//	}
//	return 0;
//}
//Again
//#include<stdio.h>
//
//int swap(int& a, int& b) {
//	int t = a;
//	a = b;
//	b = t;
//}
//
//int Partation(int num[], int left, int right) {
//	int i = left, j = right, pivot = num[left];
//	while(i < j) {
//		while(i < j && num[j] >= pivot) {
//			j--;
//		}
//		if (i < j) {
//			swap(num[i++], num[j]);
//		}
//		while(i < j && num[i] < pivot) {
//			swap(num[j--],num[i]);
//		}
//	}
//	return i;
//}
//
//void QuickSort(int num[], int left, int right) {
//	if (left < right) {
//		int mid = Partation(num, left, right);
//		QuickSort(num, 0, mid);
//		QuickSort(num, mid + 1, right);
//	}
//}
//
//int main()
//{
//	int num[10], i;	
//	printf("Please input ten numbers:\n");
//	for(i = 0; i < 10; i++) {
//		scanf("%d",&num[i]);
//	}
//	QuickSort(num, 0, 9);
//	printf("After sort:\n");
//	for(i = 0; i < 10; i++) {
//		printf("%d	",num[i]);
//	}
//	return 0;
//}
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
	printf("请输入该节点的值:\n");
	scanf("%c",&root->data);
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
	printf("你愿意创建%c的右子树吗\n",root->data);
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(root->rchild);
	}
	else {
		root->rchild = NULL;
	}
}

void Preorder(BNode_pioner root) {
	if (root) {
		printf("%c	",root->data);	
		Preorder(root->lchild);
		Preorder(root->rchild);
	}
}

void Inorder(BNode_pioner root) {
	if (root) {
		Inorder(root->lchild);
		printf("%c	",root->data);
		Inorder(root->rchild);
	}
}

void Postorder(BNode_pioner root) {
	if (root) {
		Postorder(root->lchild);
		Postorder(root->rchild);
		printf("%c	",root->data);
	}
}

int main()
{
	char ch;
	BNode_pioner p = NULL;
	printf("你愿意创建一棵二叉树吗?\n");	
	scanf("%c",&ch);
	getchar();
	if ('Y' == ch) {
		Creat(p);
	}
	else {
		exit(-1);
	}
	
	printf("前序遍历:\n");
	Preorder(p);
	printf("\n");
	
	printf("中序遍历:\n");
	Inorder(p);
	printf("\n");
	
	printf("后序遍历:\n");
	Postorder(p);
	printf("\n");
	
	return 0;
}
