 #include<iostream>
 using namespace std;
 class node
 {
 public:

     int data;
     node* next;
     node(int data)
     {
         this->data=data;
         next=NULL;
     }
 };
  node* head=NULL;
 void push(int data)
 {
     node* n=new node(data);
     if(head==NULL)
     {
         head=n;
     }
     else
     {
         node* temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=n;
     }
 }
 void reverse_full(node* ptr)
 {
     node* p=NULL;
     node* c=ptr;
     node* n=ptr->next;
     while(c->next!=NULL)
     {
         c->next=p;
         p=c;
         c=n;
         n=n->next;
     }
     c->next=p;
     head=c;

 }
 void reverse_list(node* ptr,int k,int x)
 {
     if(ptr==NULL||ptr->next==NULL||k==0||k==1)
     {
         return;
     }
     else{
     node* p=NULL;
     node* c=ptr;
     node* n=ptr->next;
     int i=0;
     if(k==x)
     {
         reverse_full(ptr);
     }
     else{
     while(i<k)
     {
         c->next=p;
         p=c;
         c=n;
         n=n->next;
         i++;
     }
     node* temp=head;
     temp->next=c;
     head=p;
     }
     }
 }

 void print()
 {
     node* tmp=head;
     while(tmp!=NULL)
     {
         cout<<tmp->data<<" ";
         tmp=tmp->next;
     }
 }

 int main()
 {

     int n,k;
     cin>>n>>k;
     for(int i=0;i<n;i++)
     {
         int a;cin>>a;
         push(a);
     }

     reverse_list(head,k,n);
     print();
 }
