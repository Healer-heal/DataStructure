#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode {
	char data;
	struct Bnode* lchild;
	struct Bnode* rchild; 
}Bnode,*Bnode_pioner;

void Creat(Bnode_pioner &root ) {
	char check;
	root=(Bnode_pioner)malloc(sizeof(Bnode));
	printf("������ýڵ��ֵ:\n");
	scanf("%c",&root->data);
	getchar();
	printf("�Ƿ񴴽�%c��������?(Y/N)\n",root->data);
	scanf("%c",&check);
	getchar();
	if ( 'Y' == check ) {
		Creat(root->lchild);
	}
	else {
		root->lchild=NULL;
	}
	printf("�Ƿ񴴽�%c��������?(Y/N)\n",root->rchild);
	scanf("%c",&check);
	if ( 'Y' == check ) {
		Creat(root->rchild);
	}
	else {
		root->rchild=NULL;
	}
	
}

int main()
{
	char sign;
	printf("���Ƿ�Ը�ⴴ��һ�ÿ���?(Y/N)\n");
	scanf("%c",&sign);
	getchar();
	if ( 'N' == sign ) {
		exit(-1);
	}
	else {
		Bnode_pioner root = NULL;
		Creat(root);
	}
	
	return 0;
}
