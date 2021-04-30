#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(int n, vector<int> adj[])
{
    //initializing a visited vector
    vector<int> visited(n+1, 0);
    //for disconnected components, we are checking for each node.
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty())
            {
                //capturing the top node and printing it
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                //checking every element adjacent to node and pushing it to queue
                for(auto it: adj[node])
                {
                    if(!visited[it])
                        q.push(it);
                        //marking the pushed node as visited in visited vector
                        vis[it]=1;
                }
            }
        }
    } 

}

int main(){
    //BFS - Breadth First Search
    //We go layer by layer
    //We traverse adjacent nodes first and then move down
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
    //passing the list into the BFS function
    BFS(n ,adj)
    return 0;
}