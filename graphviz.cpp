#include <fstream>

void generateGraphviz(int** edges, int n) {
    ofstream dotFile("graph.dot");
    if (!dotFile.is_open()) {
        cout << "Error creating Graphviz file." << endl;
        return;
    }

    dotFile << "graph G {" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (edges[i][j] == 1) {
                dotFile << i << " -- " << j << ";" << endl;
            }
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
}

generateGraphviz(edges, n);