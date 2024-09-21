#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_wrapper(unsigned long long param);

unsigned long long fibonachiRecurs(unsigned long long num)
{
   printf("fibbonachiRecurs(%llu)\n", num); //Incentive is to look at what is getting passed into function.
   if (num == 0 || num == 1)
   {
      return num;
   }
   else
   {
      return fib_wrapper(num - 1) + fib_wrapper(num - 2); //incentive of doing this is to check if I have the num -1 value in cache or the num -2 value in cache.
   }
}

unsigned long long fibbonachiItera(unsigned long long n)
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

   printf("fib_wrapper %llu \n", param);
   if (fibArray[param] == 4) //if param == 4 then we no we havent calculated it yet. If it isnt then have we calculated it so return its value 
   {
      fibArray[param] = fibonachiRecurs(param);
      printf("fib_wrapper setting %llu to %llu\n", param, fibArray[param]);
   }

   printf("fib_wrapper returning %llu\n", fibArray[param]);
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
   
   if (__argc == 4)
   {

      filePointer = fopen(__argv[3], "r");
      fscanf(filePointer, "%llu", &fileNum);
      fclose(filePointer);

      num1 = atoi(__argv[1]);
      nthNum = num1 + fileNum;
      for (int i = 1; i <= nthNum; i++)
      {
         fibbonachiNum = fib_wrapper(i - 1); //its basically doing nthNum -1 but here it is i cus of for loop.

         printf("final result %llu\n ", fibbonachiNum);
      }
   }
   return 0;
}
