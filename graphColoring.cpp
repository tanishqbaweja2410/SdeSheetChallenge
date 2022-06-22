// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
// TC: O(m ^ n) bcoz m * m * m * m * m......n times
// SC: O(n) + Aux Stack Space of O(n)
bool isColourPossible(int colour, bool graph[101][101], int node, vector<int> &nodeColour, int n) {
    for(int k = 0; k < n; k++) {
        if(k != node and graph[k][node] == 1 and nodeColour[k] == colour) return false;
    }
    return true;
}
bool helpSolveGraphColoring(int node, bool graph[101][101], int m, int n, vector<int> &nodeColour) {
    if(node == n) {
        return true;
    }
    
    for(int colour = 1; colour <= m; colour++) {
        if(isColourPossible(colour, graph, node, nodeColour, n)) {
            nodeColour[node] = colour;
            if(helpSolveGraphColoring(node + 1, graph, m, n, nodeColour)) {
                return true;
            }
            nodeColour[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> nodeColour(n, 0); 
    bool ans = helpSolveGraphColoring(0, graph, m, n, nodeColour);
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends