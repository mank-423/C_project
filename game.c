#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int ropasc(char you, char comp){
    //1 - win, -1 - lose, 0 - draw

    //Condition to draw
    if (you==comp){
        return 0;
    }

    //Other conditions
    if (you=='r'){
        if (comp=='s'){
            return 1;
        }

        else if (comp=='p'){
            return -1;
        }
        
        else{
            //printf("Wrong choice");
            return 1000;
        }
    }

    else if (you=='s'){
        if (comp=='r'){
            return -1;
        }

        else if (comp=='p'){
            return 1;
        }
        else{
            return 1000;
        }
    }

    else if (you=='p'){
        if (comp=='r'){
            return 1;
        }

        else if (comp=='s'){
            return -1;
        }
    }

    else{
        return 1000;
    }
}


int main()
{   
    char choice = 'Y';
    int sco_you,sco_comp;
    //while (choice=='Y' || choice == 'y'){
        srand(time(0));
        int number = rand()%3+1; //range of 3
        
        char comp,you;
        
        //Computers choice
        if (number<=1){
            comp = 's';
        }

        else if (number = 2){
            comp = 'p';
        }

        else{
            comp ='r';
        }


        //User's choice
        printf("Enter: \n");
        printf("r - rock, p - paper, s - scissors \n");
        scanf("%c",&you);   

        //Function call
        int result = ropasc(you,comp);

        //Result
        printf("You chose %c and computer chose %c\n",you,comp);

        if (result==1){
            printf("You win\n");
            sco_you++;
        } 

        else if(result==-1){
            printf("You lose\n");
            sco_comp++;
        }

        else if (result==0){
            printf("You draw\n");
        }

        else{
            printf("Wrong choice entered\n");
        }
        
       
        /*
        //Continue or not
        printf("Do you want to continue?: Y or N\n");
        scanf("%c",&choice);
        */
         return 0;
   // }
}