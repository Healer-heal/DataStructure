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
		printf("请输入该节点的值:\n");
		scanf("%c",&root->data);
		getchar();
		printf("你愿意创建%c的左子树吗?(Y/N)\n",root->data);
		scanf("%c",&check);
		getchar();
		if ( 'N' == check ) {
			root->lchild=NULL;
		}
		else {
			Creat(root->lchild);
		}
		printf("你愿意创建%c的右子树吗(Y/N)?\n",root->data);
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
	printf("你愿意创建一棵空二叉树吗?(Y/N)\n");
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
