#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int> &visited)
{
    //printing the node which gets visited
    cout<<node<<" ";
    //marking node as visited
    visited[node] = 1;

    //going to the depth of the node
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            DFS(it, adj, visited);
        }
    }
}

int main(){
    //DFS - Depth First Search
    //We go to the depth first
    //We traverse till the lowest point first and then comes back
    //Time complexity - O(N+E)
    //Space Complexity - O(N+E)+O(N)+O(N)
    int n;
    cin>>n;

    //creating adjacency list
    vector<int>adj[n];

    //taking edge as input
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        //below is the implementation for undirected graph
        //for directed graphs we can omit the second line
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //passing the list into the DFS function
    //initializing a visited vector
    vector<int>visited(n,0);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            DFS(i, adj, visited);
    }
    return 0;
}