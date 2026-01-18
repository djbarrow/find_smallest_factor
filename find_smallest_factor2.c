#include <stdio.h>
#include <stdlib.h>

typedef unsigned long uint_t;
uint_t euclid_calc_gcd(uint_t x,uint_t y)
{
   uint_t temp;

   for(;;)
   {
      if(x==y)
	 return x;
      if(x<y)
      {
	temp=((uint_t)y%(uint_t)x);
	 if(temp==0)
	    return(x);
	 else
	    y=temp;
      }
      else
      {
	temp=((uint_t)x%(uint_t)y);
	 if(temp==0)
	    return(y);
	 else
	    x=temp;
      }
   }
}

int main(int argc,char *argv[])
{
  uint_t  compositei=atoi(argv[1]),num2;
  num2=(2ULL<<(compositei-1))-2;
  printf("%d\n",euclid_calc_gcd(num2,compositei));
}
