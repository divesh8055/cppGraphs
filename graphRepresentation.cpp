#include<bits/stdc++.h>
using namespace std;

int main() {
	//n is the number of nodes
	//m is the number of edges 
	//this is the representation in adjacency matrix form
	//space complexity for undirected = O(N*N) and for directed = O(N*N)
	int n,m;
	cin>>n>>m;

	//declaring the adjacency matrix
	int adj[n+1][m+1];

	//take edges as input
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}

	//this is the representation in adjacency list form
	//space complexity for undirected = O(N+2E) and for directed = O(N+E)
	//please use the commented code
	/*
	//n is the number of nodes
	int n;
	cin>>n;

	//here we are creating an array of vectors
	vector<int>adj[n+1];

	//take edges as input
	for(int i=0; i<n; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
	*/

	//in case of edge weights, we are going to store it as array of vector of pairs.
	return 0;
}


