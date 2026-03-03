/*
  This file is written by Denis Joseph Barrow barrow_dj@yahoo.com denisjosephbarrow@gmail.com
  and formula for the smallest factor was found
  by his program fundamental https://github.com/djbarrow/fundamental using symbolic regression techniques
 It is hoped this program might crack rsa or give new insights into factorisation.
However it might be a corallory of the fermat primality test https://en.wikipedia.org/wiki/Fermat_primality_test
 This algorithm is limited to 2^31 on a 31 bit processor and for this requires at least 8GB of ram as it has to get 2^composite-2 as one of the factors into the Euclid GDB Algorithm
 */


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <gmp.h>



#include <stdint.h>
#include <immintrin.h>

void mm_lfence (void)
{
  __builtin_ia32_lfence ();
}

uint64_t start_cycles,end_cycles;
    void counter_start() {
        mm_lfence();
        start_cycles = __rdtsc();
        mm_lfence();
    }
 
    uint64_t counter_stop() {
        mm_lfence();
        uint64_t end_cycles = __rdtsc();
        mm_lfence();
        return end_cycles - start_cycles;
    }
#define __USE_GNU 
#include <sched.h>
void pin_to_core(int core_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);
}





int getsmallestfactor(unsigned int composite)
{
  int idx,root=sqrt(composite),smallestfactor=composite;
   for(idx=2;idx<=root;idx++)
   {
     
      if((composite%idx)==0)
      {
	smallestfactor=idx;
	break;
      }
   }
   return smallestfactor;
}

int main(int argc,char *argv[])
{
  int lo_composite_i,hi_composite_i,composite_i;
  mpz_t composite,rop1,rop2,op1,op2;
  pin_to_core(0);
  if(argc!=3)
    {
      fprintf(stderr,"findsmallestfactor lo_int hi_int\n");
      exit(-1);
    }	
  mpz_init(rop1);
  mpz_init(op1);
  mpz_set_ui(op1,2);
  mpz_init(op2);
  mpz_init(rop2);
  lo_composite_i=atoi(argv[1]);
  hi_composite_i=atoi(argv[2]);
   for(composite_i=lo_composite_i;composite_i<=hi_composite_i;composite_i++)
    {
      mpz_init_set_ui(composite,composite_i);
      mpz_mul_2exp(rop1,op1,composite_i-1);
      mpz_sub_ui(rop1,rop1,2);
      counter_start();
       mpz_gcd(rop2,composite,rop1);
       // ... code to measure ...
       uint64_t cycles = counter_stop();
      printf("%d ",composite_i);
      mpz_out_str(stdout,10,rop2);
      printf(" %d",getsmallestfactor(composite_i));
      printf(" %ld\n",cycles);
    }
}
