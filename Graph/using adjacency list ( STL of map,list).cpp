 #include<iostream>
 #include<map>
 #include<list>
 using namespace std;

 //using hashmap and linked list STL.
 //map is storing data in increasing order.
 template<typename T>
 class graph
 {
     map<T,list<T> > adjList;
 public:
     graph()
     {

     }
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
 };

 int main()
 {
     graph<string> G;
     G.add_edge("madan","mohan");
     G.add_edge("mohan","ram");
     G.add_edge("gopal","madan",false);
     G.add_edge("mohan","gopal");
     G.print();
 }
