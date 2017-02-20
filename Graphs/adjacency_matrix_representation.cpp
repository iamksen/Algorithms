/* Undirected graph */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int V, E, u, v, w;
	cout<<"Enter no of vertices ";
	cin>>V;
	cout<<"Enter no of edges ";
	cin>>E;
	int graph[V+1][V+1];
	for(int i = 0 ; i <= V; i++)
		for(int j = 0 ; j <= V; j++)
			graph[i][j] = 0;

	for(int i = 0; i < E; i++){
		cin>>u>>v>>w; //start end weight;
		graph[u][v] = w;
		graph[v][u] = w;
	}
	//print graph; V starts from 1
	cout<<"Adjacency Matrix of graph\n";
	for(int i = 1 ; i <= V; i++){
		for(int j = 1; j <= V; j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
