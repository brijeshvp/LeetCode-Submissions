// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,int clr,bool g[][101],int m,int n,vector<int>&color){
    // g is adj matrix -> so adj nodes of node are (node)th row numbers
    for(int nodes=0;nodes<n;++nodes){
        if(nodes!=node && g[node][nodes]==1 && color[nodes]==clr)return false;
    }
    return true;
}

bool solve(int node,bool g[][101],int m,int n,vector<int>&color){
    // BC
    if(node == n)return true;   // all nodes have been successfully colored
    
    for(int clr=1;clr<=m;++clr){
        if(isSafe(node,clr,g,m,n,color)){
            color[node] = clr;
            if(solve(node+1,g,m,n,color))return true;
            color[node] = 0;
        }
    }
    return false;   // if this node cannot be colored with any of the m colors
}

bool graphColoring(bool g[101][101], int m, int n) {
    vector<int> color(n,0);
    return solve(0,g,m,n,color);
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