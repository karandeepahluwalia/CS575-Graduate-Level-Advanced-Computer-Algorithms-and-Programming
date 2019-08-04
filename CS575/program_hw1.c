#include <stdio.h>
#include <stdlib.h>



void read_in_data(char *argv[]){
  FILE *market = fopen ( argv[1], "r" );
  FILE * pricelist = fopen ( argv[1], "r" );
  FILE *f = fopen("output.txt", "w");
  if (f == (char) 0){
    //printf("Error opening file\n");
  }
  if ( file != NULL ){
    char line[35];
    ////printf("Reaches here");
    while (fgets(line,sizeof line,file)!= (char) 0){
      //printf("How many");
      deal_cards(line,&plyr1,&plyr2,&plyr3,&cards);
      ////printf("%c%c %c%c \n",plyr1.card1.number,plyr1.card2.suit,plyr1.card2.number,plyr2.card2.suit);
      ////printf("%c%c %c%c \n",plyr2.card1.number,plyr2.card2.suit,plyr2.card2.number,plyr2.card2.suit);
      ////printf("%c%c\n",cards.cards[0].number,cards.cards[0].suit);
      evalaute_hand(&plyr1,&plyr2,&plyr3,&cards,f);
    }
  }
  fclose(f);
}
