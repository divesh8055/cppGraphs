//this code is for undirected graph

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cycleDetectionUsingDFS(vector<int>adj[], int node, int parent, vector<int>&visited)
{
    visited[node] = 1;
    for(auto it : adj[node])
    {
        if(!visited[it])
        {
            if(cycleDetectionUsingDFS(adj, it, node, visited))
                return true;
        }
        else if(it!=parent)
        {
            return true;
        }
    }
    return false;
}

int main(){

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
    //making a visited vector
    vector<int> visited(n, 0);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(cycleDetectionUsingDFS(adj,i,-1,visited))
            {
                cout<<"Cycle is present"<<endl;
            }
            else    
            {
                cout<<"Cycle is not present"<<endl;
            }
        }
    }
    return 0;
}