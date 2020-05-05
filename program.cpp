#include<string.h>
#include<iostream>
#include<cstdio>
#include<math.h>
#include <graphics.h>
using namespace std;
char encoding(int arr[]){
}
int main()
{
int a[100],b[100];
int c,sum=0,opt,j;
int data[100];
int gd = DETECT, gm,i=1;
int x1=150,y1=150,x2=150,y2=150;
char otpt[100];
cout<<"enter data \n";//enter the bits 
for(i=3;i>=0;i--)    //bits are of type interger
cin>>data[i];
for(i=0;i<4;i++){
c=data[i];
j=pow(2,i);
sum+=c*j;
}
cout<<"\nsum="<<sum<<"\n";
if(sum==0)opt=30;  //4B5B-encoding_start
if(sum==1)opt=9;
if(sum==2)opt=20;
if(sum==3)opt=21;
if(sum==4)opt=10;
if(sum==5)opt=11;
if(sum==6)opt=14; 
if(sum==7)opt=15;
if(sum==8)opt=18;
if(sum==9)opt=19;
if(sum==10)opt=22;
if(sum==11)opt=23;
if(sum==12)opt=26;
if(sum==13)opt=27;
if(sum==14)opt=28;
if(sum==15)opt=29;
for(i=0;i<5;i++){
a[i]=opt%2;
b[4-i]=a[i];
opt=(int)opt/2;}
//for(i=0;i<5;i++){
//b[i]=b[i]+'0';
//}
for(i=0;i<5;i++)
cout<<"\n"<<b[i]<<"\t";//output of 4B5B-encoding

i=1;                //         start of nrz-i encoding with graphics
initgraph(&gd, &gm, "");
float interval=(3*3.14)/100;
    setcolor(WHITE);
    line(150,0,150,500);
    line(150,200,1000,200);
    setcolor(GREEN);
    line(0,50,2000,50);
    line(250,100,250,300);
    line(350,100,350,300);
    line(450,100,450,300);
    line(550,100,550,300);
    setcolor(YELLOW);
        for(int i=0; i<=1000;i++ )
    {
        float x=(i%200)*interval;
        int y=sin(x)*60;
        putpixel(i,50-y,YELLOW);

    }

    if(b[0]==0)
    {
        y1=150;
        y2=150;
    }
    else
    {
        y1=250;
        y2=250;
    }
    for (i=1;i<5;i++)
    {
        x1=x2;
        y1=y2;
        x2=x1+100;
        line(x1,y1,x2,y2);
        c=b[i];
        x1=x2;
        y1=y2;
        if(c==1)
        {
            if(y1==150)
            {
                y2=250;
            }
            else if(y1==250)
            {
                y2=150;
            }
        }
       // cout<<" down wala x1  "<<x1<<" x2 "<<x2<<" y1  "<<y1<<" y2  "<<y2<<"\n";

        line(x1,y1,x2,y2);


    }
    x1=x2;
    y1=y2;
    x2=x1+100;
    line(x1,y1,x2,y2);
    x1=x2;
    y1=y2;
    line(x1,y1,x1,200);
    line(0,350,2000,350);
    int p=0;
    setcolor(WHITE);
int k;
        // for(int k=0;k<4;k++){    //start of biphase modulation or binary phase shift keying modulation with graphics
        for(int i=150; i<=1000;i++ )

    {
        float x=(i%200)*interval;
        int y=sin(x+p)*50;
        putpixel(i,y+350,BLUE);
        if(i==250){
        k=0;
        c=b[k+1]-b[k];
        cout<<"\nc="<<c;
        if(c!=0)
        p=p+180;
        }
         if(i==350){
        k=1;
        c=b[k+1]-b[k];
        cout<<"\nc="<<c;
        if(c!=0)
        p=p+180;
        }
         if(i==450){
        k=2;
        c=b[k+1]-b[k];
        cout<<"\nc="<<c;
        if(c!=0)
        p=p+180;
        }
         if(i==550){
        k=3;
        c=b[k+1]-b[k];
        cout<<"\nc="<<c;
        if(c!=0)
        p=p+180;
        }




        }

    getch();
	closegraph();


}
