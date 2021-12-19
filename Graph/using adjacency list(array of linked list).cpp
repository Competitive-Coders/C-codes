 #include<iostream>
 using namespace std;
 //used double list just for easy traversal, singly list would also work...
 template<typename T>
 class node
 {
     public:
     T data;
     node<T>* left;
     node<T>* right;
    node(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
 };
 template<typename T>
 class double_list
 {
     node<T>* head;
 public:
    double_list()
    {
        head=NULL;
    }
    void add_node(T data)
    {
        node<T>* n=new node<T>(data);
        if(head==NULL)
        {
            head=n;
        }
        else
        {
            n->right=head;
            head->left=n;
            head=n;
        }
    }

    void print_list()
    {
        node<T>* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->right;
        }
        cout<<endl;
    }
 };
 template<typename T>
 class graph
 {
     int V;
     double_list<T> *l;
 public:
    graph(int V)
    {
        this->V=V;
        l=new double_list<T>[V];
    }
    void add_edge(T a,T b,bool bi=true)
    {
        if(bi)
        {
            l[a].add_node(b);
            l[b].add_node(a);
        }
        else
        {
            l[a].add_node(b);
        }
    }

    void print_adjacency_list()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";l[i].print_list();
        }
    }
 };

 int main()
 {
     graph<int> G(6);
     G.add_edge(0,4);
     G.add_edge(1,3);
     G.add_edge(2,4);
     G.add_edge(0,5);
     G.add_edge(1,2,false);
     G.add_edge(3,2,false);
     G.print_adjacency_list();
     return 0;
 }
