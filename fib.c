#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fibbonachiRecurs(unsigned long long num, unsigned long long *fibArray)
{
   unsigned long long fibValue;
   if (num == 0 || num == 1)
   {
      return num;
   }
   else if(fibArray[num] == 0){
   fibValue = fibbonachiRecurs(num- 1, fibArray) + fibbonachiRecurs(num-2, fibArray);
   fibArray[num] = fibValue;
   }
}


unsigned long long fibbonachiItera(unsigned long long n, unsigned long long *fibArray)
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

      if (*__argv[2] == 'i')
      {
         fibbonachiNum = fibbonachiItera(nthNum - 1, fibArray);
      }
      else if (*__argv[2] == 'r')
      {
        fibbonachiNum = fibbonachiRecurs(nthNum - 1, fibArray);
      }
      
         printf("%llu", fibbonachiNum);
      
      free(fibArray);
   }
   return 0;
}
