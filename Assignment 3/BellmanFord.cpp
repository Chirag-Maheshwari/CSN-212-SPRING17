#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0)

using namespace std;

struct edge
{    
	int src, dest, wt;
};

void bellmanFord(const edge edges[], int, int[], int, int);

int main() 
{
    faster;
    int n,e; 
    cin>> n >> e; //n,e=no of nodes,edges
    int src; 
    cin >> src;
    edge edges[e];
    int ar[n]; //to store min wt

    for(int i=0; i<e; i++) 
    {
        cin>> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    bellmanFord(edges, e, ar, n, src);
    return 0;
}

void bellmanFord(const edge edges[], int e, int ar[], int n, int src) 
{
    for(int i=0; i<n; i++)
        ar[i]=INT_MAX;

    ar[src]=0;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<e; j++) 
        {
            if(ar[edges[j].src]+edges[j].wt<ar[edges[j].dest])
                ar[edges[j].dest]=ar[edges[j].src]+edges[j].wt;
        }
    }

    for(int i=0; i<e; i++) 
    {
        if(ar[edges[i].src]+edges[i].wt<ar[edges[i].dest]) 
        {
            cout<<"Negative cycle present"<<endl;
        }
    }
    cout<<"Minimum costs to various nodes from vertex- "<<src<<endl;
    cout<<"Vertex"<<" Cost"<<endl;
    for(int i=0; i<n; i++) 
    {
        cout<<i<<"     "<<ar[i]<<endl;
    }
}