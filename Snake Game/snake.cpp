 #include<iostream>
 #include<stdlib.h>
 #include<conio.h>
 #include<time.h>

 using namespace std;
 bool gameover;

 const int length=40,breadth=20;
 int x,y,fx,fy,bodyx[100],bodyy[100],score=0,n=0;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

 enum object
 {
     STOP,LEFT,RIGHT,UP,DOWN
 }dir;

 void state()
 {

     gameover=false;
     dir=STOP;
     x=length/2;
     y=breadth/2;
     fx=rand()%length;
     fy=rand()%breadth;
     score=0;
 }

 void layout()
 {
     for(int i=0;i<length;i++)
        cout<<"#";
     cout<<endl;

     for(int i=0;i<breadth;i++)
     {
         for(int j=0;j<length;j++)
         {
             if(j==0||j==(length-1))
                cout<<"#";
            else
                if(i==y&&j==x)
                   cout<<"O";
            else
                if(i==fy&&j==fx)
                   cout<<"0";
            else
            {
                bool print=false;
                for(int b=0;b<2*n;b++)
                {
                    if(bodyx[b]==j&&bodyy[b]==i)
                    {
                        cout<<"X";
                        print="true";
                    }
                }

                if(!print)
                {
                    cout<<" ";
                }
            }

         }
         cout<<endl;
     }
     for(int i=0;i<length;i++)
        cout<<"#";
 }

 void brain()
 {
      int prevx=bodyx[0];
         int prevy=bodyy[0];
         int prev2x;
         int prev2y;
         bodyx[0]=x;
         bodyy[0]=y;

         for(int b=1;b<2*n;b++)
         {
             prev2x=bodyx[b];
             prev2y=bodyy[b];
             bodyx[b]=prevx;
             bodyy[b]=prevy;
             prevx=prev2x;
             prevy=prev2y;
         }
     switch(dir)
     {
     case LEFT:
         delay(30);
        x--;break;
     case RIGHT:
         delay(30);
        x++;break;
     case UP:
         delay(150);
        y--;break;
     case DOWN:
         delay(150);
        y++;break;
     default:
        break;

     }

     if(x==fx&&y==fy)
     {
         score+=10;
         n++;
         fx=rand()%length;
         fy=rand()%breadth;
     }

     if(x==length+1||x==-1||y==-1||y==breadth+1)
     {
         gameover=true;
     }
 }


 void input()
 {
     if(_kbhit())
     {
         switch(_getch())
         {
             case 'w':
                 dir=UP;
                 break;
             case 's':
                dir=DOWN;
                break;
             case 'd':
                dir=RIGHT;
                break;
             case 'a':
                dir=LEFT;
                break;
             case 'q':
                gameover=true;
                break;
             default:
                break;
         }
     }
 }

 int main()
 {
     system("color B4");
    state();

    while(!gameover)
    {
        layout();
        brain();
        input();
        system("cls");
    }

    system("cls");
    cout<<"\n\n\n\n";
    cout<<"\n**********         **        ****      ****  ********            ******    **           **  ********  ********";
    cout<<"\n**********        ****       ** **    ** **  ***                ***  ***    **         **   ***       **      **";
    cout<<"\n**               **  **      **  **  **  **  **                **      **    **       **    **        **     **";
    cout<<"\n**     ***      **    **     **   ****   **  ********          **      **     **     **     ********  *******";
    cout<<"\n**    ** **    **** *****    **          **  **                ***    ***      **   **      **        **    ** ";
    cout<<"\n******** **   **        **   **          **  ***                ***  ***        ** **       ***       **     **";
    cout<<"\n******   **  ***        ***  **          **  ********            ******          ***        ********  **      **";
    cout<<"\n\n\n\n";

    cout<<"YOU SCORED: "<<score<<" POINTS";
    cout<<"\n\n\n\n";

 }

