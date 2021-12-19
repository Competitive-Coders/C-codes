 //add nodes to tree and if input==-1 ,the node becomes leaf node.

  #include<iostream>
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

  node* make_tree(node* root)
  {
      int d;cin>>d;
      if(d==-1)
        return NULL;

      root=new node(d);
      root->left=make_tree(root->left);
      root->right=make_tree(root->right);
      return root;

  }
  node* make_tree_another_way()
  {
      int d;cin>>d;
      if(d==-1)
      {
          return NULL;
      }
      node* n=new node(d);
      n->left=make_tree_another_way();
      n->right=make_tree_another_way();
      return n;
  }

  void print(node* root)
  {
      if(root==NULL)
        return;
      print(root->left);
      cout<<root->data<<" ";
      print(root->right);
  }
  int main()
  {
      node* root=NULL;
      root=make_tree(root);
      print(root);
  }
