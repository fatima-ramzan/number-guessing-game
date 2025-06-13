#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void lowBeep()
{
    Beep(400,200);
}
void highBeep()
{
    Beep(1000,300);
    Beep(1200,300);
}
void getSettings(int difficulty,int *maxNum,int *maxAttempts)
{
    if (difficulty == 1)
    {
      *maxNum =100;
      *maxAttempts=10;
    }
    else if (difficulty == 2)
    {
       *maxNum = 100;
       *maxAttempts=7;
    }
    else if (difficulty == 3)
    {
        *maxNum =100;
        *maxAttempts=3;
    }
    else
    {
        *maxNum =10;
        *maxAttempts =10;
    }   
}
int main()
{
    int guess, number,maxNumber,maxAttempts,difficulty,playAgain;
    int attempts;
    srand(time(NULL));
    do
    {
        printf("\t\t\t\033[33m  GAME IS START🏎️\033[0m\n");
        printf("\t\033[33m let's play the game!\033[0m\n");
        printf("\t\033[35mSELECT DIFFICULTY LEVEL:\033[0m\n");
        printf("\t1. Easy    ------   10 Attempts\n");
        printf("\t2. Medium  ------   7 Attempts\n");
        printf("\t3. Hard    ------   3 Attempts\n");
        printf(" Enter the difficulty level you want to play(1-3):");
        scanf("%d",&difficulty);
        getSettings(difficulty,&maxNumber,&maxAttempts);
        number= rand() % maxNumber +1;
        printf("\033[33m Guess the number between 1 and %d. You have %d attempts.\033[0m\n",maxNumber,maxAttempts);
        attempts =0;
        while (attempts<maxAttempts)
        {
           printf("ENTER YOUR GUESS:");
           scanf("%d",&guess);
           attempts++;
           if (guess<number)
           {
            printf("\033[31mToo low! Try a higher number\033[0m\n");
            lowBeep();
           }
            else if (guess>number)
           {
            printf("\033[31mToo high! Try a lower number\033[0m\n");
            highBeep();
           }
           else
           {
           printf("\033[32m🎉Yayyyyyy! You guessed the number in %d attempt(s).\033[0m\n",attempts);
           highBeep();
           break;
           }
        }
        if (guess!=number)
        {
            printf("\033[31m😢You have used all the attermpts. The number was %d.\033[0m\n",number);
        }
        printf("\n\033[35mDo you want to play again?(1 = YES, 0 = NO):\033[0m");
        scanf("%d",&playAgain);
        printf("\n");
    }while (playAgain == 1);
    printf("\t\t\033[33m💝THANKYOU FOR PLAYING!💝\033[0m\n");
    return 0;
}

   
    