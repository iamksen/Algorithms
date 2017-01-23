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
vi used;
void dfs(int v)
{
	cout<<v<<" ";
	used[v] = true;
	for( vi ::iterator it = graph[v].begin(); it != graph[v].end(); it++){
		if( !used[*it])
			dfs(*it);
	}
}
int main(int argc, char const *argv[]) {
	int i, u, v;
	cin>>n>>e;
	graph.resize(n+1);
	used.resize(n+1);
	used.clear();
	graph.clear();
	//taking input in the form u->v
	REP(i, 1, e){
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u); //undirected graph
	}
	cin>>start;
	dfs(start);
	return 0;
}
