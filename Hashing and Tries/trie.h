 #include<unordered_map>
 #define hashmap unordered_map <char,node*>
 using namespace std;

 class node
 {
 public:
    char data;
    hashmap h;
    bool isTerminal;

    node(char data)
    {
        this->data=data;
        isTerminal=false;
    }
 };

 class trie
 {
 public:
    trie()
    {
        node* root=new node('\0');
    }

    //insertion of data:

    void insert(char* word)
    {
        node* temp=root;
        int i=0;
        while(word[i]!='\0')
        {
            if(temp->h.count(word[i])==0)
            {
                node* n=new node(word[i]);
                temp->h[word[i]]=n;
                temp=n;
            }
            else
            {
                temp=temp->h[word[i]];
            }
        }
        temp->isTerminal=true;
        i++;
    }

    bool search(char* word)
    {
        node* temp=root;
        int i=0;
        while(word[i]!='\0')
        {
            if(temp->h.count(word[i])==1)
            {
                temp=temp->h[word[i]];
            }
            else
                return false;
        }
        return temp->isTerminal;
    }
 };
