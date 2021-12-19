 //add nodes to tree and if input==-1 ,the node becomes leaf node.

  #include<iostream>
  #include<queue>
  using namespace std;
  class node
  {
  public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
  };

  node* make_tree(node* root) //make a tree NOT a BST...
  {
      int d;cin>>d;
      if(d==-1)
        return NULL;

      root=new node(d);
      root->left=make_tree(root->left);
      root->right=make_tree(root->right);
      return root;

  }

  void print(node* root) //level order print using queue
  {
      queue<node*> q;
      q.push(root);
      while(!q.empty())
      {
          node* n=q.front();
          q.pop();
          q.push(n->left);
          q.push(n->right);
          cout<<n->data<<" ";
      }
      return;
  }

  void print2(node* root,int k) //level order print of kth level using recursion
  {
      if(root==NULL)
        return;
      if(k==0)
      {
          cout<<root->data<<" ";
          return;
      }

      print2(root->left,k-1);
      print2(root->right,k-1);
      return;
  }

  int height(node* root)
  {
      if(root==NULL)
        return 0;
      return max(height(root->left),height(root->right))+1;
  }

  void print_all(node* root)  //function to print all levels from 0 to h using print2 function and height of tree
  {
      int x=height(root);

      for(int i=0;i<x;i++)
      {
          print2(root,i);
          cout<<endl;
      }
  }
  int main()
  {
      node* root=NULL;
      root=make_tree(root);
      print_all(root);
  }
