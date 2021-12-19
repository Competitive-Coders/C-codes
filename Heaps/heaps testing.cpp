  #include<iostream>
  #include<stdlib.h>

using namespace std;
int main()
{
    int n;
    char ch;
    int *ptr;
    int i=0;
    do
    {
        cout<<"\nEnter the number: ";
        cin>>n;
        ptr=(int*)malloc(sizeof(int));

        ptr[i]=n;
        cout<<"Want to enter more? (y/n)";cin>>ch;
        if(ch=='y'||ch=='Y')
        {
            i++;
        }
    }while(ch=='y'||ch=='Y');
    int save=i;

    cout<<"\noutput\n";
    for(int i=0;i<=save;i++)
        cout<<ptr[i]<<" ";
}
