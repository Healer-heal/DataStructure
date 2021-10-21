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
//�������Ĵ����Լ�����
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
//	printf("������ýڵ��ֵ:\n");
//	scanf("%c",&root->data);
//	getchar();
//	printf("��Ը�ⴴ��%c����������?\n",root->data);
//	scanf("%c",&ch);
//	getchar();
//	if ('Y' == ch) {
//		Creat(root->lchild);
//	}
//	else {
//		root->lchild = NULL;
//	}
//	printf("��Ը�ⴴ��%c����������?\n",root->data);
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
//	printf("��Ը�ⴴ��һ�ÿյĶ�������?\n");
//	scanf("%c",&ch);
//	getchar();
//	if ('Y' == ch) {
//		exit(-1);
//	}
//	else {
//		Creat(root);
//	}
//	printf("ǰ�����:\n");
//	Preorder(root);
//	printf("\n");
//	printf("�������:\n");
//	Inorder(root);
//	printf("\n");
//	printf("�������:\n");
//	Postorder(root);
//	printf("\n");
//	return 0;
// } 
//���鼯
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
//int find(int u) {				//����Ĵ���д�ıȽϼ�࣬��һ���õ�ģ�� 
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
//	printf("���������������ݸ���:\n");
//	cin >> n >> m;
//	Init(n);
//	printf("�����������ݹ�ϵ�������˵ı��:\n");
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
//���鼯�ٴθ�ϰ
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
	printf("�������˵ĸ����Լ���ϵ����:\n");
	scanf("%d%d",&n,&m);
	Init(n);//��ʼ����������
	printf("�������й�ϵ�����������±�:\n");
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

