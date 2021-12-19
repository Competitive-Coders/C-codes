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
        right=NULL;left=NULL;
    }
 };

 class tree
 {
 public:
     node* root=NULL;
     void add_node(int data)
     {
         node* n=new node(data);
         if(root==NULL)
            root=n;
         else
         {
             node* temp=root;
             while(temp->left!=NULL||temp->right!=NULL){
             if(n->data<=temp->data)
             {
                 if(temp->left!=NULL)
                 temp=temp->left;
                 else
                 break;
             }
             else
             {
                 if(temp->right!=NULL)
                 temp=temp->right;
                 else
                 break;
             }
             }
             if(n->data<=temp->data)
             {
                 temp->left=n;
             }
             else
             {
                 temp->right=n;
             }
         }
     }
     void preorder(node* ptr)
     {
         if(ptr==NULL)
            return;
         cout<<ptr->data<<"->";
         preorder(ptr->left);
         preorder(ptr->right);
     }

     void inorder(node* ptr)
     {
         if(ptr==NULL)
            return;
         inorder(ptr->left);
         cout<<ptr->data<<"->";
         inorder(ptr->right);
     }

     void postorder(node* ptr)
     {
         if(ptr==NULL)
            return;
         inorder(ptr->left);
         inorder(ptr->right);
         cout<<ptr->data<<"->";
     }
     void level_order(node* ptr)
     {
         queue<node*> q;
         while(ptr!=NULL)
         {
             cout<<ptr->data<<"->";
             if(ptr->left)
             q.push(ptr->left);
             if(ptr->right)
             q.push(ptr->right);
             ptr=q.front();
             q.pop();
         }
     }
 };

 int main()
 {
     tree t;
     t.add_node(2);
     t.add_node(4);
     t.add_node(1);
     t.add_node(7);
     t.add_node(11);
     t.add_node(3);
     t.add_node(6);
     t.add_node(3);
     node* ptr=t.root;
     t.preorder(ptr);
     cout<<endl;
     t.inorder(ptr);
     cout<<endl;
     t.postorder(ptr);
     cout<<endl;
     t.level_order(ptr);
 }
