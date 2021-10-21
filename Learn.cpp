////QuickSort
//#include<stdio.h>
//#include<stdlib.h>
//
//void swap(int& a, int& b) {
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
//			i++;
//		}
//		if (i < j) {
//			swap(num[i],num[j--]);
//		}
//	}
//	return i;
//}
//
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
//	printf("Afer sort:\n");
//	for(i = 0; i < 10; i++) {
//		printf("%d	",num[i]);
//	}
//	return 0;
//}
//二叉树的创建以及遍历
//#include<stdio.h>
//#include<stdlib.h>
//typedef char ElemType;
//typedef struct BNode {
//	ElemType data;
//	struct BNode* lchild;
//	struct BNode* rchild;
//}BNode,*BNode_pioner;
//
//void Creat(BNode_pioner& root) {
//	char ch;
//	root = (BNode*)malloc(sizeof(BNode));
//	printf("请输入该节点的值:\n");
//	scanf("%c",&root->data);
//	getchar();
//	printf("你愿意创建%c的左子树吗?\n",root->data);
//	scanf("%c",&ch);
//	getchar();
//	if ('Y' == ch) {
//		Creat(root->lchild);
//	}
//	else {
//		root->lchild = NULL;
//	}
//	printf("你愿意创建%c的右子树吗?\n",root->data);
//	scanf("%c",&ch);
//	getchar();
//	if ('Y' == ch) {
//		Creat(root->rchild);
//	} 
//	else {
//		root->rchild = NULL;
//	}
//}
//
//void Preorder(BNode_pioner root) {
//	if (root) {
//		printf("%c	",root->data);
//		Preorder(root->lchild);
//		Preorder(root->rchild);
//	}
//}
//
//void Inorder(BNode_pioner root) {
//	if (root) {
//		Inorder(root->lchild);
//		printf("%c	",root->data);
//		Inorder(root->rchild);
//	}
//}
//
//void Postorder(BNode_pioner root) {
//	if (root) {
//		Postorder(root->lchild);
//		Postorder(root->rchild);
//		printf("%c	",root->data);
//	}
//}
//
//int main()
//{
//	char ch;
//	BNode_pioner root = NULL;
//	printf("你愿意创建一棵空的二叉树吗?\n");
//	scanf("%c",&ch);
//	getchar();
//	if ('Y' == ch) {
//		exit(-1);
//	}
//	else {
//		Creat(root);
//	}
//	printf("前序遍历:\n");
//	Preorder(root);
//	printf("\n");
//	printf("中序遍历:\n");
//	Inorder(root);
//	printf("\n");
//	printf("后序遍历:\n");
//	Postorder(root);
//	printf("\n");
//	return 0;
// } 
//并查集
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
//#define N 100
//using namespace std;
//int father[N];
//void Init(int n) {
//	for(int i = 1; i <= n; i++) {
//		father[i] = i;
//	}		
//}
//
//int find(int u) {				//这里的代码写的比较简洁，是一个好的模板 
//	if (u != father[u]) {
//		father[u] = find(father[u]);
//	}
//	return father[u];
//}
//
//void Merge(int u, int v) {
//	int num1 = find(u);
//	int num2 = find(v);
//	if (num1 < num2) {
//		father[num2] = num1;
//	}
//	else if (num1 > num2) {
//		father[num1] = num2;
//	}
//}
//
//int main()
//{
//	int n ,m, u, v, sum = 0;
//	printf("请输入人数和亲戚个数:\n");
//	cin >> n >> m;
//	Init(n);
//	printf("请输入有亲戚关系的两个人的编号:\n");
//	for(int i = 0; i < m; i++) {
//		scanf("%d%d",&u,&v);
//		Merge(u,v);
//	}
//	for(int i = 1; i <= n; i++) {
//		find(i);
//	}
//	for(int i = 1; i <= n; i++) {
//		cout << father[i] <<"	";
//		if (father[i] == i) {
//			sum++;
//		}
//	}
//	printf("\n");
//	cout << "sum =	" << sum << endl;
//	return 0;
// } 
//并查集再次复习
#include<stdio.h>
#define N	100
int father[N];

void Init(int n) {
	for(int i = 1; i <= n; i++) {
		father[i] = i;
	}
}

int find(int n) {
	if (n != father[n]) {
		father[n] = find(father[n]);
	}
	return father[n];
}

void Merge(int u, int v) {
	int num1 = find(u);
	int num2 = find(v);
	if (num1 < num2) {
		father[num2] = num1;
	}
	else if (num1 > num2) {
		father[num1] = num2;
	}
}

int main()
{
	int n, m, u, v, sum = 0;	
	printf("请输入人的个数以及关系个数:\n");
	scanf("%d%d",&n,&m);
	Init(n);//初始化父亲数组
	printf("请输入有关系的两个结点的下标:\n");
	for(int i = 1; i <= m; i++) {
		scanf("%d%d",&u,&v);
		Merge(u,v);
	} 
	for(int i = 1; i <= n; i++) {
		find(i);
		printf("%d	",father[i]);
		if (i == father[i]) {
			sum++;
		}
	}
	printf("\n");
	printf("%d\n",sum);
	return 0;
} 

