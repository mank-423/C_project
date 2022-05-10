#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int number;
	srand(time(0));
	number = rand()%5+1;
	int guess;
	int count=1;
	do {
		printf("Enter your guess: \n");
		scanf("%d",&guess);
		if (guess>number)
		{
			printf("lower number please\n");
		}
		else if (number>guess)
		{
			printf("higher number please! \n");
		}
		else
		{
			printf("Guessed it right in %d attempts \n",count);
		}
		count++;	
	}
	while (guess!=number);
	printf("FOUND THE NUMBER: %d \n",number);
	printf("Attempts taken: %d",count);
	return 0;
}
