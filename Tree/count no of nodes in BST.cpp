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

  node* make_tree(node* root,int d)
  {
      node* n=new node(d);
      if(root==NULL)
      {
          root=n;
          return root;
      }
      node* temp=root;
      while(temp->left!=NULL||temp->right!=NULL)
      {
          if(d<=temp->data)
          {
              if(temp->left!=NULL)
              {
                  temp=temp->left;
              }
              else
                break;
          }
          else
          {
              if(temp->right!=NULL)
              {
                  temp=temp->right;
              }
              else
                break;
          }
      }

      if(d<=temp->data)
      {
          temp->left=n;
      }
      else
        temp->right=n;
        return root;
  }

  int count_nodes(node* root)
  {
      if(root==NULL)
      {
          return 0;
      }
      else
      {
          return (1+count_nodes(root->left)+count_nodes(root->right));
      }
  }
  int main()
  {
      node* root=NULL;
      int a[]={2,5,3,6,8,6,12,89,9};
      int n=sizeof(a)/sizeof(int);
      for(int i=0;i<n;i++)
      {
          root=make_tree(root,a[i]);
      }
      cout<<count_nodes(root);
  }
