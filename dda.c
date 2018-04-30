#include<stdio.h>
#include<math.h>
#include "image.h"

int round1(float x)
{  int y=x;
   if(x-y>0.5)
      return y+1;
   else
      return y;
   
}

int main()
{   int arr[500][500]={0};
    int xstart,ystart,xend,i,yend,nx,ny;
    float dx,dy,x,y,span;
    printf("Enter xstart and ystart:\n");
    scanf("%d %d",&xstart,&ystart);
    printf("Enter xend and yend:\n");
    scanf("%d %d",&xend,&yend);
    if(abs(xend-xstart)>=abs(yend-ystart)) 
         span = abs(xend-xstart);
     
    else
         span = abs(yend - ystart);
   
   dx = abs(xend - xstart) / span;
   dy = abs(yend - ystart) / span;
   x=xstart;
   y=ystart;
   while(i<=span)
   {  nx=round1(x);
      ny=round1(y);
      arr[nx][ny]=255;
      x=x+dx;
      y=y+dy;
      i=i+1;
    }
    imwriter(arr);
  return 0;
}
