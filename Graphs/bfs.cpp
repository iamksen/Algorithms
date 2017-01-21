#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define rep(i, a, b) for(int i = int(a); i <  int(b); i++)
#define TRvi(c, it)  for(vi::iterator  it = (c).begin(); it != (c).end(); it++ )

#define pb push_back
#define INF 1000000000 //1e9
int n, e, start; //vertices, edges
vector < vi > graph;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	vector<bool> used(n+1, false);
	vi d(n+1, INF), p(n+1, -1); //distance , parent vector
	used[start] = true;
	d[start] = 0;
	p[start] = -1;

	cout<<"BFS"<<endl;
	while( !q.empty() ){
		int i, v = q.front();
		q.pop();
		cout<<v<<" ";
		rep(i, 0, graph[v].size()){
			int to = graph[v][i];
			if( !used[to] ){
				q.push(to);
				used[to] = true;
				d[to] = d[v] + 1;
				p[to] = v; //parent of 'to' is v
			}
		}
	}
	cout<<endl;

	//To print path, replace end with finish node		
	int end = 1;
	if(!used[end])
		cout<<"No path from "<<start<<" to "<<end<<endl;
	else {
		vi path;
		int i = end;
		while( i != -1){
			path.pb(i);
			i = p[i];
		}
		reverse(path.begin(), path.end() );
		cout<<"Path from "<<start<<" to "<<end<<endl;
		for(i = 0; i < path.size(); i++)
			cout<<path[i]<<" ";
		cout<<endl;
	}
}
int main(int argc, char const *argv[]) {
	int i, u, v;
	cin>>n>>e;
	graph.resize(n+1);
	graph.clear();
	//taking input in the form u->v
	REP(i, 1, e){
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u); //undirected graph
	}
	cin>>start;
	bfs(start);
	return 0;
}
