 #include<string.h>
 #include<math.h>
 using namespace std;

 template <typename T>
 class node
 {
 public:
    string key;
    T value;
    node<T>* next;

    node(string key,T value)
    {
        this->key=key;
        this->value=value;
    }
 };

 template <typename T>
 class hashtable
 {
     int cs; //current size
     int ts; //total max size
     node<T>** ptr_bucket;

     void rehash()
     {
         node<T>** old_bucket=ptr_bucket;
         int old_ts=ts;
         cs=0;
         ts*=2; //expanding like vectors and reducing the load factor to half

         ptr_bucket=new node<T>* [ts];
         for(int i=0;i<ts;i++)
         {
             ptr_bucket[i]=NULL;
         }
         for(int i=0;i<old_ts;i++)
         {
             node<T>* temp=old_bucket[i];
             while(temp!=NULL)
             {
                 insert_data(temp->key,temp->value);
                 temp=temp->next;
             }
         }
         delete []old_bucket;
     }
     int hash_function(string key)
     {
         int n=key.length();
         int ans=0;
         for(int i=0;i<n;i++)
         {
             ans+=key[i]*(pow(3,i));
         }
         ans%=ts;
         return ans;
     }
 public:

    hashtable(int ds=7)
    {
        cs=0;
        ts=ds;
        ptr_bucket=new node<T>*[ts];

        for(int i=0;i<ts;i++)
        {
            ptr_bucket[i]=NULL;
        }
    }

    void insert_data(string key,T value)
    {
        int i=hash_function(key);
        node<T>* n=new node<T>(key,value);
        n->next=ptr_bucket[i];
        ptr_bucket[i]=n;
        cs++;
        double load_factor=(double)cs/(double)ts;
        if(load_factor>=0.7)
            rehash();
    }

    void print()
    {
        for(int  i=0;i<ts;i++)
        {
            node<T>* temp=ptr_bucket[i];
            cout<<"Bucket "<<i<<"|--- ";
            while(temp!=NULL)
            {
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void delete_data(string k)
    {
        int i=hash_function(k);
        node<T>* temp=ptr_bucket[i];
        while(temp->next->key!=k&&temp!=NULL)
        {
            temp=temp->next;
        }
        if(temp==NULL)
            return;
        temp->next=temp->next->next;
    }

    void search_data(string k)
    {
        int i=hash_function(k);
        node<T>* temp=ptr_bucket[i];
        while(temp->key!=k)
        {
            temp=temp->next;
        }
        cout<<"\nKey: "<<temp->key<<"\nData: "<<temp->value<<endl;
    }
 };

