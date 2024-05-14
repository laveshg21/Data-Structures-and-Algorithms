#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
WEIGHTED DIRECTED ACYCLIC GRAPH
                     2
				1 ------> 2 -----
				^         ^     |
				| 1     3 |     | 7
				|         |     v
				3 <------ 4 --> 5
                      2      2 
5 6
1 2 2
2 5 7
3 1 1
4 3 2
4 2 3
4 5 2 

*/
int main(){

	// n = #nodes, e = #edges
	int n = 0 , e = 0; 
	cin >> n >> e;

	/*************************************************************************/
	// Method 1: Create adjacency matrix statically
	int adj_mat[n+1][n+1];
	for(int i=0; i<n+1; i++){
		for(int j=0; j<n+1; j++){
			adj_mat[i][j] = 0;
		}
	}

	// Fill adjacency matrix 
	for(int i=0; i < e; i++){
		int node1, node2, wt;
		cin >> node1 >> node2 >> wt; 
		adj_mat[node1][node2] = wt;
	}

	for(int i=0; i<n+1; i++){
		for(int j=0; j<n+1; j++){
			cout << adj_mat[i][j] << " ";
		}
		cout << endl; 
	}

	/*************************************************************************/
	// Method 2: Adjacency List
	// O(2e) space

	map<int, vector<pair<int,int>>> adj_list[n+1]; 
	// vector<pair<int, int>> adj_list[n+1];
	for(int k = 0; k < e; k++){ // O(n) time 
		int u = 0, v = 0, wt =0;
		cin >> u >> v >> wt;
		adj_list[u].push_back({v,wt});
	}

	for (const auto& entry : adj_list) {
        int node = entry.first;
        const vector<pair<int, int>>& neighbors = entry.second;

        cout << node << ": ";
        for (const auto& edge : neighbors) {
            cout << "{" << edge.first << "," << edge.second << "}, ";
        }
        cout << endl;
    }


	return 0; 
}