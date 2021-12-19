#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int countFactor(int n)
{
    int count=0;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
            count+=1;
                // printf("%d ", i);

            else // Otherwise print both
            count+=2;
                // printf("%d %d ", i, n/i);
        }
    }
    return count%1000000007;
}
template<typename T>
class graph{
    map<T,list<T>> adjList;
public:
    graph(){

    }
    void AddEdge(T u,int v,bool bidir = true){
        // push v at linked list at uth index
        adjList[u].push_back(v);
        // if its bidirectional
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i: adjList){
            // we will traverse ith linked list from 0 to number of vertex
            cout<<i.first<<"->";
            // traverse ith linked list and print it
            for(auto node : i.second){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void BFS(T src){
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbor : adjList[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            for(auto i:adjList){

            }
        }
    }
    int BFS_ShortestPath(T src,T dest,int*a){
        map<T,T> parent;
        map<T,int> dist;
        queue<T> q;
        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;
        q.push(src);

        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto i: adjList[node]){
                if(dist[i] == INT_MAX){
                     q.push(i);
                    dist[i] = dist[node]+1;
                    parent[i] = node;
                }
            }
        }
        int product=1;
        int i=dest;
        while(parent[i]!=i){
            // cout<<i<<" ";
            product*=a[i];
            i=parent[i];
        }
        // cout<<i<<endl;
        product*=a[i];
        // cout<<"product is "<<product<<endl;
        // cout<<"dist of "<<dest<<" from "<<src<<" is "<<dist[dest]<<endl;
        return product;
    }
};
 /*
            0------1 *
            |     /|  \
            |   /  |   2
            | /    |  /
            4------3 *

            all are bidirectional
    */
int main() {
    std::ios::sync_with_stdio(false);
   int tc;
    cin>>tc;
    while(tc--){
        graph<int> g;
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            g.AddEdge(x,y);
        }
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            // cout<<a[i]<<" ";
        }
        int Q;
        cin>>Q;
        while(Q--){
            int u,v;
            cin>>u>>v;
           int product = g.BFS_ShortestPath(u,v,a);
           // now just find factors and print it
           cout<<countFactor(product)<<endl;
        }
    }

    }
