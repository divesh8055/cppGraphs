#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int source, vector<int>adj, int color[])
{
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                color[it] = 1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) //checking if both have same color or not
                return false;
        }
    }
    return true;
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
    int color[n];
    memset(color, -1, sizeof(color));
    for(int i=0; i<n; i++)
    {
        if(color[i]==-1)
        {
            if(!checkBipartite(i, adj, color))
                cout<<"No"<<endl;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}