#include<stdio.h>
#include "image.h"
#include<math.h>
int sign(int x)
{
  if(x>0) return 1;
  if(x<0) return -1;
  if(x==0) return 0;
}
int main()
{
   int x,y,xstart,ystart,xend,yend,dx,dy,s1,s2,temp,p,n,swap;
   int arr[500][500]={0};
   printf("Enter xstart and ystart:\n");
    scanf("%d %d",&xstart,&ystart);
    printf("Enter xend and yend:\n");
    scanf("%d %d",&xend,&yend);
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
  imwriter(arr);
 return 0;
}
