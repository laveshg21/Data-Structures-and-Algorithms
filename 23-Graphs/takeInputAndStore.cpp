#include<iostream> 
using namespace std;

int main(){

	// n = #nodes, e = #edges
	int n = 0 , e = 0; 
	cin >> n >> e;
	// By default we'll keep nodes as 0, 1, ...., n-1

	/*************************************************************************/
	// Method 1.1 : Create Adjacency Matrix 'edges' dynamically and initialise 
	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++){
			edges[i][j] = 0;
		}  
	} // O(n^2) space

	// Fill adjacency matrix --- fn = first node, sn = second node
	for(int k = 0; k < e; k++){ // O(n) time 
		int fn = 0, sn = 0;
		cin >> fn >> sn;
		edges[fn][sn] = 1;
		edges[sn][fn] = 1;
	}
	/*************************************************************************/
	// Method 1.2 : Create adjacency matrix statically
	int adj[n+1][n+1];

	// Fill adjacency matrix 
	for(int i=0; i < e; i++){
		int f,s;
		cin >> f >> s; 
		adj[f][s] = 1;
		adj[s][f] = 1; 
	}
	/*************************************************************************/
	// Method 2: Adjacency List
	// O(2e) space

	vector<int> adj[n+1];
	for(int k = 0; k < e; k++){ // O(n) time 
		int u = 0, v = 0;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		/*
		if directed graph u --> v
		then only do adj[u].push_back(v); 
		Space: O(e)
		*/
	}


	return 0; 
}

/* Edge bw 4 and 3
7 7 
0 1                   0
1 5                  / \
5 4                 1   2
4 3                 |   | \
3 2                 5   3  6 
2 0                  \ /
2 6                   4     
*/


/* NO Edge bw 4 and 3 
7 6 
0 1
1 5 
5 4
3 2
2 0
2 6 
*/
