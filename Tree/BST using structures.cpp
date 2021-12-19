 #include<iostream>
 #include<malloc.h>
 using namespace std;
 struct node
 {
     int data;
     struct node* left;
     struct node* right;
 };

 node* add(struct node* root,int d)
 {
     struct node* n=(struct node*)malloc(sizeof(struct node));
     n->data=d;
     n->left=NULL;
     n->right=NULL;
     if(root==NULL)
     {
         root=n;
         return root;
     }
     else
     {
         struct node* temp=root;
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
     return root;
 }

 void print_inorder(struct node* root)
 {
     if(root==NULL)
        return;
     print_inorder(root->left);
     cout<<root->data<<" ";
     print_inorder(root->right);
 }
 int main()
 {
     cout<<"\nEnter the size:";
     int n;cin>>n;
     int a[n];
     cout<<"\nEnter the "<<n<<" Elements: ";
     /*int a[]={12,9,10,17,15,19,6,7};*/
     for(int i=0;i<n;i++)
        cin>>a[i];
     node* root=NULL;
     for(int i=0;i<n;i++)
     {
         root=add(root,a[i]);
     }
     cout<<"\nThe BST of the given array is:";
     print_inorder(root);
     return 0;
 }
