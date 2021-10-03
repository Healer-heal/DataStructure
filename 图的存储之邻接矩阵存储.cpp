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
	cout <<"������ͼ�н��ĸ����ͱߵ�����" << endl;
	cin >> 	G.vexnum >> G.edgenum;
	cout << "������ͼ�н�����Ϣ" << endl;
	for(i = 0; i < G.vexnum; i++) {
		cin >> G.Venum[i];
	}
	for(i = 0; i < G.vexnum; i++) {
		for(j = 0; j < G.vexnum; j++) {
			G.Edge[i][j] = 0;
		}
	}
	cout << "������ÿ���߹���������������Ϣ:" << endl;
	while(G.edgenum--) {
		cin >> u >> n;
		i = vexlocation(G,u);
		j = vexlocation(G,n);
		if (i != -1 && j != -1) {
			G.Edge[i][j] = G.Edge[j][i] = 1;
		}
		else {
			cout << "����Ľ����Ϣ��������������" << endl;
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
