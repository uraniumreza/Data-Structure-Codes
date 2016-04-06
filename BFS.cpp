#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NIL -1
#define INF 1000

int Node,Edge;
int matrix[100][100];
int color[100];
int Distance[100];
int parent[100];

void BFS(int source)
{
	for(int i=0;i<Node;i++){
		color[i] = WHITE;
		Distance[i] = INF;
		parent[i] = NIL;
	}

	color[source] = GRAY;
	Distance[source] = 0;
	parent[source] = NIL;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty())
	{
		int v;
		int u = Q.front();
		Q.pop();
		for(int v=0;v<Node;v++)
		{
			if(matrix[u][v] == 1 && color[v] == WHITE){
				color[v] = GRAY;
				Distance[v] = Distance[u] + 1;
				cout<<"v: "<<v<<" Distance: "<<Distance[v]<<endl;
				parent[v] = u;
				Q.push(v);
			}
		}
		color[u] = BLACK;
	}
}

void PrintPath(int src, int dest)
{
	if(src == dest){
		cout<<src<<" ";
		return;
	}
	else if(parent[dest]==NIL) cout<<"No path From "<<src<<" to "<<dest<<endl;
	else PrintPath(src, parent[dest]);
	cout<<dest<<" ";
}



int main()
{
	cout<<"How many Nodes and Edges: "; cin>>Node>>Edge;

	for(int i=0;i<Node;i++){
		for(int j=0;j<Node;j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0;i<Edge;i++)
	{
		int n1,n2,cost;
		scanf("%d%d%d",&n1,&n2,&cost);
		matrix[n1][n2] = cost;			// jodi graph ta unweighted hoy tahole just 1
		matrix[n2][n1] = cost;
	}

	cout<<"Insert source and Destination: ";
	int src, dest;
	cin>>src>>dest;
	
	BFS(src);

	cout<<"Path: ";
	PrintPath(src, dest);
	cout<<endl;


	if(Distance[dest]!=INF) cout<<"Path Length: "<<Distance[dest]<<endl;
	else cout<<"No possible paths from this source to destination!"<<endl;


	return 0;
}