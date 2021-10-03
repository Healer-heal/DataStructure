#include<iostream>
using namespace std;

#define MaxVenum 100
typedef char VexType;
typedef int EdgeType;
typedef struct {
	VexType Venum[MaxVenum];
	EdgeType Edge[MaxVenum][MaxVenum];
	int vexnum, edgenum;
}AMGraph;

int vexlocation(AMGraph G,VexType num) {
	int i;
	for(i = 0; i < G.vexnum; i++) {
		if (G.Venum[i] == num) {
			return i;
		}
	}	
	return -1;
}

void CreatAMGraph(AMGraph G) {
	int i, j;
	VexType u, n;
	cout <<"请输入图中结点的个数和边的条数" << endl;
	cin >> 	G.vexnum >> G.edgenum;
	cout << "请输入图中结点的信息" << endl;
	for(i = 0; i < G.vexnum; i++) {
		cin >> G.Venum[i];
	}
	for(i = 0; i < G.vexnum; i++) {
		for(j = 0; j < G.vexnum; j++) {
			G.Edge[i][j] = 0;
		}
	}
	cout << "请输入每条边关联的两个结点的信息:" << endl;
	while(G.edgenum--) {
		cin >> u >> n;
		i = vexlocation(G,u);
		j = vexlocation(G,n);
		if (i != -1 && j != -1) {
			G.Edge[i][j] = G.Edge[j][i] = 1;
		}
		else {
			cout << "输入的结点信息有误，请重新输入" << endl;
			G.edgenum++; 
		}
	}
}

void print(AMGraph G) {
	int i, j;
	for(i = 0; i < G.vexnum; i++) {
		for( j = 0; j < G.vexnum; j++) {
			cout << G.Edge[i][j] << "\t";
		}
		cout << endl;
	}	
}

int main()
{
	AMGraph G;
	CreatAMGraph(G);
	print(G);
	return 0;
}
