#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fibbonachiRecurs(unsigned long long num)
{

   if (num == 0 || num == 1)
   {
      return num;
   }
   else
   {
      return fibbonachiRecurs(num - 1) + fibbonachiRecurs(num - 2);
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


unsigned long long fib_wrapper(unsigned long long param, unsigned long long *arr, char *__argv)
{
   if (__argv[2] == 'r')
   {
      for(int i = 2; i < param; i++){
         if (arr[i] == 0)
      {
         arr[i] = fibbonachiRecurs(param);
         
      }
      }
   }
   else if (__argv[2] == 'i')
   {
      if (arr[param] == 0)
      {
         arr[param] += fibbonachiItera(param);
      }
   }
   return arr[param];
}


int main(int __argc, char *__argv[])
{
   FILE *filePointer;
   unsigned long long fileNum = 0;
   unsigned long long nthNum = 0;
   unsigned long long fibbonachiNum = 0;
   unsigned long long num1 = 0;

   if (__argc == 4)
   {

      filePointer = fopen(__argv[3], "r");
      fscanf(filePointer, "%llu", &fileNum);
      fclose(filePointer);

      num1 = atoi(__argv[1]);
      nthNum = num1 + fileNum;

      unsigned long long *fibArray = calloc(nthNum, sizeof(long long int));

      fibArray[0] = 0;
      fibArray[1] = 1;

      fibbonachiNum = fib_wrapper(nthNum - 1, fibArray, __argv[2]);

      printf("%llu", fibbonachiNum);

      free(fibArray);
   }
   return 0;
}
