#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode {
	char data;
	struct Bnode* lchild;
	struct Bnode* rchild;
}Bnode,*Bnode_pioner;

void Creat(Bnode_pioner &root) {
		char check; 
		root=(Bnode_pioner)malloc(sizeof(Bnode));
		printf("������ýڵ��ֵ:\n");
		scanf("%c",&root->data);
		getchar();
		printf("��Ը�ⴴ��%c����������?(Y/N)\n",root->data);
		scanf("%c",&check);
		getchar();
		if ( 'N' == check ) {
			root->lchild=NULL;
		}
		else {
			Creat(root->lchild);
		}
		printf("��Ը�ⴴ��%c����������(Y/N)?\n",root->data);
		scanf("%c",&check);
		if ( 'N' == check ) {
			root->rchild=NULL;
		}
		else {
			Creat(root->rchild);
		}
}

int main()
{
	char check;
	Bnode_pioner root=NULL;
	printf("��Ը�ⴴ��һ�ÿն�������?(Y/N)\n");
	scanf("%c",&check);
	getchar();
	if ( 'N' == check ) {
		exit(-1);
	}
	else {
		Creat(root);
	}
	
	return 0;
}
