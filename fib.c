#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_wrapper(unsigned long long param);

unsigned long long fib_r(unsigned long long num)
{
   if (num == 0 || num == 1)
   {
      return num;
   }
   else
   {
      return fib_wrapper(num - 1) + fib_wrapper(num - 2); // incentive of doing this is to check if I have the num -1 value in cache or the num -2 value in cache.
   }
}

unsigned long long fib_i(unsigned long long n)
{
   unsigned long long num1 = 0;
   unsigned long long num2 = 1;
   unsigned long long num3 = 0;
   for (int i = 2; i <= n; i++)
   {

      num3 = num1 + num2;
      num1 = num2;
      num2 = num3;
   }
   return num3;
}

unsigned long long fibArray[200];

unsigned long long fib_wrapper(unsigned long long param)
{
   if (fibArray[param] == 4) // if param == 4 then we no we havent calculated it yet. If it isnt then have we calculated it so return its value
   {
      fibArray[param] = fib_r(param);
   }
   return fibArray[param];
}

int main(int __argc, char *__argv[])
{
   FILE *filePointer;
   unsigned long long fileNum = 0;
   unsigned long long nthNum = 0;
   unsigned long long fibbonachiNum = 0;
   unsigned long long num1 = 0;

   for (int i = 0; i < 200; i++)
   {
      fibArray[i] = 4; // initalize all 200 cells to 4
   }

   if (__argc == 3)
   {

      num1 = atoi(__argv[1]);
      nthNum = num1;

      if (*__argv[2] == 'r')
      {
         fibbonachiNum = fib_wrapper(nthNum - 1);
      }
      else if (*__argv[2] == 'i')
      {
         fibbonachiNum = fib_wrapper(nthNum - 1);
      }
      // its basically doing nthNum -1 but here it is i cus of for loop.
      printf("%llu", fibbonachiNum);
   }

   return 0;
}
