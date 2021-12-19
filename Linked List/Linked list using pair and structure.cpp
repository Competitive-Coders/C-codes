  #include<iostream>
  #include<malloc.h>
  using namespace std;
  struct node
  {
      int data;
      struct node* next;
  };

  node* add(struct node* head,int d)
  {
      struct node* n=(struct node*)malloc(sizeof(struct node));
      n->data=d;
      n->next=NULL;
      if(head==NULL)
      {
          head=n;
          return head;
      }
      else
      {
          n->next=head;
          head=n;
          return head;
      }
      return head;
  }

  pair<node*,int> delete_node(struct node* head,int d)
  {
      if(head->data==d)
      {
          head=head->next;
          return make_pair(head,1);
      }
      else
      {
          struct node* n=head;
          while(n->next->data!=d&&n->next!=NULL)
          {
              n=n->next;
          }
          if(n->next==NULL)
          {
              return make_pair(head,0);
          }
          else
          {
              n->next=n->next->next;
              return make_pair(head,1);
          }
      }
  }
  void print(struct node* head)
  {
      cout<<"\nThe linked list is: \n";
      while(head!=NULL)
      {
          cout<<head->data<<"->";
          head=head->next;
      }
  }

void rearrange(struct node *list)
{
struct node *p, * q;
int temp;
if ((!list) || !list->next)
	return;
p = list;
q = list->next;
while(q)
{
	temp = p->data;
	p->data = q->data;
	q->data = temp;
	p = q->next;
	q = p?p->next:0;
}
}
  int main()
  {
      int a[]={9,2,8,7,5,6,4,3,12};
      struct node* head=NULL;
      int n=sizeof(a)/sizeof(int);
      for(int i=0;i<n;i++)
        head=add(head,a[i]);
      print(head);

      rearrange(head);
      print(head);
      int ele;
      cout<<"\nEnter element to be deleted: ";cin>>ele;
      pair<node*,int> r=delete_node(head,ele);

      if(r.second==1)
        cout<<"\nElement deleted!";
      else
        cout<<"\nNot found";
      //print(r.first);
      return 0;
  }
