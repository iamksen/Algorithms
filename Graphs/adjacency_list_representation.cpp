#include <vector>
#include <list>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
	int vertices, edges, from, to, weight;
	cout<<"Enter no of vertices ";
	cin>>vertices;

	cout<<"Enter no of edges";
	cin>>edges;

	vector< list< pair <int, int> > > graph( vertices + 1);

	cout<<"Enter edge, from->to and its weight ";
	for(int i = 0 ; i < edges ; i++){
		cin>>from>>to>>weight;
		graph[from].push_back( make_pair(to, weight) );
	}

	cout<<"Adjacency graph ->"<<endl;
	list < pair<int, int> > :: iterator it;
	for(int i = 0 ; i < graph.size(); i++){
		cout<<"AdjacencyList["<<i<<"]";
		for( it = graph[i].begin(); it != graph[i].end(); it++ )
			cout<<" ->"<<(*it).first<<"("<<(*it).second<<")";
		cout<<endl;
	}
}