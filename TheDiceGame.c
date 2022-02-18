#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dices(int *number)
{
    *number=rand()%12;
}
void fcn(int bet_type, int specific_num, char *status, int *sum_of_dices)
{
    dices(sum_of_dices);
    if(bet_type==1)
    {
        if(*sum_of_dices>=2&&*sum_of_dices<=6)
        {
            *status='W';
        }
        else
        {
            *status='L';
        }
    }
    else if(bet_type==2)
    {
        if(*sum_of_dices>=7&&*sum_of_dices<=12)
        {
            *status='W';
        }
        else
        {
            *status='L';
        }
    }
    else if(bet_type==3)
    {
        if(*sum_of_dices==specific_num&&*sum_of_dices!=0&&*sum_of_dices!=1)
        {
            *status='W';
        }
        else
        {
            *status='L';
        }
    }

}
int main()
{
    srand(time(NULL));
    int number,account,bet,choice,win,nmb;
    char ch='Y', stat;
    printf("Enter a start account for the game $:");
    scanf("%d",&account);
    int dum=1;
    while(ch=='y'||ch=='Y')
    {
        while(1)
        {
            printf("Enter the bet amount: ");
            scanf("%d",&bet);
            if(bet<=account)
            {
                break;
            }
            else
            {
                printf("You can't bet higher than your currency.\n");
            }
        }
        account-=bet;
        while(1)
        {
            printf("Enter '1' to bet on numbers between 2-6, '2' to bet on numbers between 7-12, or '3' to bet on a specific number:\n");
            scanf("%d",&choice);
            if(choice==1 || choice==2)
            {
                fcn(choice,0, &stat, &nmb);
                printf("Dices are thrown. Summation is %d\n",nmb);
                if(stat=='W')
                {
                    printf("You win this round!\n");
                    win=bet*2;
                    break;
                }
                else
                {
                    printf("You lost this round!\n");
                    win=0;
                    break;
                }
            }
            else if(choice==3){
                printf("Enter a number between 2-12: ");
                scanf("%d",&number);
                fcn(choice,number, &stat, &nmb);
                printf("Dices are thrown. Summation is %d\n",nmb);
                if(stat=='W')
                {
                    printf("You win this round!\n");
                    win=bet*15;
                    break;
                }
                else
                {
                    printf("You lost this round!\n");
                    win=0;
                    break;
                }
            }
            else
            {
                printf("Wrong selection, select again.\n");
            }
        }
        account+=win;
        printf("Your total currency is %d\n",account);
        if(account<=0)
        {
            printf("You've lost all of your money\n");
            break;
        }
        else
        {
            while(1){
                printf("Do you want to continue: Y/N:");
                scanf(" %c",&ch);
                if(ch=='y'||ch=='Y'||ch=='n'||ch=='N')
                {
                    break;
                }
                else{
                    printf("Wrong input, please enter again.\n");
                }
            }
        }
    }
    printf("Thank you for playing. See you next time!\n");
    system("PAUSE");
    return(0);
}
