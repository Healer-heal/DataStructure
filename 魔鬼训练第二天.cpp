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
	printf("请输入该节点的值:\n");
	scanf("%c",&root->data);
	getchar();
	printf("是否创建%c的左子树?(Y/N)\n",root->data);
	scanf("%c",&check);
	getchar();
	if ( 'Y' == check ) {
		Creat(root->lchild);
	}
	else {
		root->lchild=NULL;
	}
	printf("是否创建%c的右子树?(Y/N)\n",root->rchild);
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
	printf("你是否愿意创建一棵空树?(Y/N)\n");
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
