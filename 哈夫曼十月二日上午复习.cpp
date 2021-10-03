#include <iostream>
#include <string>
#define MAXLEAF 30
#define MAXNODE 2 * MAXLEAF - 1
#define MAXBIT 100
#define MAXWEIGHT 9999
using namespace std;
typedef struct {
	int weight;
	int val;
	int parent;
	int lchild;
	int rchild;
}HFnodeType;

typedef struct {
	int bit[MAXBIT];
	int start;
}HFcodeType;

HFnodeType HFnode[MAXNODE];
HFcodeType HFcode[MAXLEAF];

void HuffmanTree(HFnodeType HFnode[MAXNODE], int n) {
	int i, x1, x2, j;
	double m1, m2;
	m1 = m2 = MAXWEIGHT;
	for(i = 0; i < n; i++) {
		HFnode[i].lchild = -1;
		HFnode[i].parent = -1;
		HFnode[i].rchild = -1;
		HFnode[i].weight = 0;
	}
	cout << "Please input the value and weight of the leaf" << endl;
	for(i = 0; i < n; i++) {
		cin >> HFnode[i].val >> HFnode[i].weight;
	}
	
	for(i = 0; i < n - 1; i++) {
		m1 = m2 = MAXWEIGHT;
		x1 = x2 = 0;
		for(j = 0; j < n + i; j++) {
			if (HFnode[j].weight < m1 && HFnode[j].parent == -1) {
				m2 = m1;
				x2 = x1;
				m1 = HFnode[j].weight;
				x1 = j;
			}
			else if (HFnode[j].weight < m2 && HFnode[j].parent == -1) {
				m2 = HFnode[j].weight;
				x2 = j;
			}
		}
		HFnode[x1].parent = n + i;
		HFnode[x2].parent = n + i;
		HFnode[n + i].weight = m1 + m2;
		HFnode[n + i].lchild = x1;
		HFnode[n + i].rchild = x2;
	}
}

void HuffmanCode(HFcodeType HFcode[MAXLEAF],int n) {
	HFcodeType cd;
	cd.start = n - 1;
	int i, c, p, j;
	for(i = 0; i < n; i++) {
		c = i;
		p = HFnode[c].parent;
		while(p != -1) {
			if (HFnode[p].lchild == c) {
				cd.bit[cd.start] = 0;
			}
			else {
				cd.bit[cd.start] = 1;
			}
			cd.start--;
			c = p;
			p = HFnode[p].parent;
		}
		for(j = cd.start + 1; j < n; j++) {
			HFcode[i].bit[j] = cd.bit[j];
		}
		HFcode[i].start = cd.start;
	}
	
	
	
}

int main()
{
	int n;
	cout << "Please input the number of the leaf" << endl;
	cin >> n;
	HuffmanTree(HFnode,n);
	HuffmanCode(HFcode,n);	
	return 0;
}
