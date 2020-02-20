#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void makeCode(char secretCode[4][10])
{
 int i, randColor;
 for(i=0; i<4; i++)
 {
 randColor = 1 + rand() % 6; //creates a number
 switch(randColor) //converts number created to a string
 {
 case 1: strcpy(secretCode[i], "red"); break;
 case 2: strcpy(secretCode[i], "yellow"); break;
 case 3: strcpy(secretCode[i], "green"); break;
 case 4: strcpy(secretCode[i], "blue"); break;
 case 5: strcpy(secretCode[i], "white"); break;
 case 6: strcpy(secretCode[i], "black"); break;
}
}
}
void guess(char guessCode[4][10])
{
 int i;
 printf("\nEnter your guess:\n");
 for(i=0; i<4; i++)
 scanf("%s", guessCode[i]);
}
void codeCheck(char secretCode[4][10], char guessCode[4][10], int
*blackPeg, int *whitePeg)
{
 int i, j, checkSecret[4] = {1,1,1,1}, checkGuess[4] = {1,1,1,1};
 *blackPeg = *whitePeg = 0;
 for(i=0; i<4; i++) //if secret and guess's position and color are same, blackpeg increases and mark "check"
if(strcmp(guessCode[i], secretCode[i]) == 0)
 {
 ++*blackPeg;
 checkSecret[i] = checkGuess[i] = 0;
 }
 for(i=0; i<4; i++)
 for(j=0; j<4; j++)
 if(strcmp(secretCode[i],guessCode[j]) == 0 && checkGuess[i]
&& checkSecret[j] && i != j)
 {// determines crushes and eliminates extra whitePegs
 ++*whitePeg;
 checkSecret[j] = checkGuess[i] = 0;
 }
}
void displayGuess(char guessCode[4][10], int blackPeg, int whitePeg)
{
 int i;
 printf("\nYour Guess\t\t\t\tYour Score\n");
 for(i=0; i<4; i++)
 printf("%s ", guessCode[i]);
 printf("\t\t");
 for(i=0; i<blackPeg; i++)
 printf("black ");
 for(i=0; i<whitePeg; i++)
 printf("white ");
 printf("\n\n");
}
int main()
{
 srand(time(NULL));
 int i, option=1, blackPeg, whitePeg, wrongGuess;
 char secretCode[4][10], guessCode[4][10];
 while(1)
 {
 printf("MASTER MIND! \nPress 1 to start game \nPress any number to exit\n\n");
 scanf("%d", &option);
 if(option == 1)
{
 makeCode(secretCode);
 for(wrongGuess=1; wrongGuess<=12; wrongGuess++) //gives 12 rights to guess
 {
 guess(guessCode);
 codeCheck(secretCode, guessCode, &blackPeg, &whitePeg);
 displayGuess(guessCode, blackPeg, whitePeg);
 if(blackPeg == 4) //if player guess correct all, than the game finishes
 {
 printf("You Win!\n\n\n\n"); break;
 }
 }
 if(wrongGuess == 13) //if player cannot guess correct colors in 12 rounds, he losts
 printf("\nYou Lost!\nSecret Code: %s %s %s %s\n\n\n\n\n",
secretCode[0], secretCode[1], secretCode[2], secretCode[3]);
 }
 else
 exit(1);
 }
}
