 #include<iostream>
 using namespace std;
 class complex
 {
     int real;
     int img;
 public:
     complex(); //default
     complex(int a=0,int b=0) //parameterized
     {
         real=a;
         img=b;
     }
     complex(complex &C) //copy
     {
         real=C.real;
         img=C.img;
     }

     complex add(complex C1,complex C2)
     {
         real=C1.real+C2.real;
         img=C1.img+C2.img;
     }
     void display()
     {
         cout<<endl;
         if(img>0)
         cout<<real<<" + "<<img<<"i";
         else
         cout<<real<<" - "<<-img<<"i";

     }
     void operator -()
     {
         img=-img;
     }
     void operator +(complex C)
     {
         real+=C.real;
         img+=C.img;
     }

 };
 int main()
 {
     complex c(12,5);
     complex d(c);
     -d;
     c.display();
     d.display();
     complex a(5,9),b(a);
     a.display();
     b.display();
     b+a;
     a.display();
     b.display();
     return 0;
 }
