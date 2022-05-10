#include<stdio.h>
#include<conio.h>


//Display the matrix 
void display(char grid[3][3]){
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%c \t",grid[i][j]);
        }
        printf("\n");
    }
}

//Putting the char in the matrix using the no of cell depicted int the matrix
void put_char(int cell,char c, char ar[3][3]){
    int i,j;
    switch (cell)
            {
            case 1:
                i=0;
                j=0;
                break;
            case 2:
                i=0;
                j=1;
                break;
            case 3:
                i=0;
                j=2;
                break;
            case 4:
                i=1;
                j=0;
                break;
            case 5:
                i=1;
                j=1;
                break;
            case 6:
                i=1;
                j=2;
                break;
            case 7:
                i=2;
                j=0;
                break;
            case 8:
                i=2;
                j=1;
                break;
            case 9:
                i=2;
                j=2;
                break;
            
            default:
                break;
            };
            ar[i][j] = c; 
}

//Checking the rows of the matrix
int horztl(char arr[3][3]){
    int i=0;
    int j=0;
    
    for (i=0;i<3;i++)
    {
        if (arr[i][j]=='0' || arr[i][j]=='X'){
        if (arr[i][j] == arr[i][j+1] && arr[i][j+1]==arr[i][j+2]){
            return 1;
            break;
        }
        else{
            continue;
        }    
        
        }
    }

    return 0;

}


//Checking the vertical lines of the matrix
int vertcl(char arr[3][3]){
    int i=0;
    int j=0;
    
    for (j=0;j<3;j++)
    {
        if (arr[i][j]=='0' || arr[i][j]=='X'){
        if (arr[i][j] == arr[i+1][j] && arr[i+1][j]==arr[i+2][j]){
            return 1;
            break;
        }
        else{
            continue;
        }    
        }
    }

    return 0;

}

//Diagnols check of the matrix
int cross(char arr[3][3]){
    int i=0;
    int j=0;
    //00 11 22  , 20,11,02
    for (i=0;i<3;i++)
    {
        if (arr[i][j]=='0' || arr[i][j]=='X'){
        if (arr[i][j] == arr[i+1][j+1] && arr[i+1][j+1]==arr[i+2][j+2]){
            return 1;
            break;
        }

        else if (arr[i][j] == arr[i-1][j+1] && arr[i-1][j+1]==arr[i-2][j+2]){
            return 1;
            break;
        }

        else{
            continue;
        }

        }
    }

    return 0;
}

//Putting above 3 functions to get the win or not 
//The user who will put the recent character will be the winner as that will update the matrix
//It is working for cross and horizontal, whereas column ke liye not working -> corrected there was a[i][j] = a[i+1][j] correct
// but a[i][j+1] = a[i+2][j] wasnt correct, and it is corrected 
int win(char arr[3][3]){
    int crss,hrz,vtl;
    vtl = vertcl(arr);
    hrz = horztl(arr);
    crss = cross(arr);
    if (vtl == 1 || crss == 1 || hrz == 1){
        return 1;
        //break;
    }
    else{
    }
}




int main()
{
    //1 2 5 3 9 4 6 8 7
    //The game is working for a cross of user 1
    char arr[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
        };
    int i=0, j=0; //For index of array 
    int cell; //Choosing the cell
    int chance=0; //For the chance of user and computer 
    char c1, c2; // Character X or 0
    int k,l; //For the iteration of for loop
    int sc_ur1=0,sc_ur2=0; //For score of computer and user
    int finish; //For using the win function in the loop 

    printf("----------------------------TIC TAC TOE----------------------- \n");
    //PLAYER CHOOSING X OR 0
    printf("Player 1 choose (X or 0):\n");
    scanf("%c",&c1);
    if (c1=='X'){
        c2='0';
        printf("Player 2 gets (X or 0):\n");
        printf("%c \n",c2);
    }
    else{
        c2='X';
        printf("Player 2 gets (X or 0):\n");
        printf("%c \n",c2);
    }
    
    printf("CONSIDER THE GRID AS MATRIX, WITH ELEMENTS NAMING AS FOLLOWS \n");
    //printf("A11 \t A12 \t A13 \nA21 \t A22 \t A23 \nA31 \t A32 \t A33 \n");
    printf("1 \t 2 \t 3 \n4 \t 5 \t 6 \n7 \t 8 \t 9 \n");
    
    //Entry in the matrix 
    for (k=0;k<3;k++){
        for (l=0;l<3;l++){
        
        if (chance==0 || chance==2 || chance==4 || chance==6 || chance==8){
            printf("Enter player 1 your position:\n");
            scanf("%d",&cell);
            put_char(cell,c1,arr);
            if (win(arr)==1){
                sc_ur1++;
            }
            
        }

        else{
            printf("Enter player 2 your position:\n");
            scanf("%d",&cell);
            put_char(cell,c2,arr);
            if (win(arr)==1){
                sc_ur2++;
            }
            
        }

        if (win(arr)==1){
                break;
        }
        
        //Display where game finishes after each turn
        display(arr);

        chance++;
        }
        
        if (win(arr)==1){
                break;
        }
    }
        

    printf("\n");
    //Display
    printf("The game finishes at: \n");
    display(arr);
    
    //Sharing the result 
    if (sc_ur1 == 1){
        printf("User 1 wins the game!!");
    }

    else if (sc_ur2 == 1){
        printf("User 2 wins the game!!");
    }

    else{
        printf("The game is a draw");
    }

    //Logic to win
    //i= any fixed number  row
    //arr[i][j]==arr[i][j+1] == arr[i][j+2]->row

    //j = fixed number column
    //arr[i][j]==arr[i+1][j] == arr[i+2][j]->column

    //Corners
    //arr[i][j]==arr[i+1][j+1] == arr[i+2][j+2]
    //arr[i-1][j-1] ==arr[i][j]  == arr[i-1][j-1]

    
    return 0;
}