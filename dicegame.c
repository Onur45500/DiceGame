
/* dicegame.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int randomNumber(int max)
{
	int random;
	
	random = rand() % max + 1;

	return random;
}

int main()
{
	int diceFaces = 6;
	int money = 1000;
	int dice;
	int bet;
	int betFace;
	
	srand(getpid());
	dice = randomNumber(diceFaces);
	printf("Bet 0€ to quit the game\n");
	printf("You have : %d€\n", money);

	while(1)
	{
		
		printf("What is your bet ?\n");
 		fflush(stdout);
		scanf("%d", &bet);
		if(bet > money)
		{
			printf("You don't have enough money to bet this amount\n");
			continue;
		}
		else if(bet == 0)
			break;

		printf("On what face of the dice will you bet ?\n");
		fflush(stdout);
		scanf("%d", &betFace);
		sleep(1);

		printf("The dice is rolling...\n");
		sleep(2);
		printf("Dice : %d\n", dice);
	
		if(dice != betFace)
		{
			money = money - bet;
			sleep(1);
			printf("You loosed : %d€\n", bet);
			sleep(1);
			printf("Actual money : %d€\n", money);
		}
		else if(dice == betFace)
		{
			money = money + bet * 3;
			sleep(1);
			printf("You winned : %d€\n", bet*3);
			sleep(1);
			printf("Actual monney : %d€\n", money);	
		}
		
		if(money <= 0)
			break;
	}	

	
	printf("End of the game\n");
	return 0;
}
