#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 505, maxe = 100001;
int n, m, cnt;
int head[maxn];

struct node {
	int to, next, w;
}edge[maxe];

void add(int u, int v, int w) {
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];//好好理解这行代码和下一行代码 
	head[u] = cnt++;//好好理解这两行代码，并且注意cnt的妙用 
}

void printing() {
	for(int u = 1; u <= n; u++) {
		cout << u << " ";
		for(int i = head[u]; i != -1; i = edge[i].next) {
			cout << "---" << i << ":(" << edge[i].to << edge[i].w << "	" << edge[i].next << ")";
			cout << endl;
		}
	}
}
0
int main()
{
	cin >> n >> m;
	cnt = 0;
	memset(head,-1,sizeof(head)); 
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	printing();
	return 0;
}