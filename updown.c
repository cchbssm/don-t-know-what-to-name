#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

short int n, res=0, ans, sta;

void set();
void game();

int main(){
   printf("welcome to up down game\ntype 1 to start\n");
   while(1){
      set();
      if(!sta) return 0;
      game();
      if(!sta || !res) return 0;
      if(sta) set();
   }

   return 0;
}

void set()
{
   srand(time(NULL));
   scanf("%hd", &sta);
   if(!sta) return;
   printf("type max integer(1~32768)\n");
   scanf("%hd", &n);
   printf("You have 10 chances\nwhenever you want to end type 0\n");
   ans = rand() % n + 1;

   return;
}

void game(){
   for(int cnt = 0; cnt<10; cnt++){
      printf("You have %d chances left\ntype answer\n", 10-cnt);

      scanf("%hd", &res);
      if(!res) return;
      if(res == ans){
         printf("Your correct!\nIf you want to play more type 1 or type 0\n");
         return;
      }
      if(res > ans){
         printf("down\n");
         continue;
      }
      if(res < ans){
         printf("up\n");
         continue;
      }
   }
   printf("You failed\nIf you want to try one more type 1 or type 0\n");

   return;
}