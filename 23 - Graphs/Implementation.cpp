#include<iostream>
#include<queue> 
using namespace std;

/* once we go in a direction, we keep going into
 that direction till we can go in that direction
 Depth First Search */

void print_dfs(int** edges, int n, bool* isVisited, int sv){
	cout << sv << endl;
	isVisited[sv] = true;

	for(int i = 0; i < n; i++){
		if (i == sv) {
			continue;
		}
		if(edges[sv][i] == 1){
			if(isVisited[i]){
				continue;
			}
			print_dfs(edges, n, isVisited, i);
		}
	}

}

void print_bfs(int** edges, int n, bool* isVisited, int sv){
	queue<int> pendingV;
	pendingV.push(sv); 
	isVisited[sv] = true;
	while(!pendingV.empty()){
		int currV = pendingV.front();
		pendingV.pop();
		cout << currV << endl; 

		for(int i=0; i < n; i++){
			if(i ==currV){
				continue; 
			}
			if(edges[currV][i] && !isVisited[i]){
				pendingV.push(i);
				isVisited[i] = true; 
			}
		}
	} 
}

int main(){

	// n = #nodes, e = #edges
	int n = 0 , e = 0; 
	cin >> n >> e;
	// By default we'll keep nodes as 0, 1, ...., n-1

	// Create Adjacency Matrix 'edges' and initialise 
	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++){
			edges[i][j] = 0;
		}  
	}

	// Fill adjacency matrix 
	for(int k = 0; k < e; k++){
		int fn = 0, sn = 0;
		cin >> fn >> sn;
		edges[fn][sn] = 1;
		edges[sn][fn] = 1;
	}

	// Create and Initialise isVisited
	bool* isVisited = new bool[n];
	for(int l = 0; l < n; l++){
		isVisited[l] = false; 
	}

	// print_dfs(edges, n, isVisited, 0);
	print_bfs(edges, n, isVisited, 0);

	// DELETE ALL THE MEMORY 
	// Delete the adjacency matrix
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    // Delete the isVisited array
    delete[] isVisited;

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
