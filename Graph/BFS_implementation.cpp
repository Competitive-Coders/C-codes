 #include<iostream>
 #include<map>
 #include<list>
 #include<queue>
 using namespace std;

 //using hashmap and linked list STL.
 //map is storing data in increasing order.
 template<typename T>
 class graph
 {
     map<T,list<T> > adjList;
 public:
    void add_edge(T a,T b,bool bi=true)
    {
        adjList[a].push_back(b);
        if(bi)
        adjList[b].push_back(a);
    }

    void print()
    {
        for(auto i: adjList)
        {
            cout<<i.first<<"::> ";
            for(auto j:i.second)
            {
                cout<<j<<"->";
            }
            cout<<endl;
        }
    }

    void bfs(T src)
    {
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T n=q.front();
            cout<<n<<"--";
            q.pop();

            for(int neighbour: adjList[n])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
    }

    void find_shortest(T src)
    {
        queue<T> q;
        map<T,int> dist;
        for(auto var: adjList)
        {
            dist[var]=INT_MAX;
        }
    }
 };

 int main()
 {
     graph<int> G;
     G.add_edge(1,2);
     G.add_edge(2,3);
     G.add_edge(3,5,false);
     G.add_edge(4,2);
     G.add_edge(1,5);
     G.print();

     cout<<endl;
     G.bfs(1);
 }
