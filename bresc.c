#include<stdio.h>
#include "image.h"
#include<math.h>

int main()
{
   int arr[500][500]={0};
   int x,y,xc,yc,r,d,dd;
   printf("Enter xc and yc\n");
   scanf("%d%d",&xc,&yc);
   printf("Enter Radius:");
   scanf("%d",&r);
   x=0;y=r;
   dd=2*(1-r);
   while(y>x)
   {
        arr[xc+x][yc+y]=255;
        arr[xc-x][yc+y]=255;
	arr[xc+x][yc-y]=255;
	arr[xc-x][yc-y]=255;
	arr[xc+y][yc+x]=255;
	arr[xc-y][yc+x]=255;
	arr[xc+y][yc-x]=255;
	arr[xc-y][yc-x]=255;
     if(dd<0)
       {
          d=2*dd+2*y-1;
	  if(d<=0)
          {    x=x+1;
               dd=dd+2*x+1;
          }
          else
          {
               x=x+1;
               y=y-1;
               dd=dd+2*x-2*y+2;
           }
        }
    else
         if(dd>0)
           {
                d=2*x-2*dd+1;
                if(d<0)
                  {y=y-1;
                   dd=dd-2*y+1;
                  }
                else
                  {
                    x=x+1;
                    y=y-1;
                    dd=dd+2*x-2*y+2;
                  }
            }
         else
           { x=x+1;
             y=y-1;
             dd=dd+2*x-2*y+2;
            }
   }
  imwriter(arr);
 return 0;
}
