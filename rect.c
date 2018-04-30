#include<stdio.h>
#include "image.h"
#include<math.h>
int sign(int x)
{
  if(x>0) return 1;
  if(x<0) return -1;
  if(x==0) return 0;
}

int arr[500][500]={0};

void draw(int xstart,int ystart,int xend,int yend)
{
   int x,y,dx,dy,s1,s2,temp,p,n,swap;
   dx = abs(xend -xstart);
   dy = abs(yend -ystart);
   s1=sign(xend-xstart);
   s2=sign(yend-ystart);
   if(dy>dx)
   {
      temp = dx;
      dx = dy;
      dy = temp;
      swap =1;
    }
    else
      swap = 0;
  n=1;
  p=2*dy-dx;
  arr[x][y]=255;
  while(n<=dx)
  {
     if(p>=0)
     {
        x=x+s1;
        y=y+s2;
        p=p+2*(dy-dx);
     }
     else
      {   if(swap==1)
             y=y+s2;
         else
             x=x+s1;
        p=p+2*dy;
      }
     arr[x][y]=255;
     n=n+1;
   }
}

int main()
{  int xstart,ystart,xend,yend;
   printf("Enter xstart and ystart:\n");
    scanf("%d %d",&xstart,&ystart);
    printf("Enter xend and yend:\n");
    scanf("%d %d",&xend,&yend);
   draw(xstart,ystart,xend,ystart);
   draw(xend,ystart,xend,yend);
   draw(xend,yend,xstart,yend);
   draw(xstart,yend,xstart,ystart);
 imwriter(arr);
return 0;
}
