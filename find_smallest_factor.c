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

int main(int argc,char *argv[])
{
  int compositei;
  mpz_t composite,rop1,rop2,op1,op2;
  mpz_init(rop1);
  mpz_set_ui(op1,2);
  mpz_init(op2);
  mpz_init_set_str(composite,argv[1],10);
  compositei=atoi(argv[1])-1;
  mpz_mul_2exp(rop1,op1,compositei);
  mpz_sub_ui(rop1,rop1,2);
  mpz_gcd(rop2,composite,rop1);
  printf("\n");
  mpz_out_str(stdout,10,rop2);
  printf("\n");
}
