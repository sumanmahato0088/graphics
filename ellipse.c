#include<stdio.h>
#include "image.h"
//#define ROUND(a) ((int) (a+0.5))

int main()
{
  int arr[500][500]={0};
  int x,y,a,b,xc,yc;
  int p,fx,fy,a2,b2,twoa2,twob2;
  printf("Enter xc and yc\n");
  scanf("%d%d",&xc,&yc);
  printf("Enter a and b\n");
  scanf("%d%d",&a,&b);
  a2=a*a;
  b2=b*b;
  twoa2=2*a2;
  twob2=2*b2;
  x=0;
  y=b;
  fx=0;
  fy=twoa2*b;
  p=(b2-(a2*b)+(a2*0.25));
  arr[xc+x][yc+y]=255;
  arr[xc-x][yc+y]=255;
  arr[xc+x][yc-y]=255;
  arr[xc-x][yc-y]=255;
  while(fx<fy)
  {
     x=x+1;
     fx=fx+twob2;
     if(p<0)
        p=p+b2+fx;
     else
       {
         y=y-1;
         fy=fy-twoa2;
         p=p+b2+fx-fy;
        }
   arr[xc+x][yc+y]=255;
   arr[xc-x][yc+y]=255;
   arr[xc+x][yc-y]=255;
   arr[xc-x][yc-y]=255;
  }
  p=(b2*(x+0.5)*(x+0.5)+a2*(y-1)*(y-1)-(a2*b2));
  while(y>0)
  {
     y=y-1;
     fy=fy-twoa2;
     if(p>0)
      p=p+a2-fy;
     else
      {
        x=x+1;
        fx=fx+twob2;
        p=p+a2-fy+fx;
       }
    arr[xc+x][yc+y]=255;
    arr[xc-x][yc+y]=255;
    arr[xc+x][yc-y]=255;
    arr[xc-x][yc-y]=255;
  }
 imwriter(arr);
 return 0;
}   
