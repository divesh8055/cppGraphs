#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cycleDetectionUsingBFS(vector<int>adj[], int s, vector<int>&visited)
{
    //making a queue of pairs to store the node and its parent node
    queue<pair<int, int>> q;
    visited[s] = 1;
    //initially -1 is stored as parent for the source node
    q.push({s,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        //similar to BFS, we traverse for adjacent nodes and push it to queue if its not visited.
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if(parent!=it)
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
            if(cycleDetectionUsingBFS(adj,i,visited))
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