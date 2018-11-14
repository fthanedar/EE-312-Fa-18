#include "deck.h"
#include <iostream>
#include <string>
using namespace std;

Deck:: Deck(){

   int suit=0;
   int rank=0;
   int count = 0;
   int i=0;
Card card;
card.spades;

   for(suit= card.spades;suit<=card.clubs;suit++){

       for(rank=1;rank<=13;rank++){
           myCards[i++]= Card(rank,(Card::Suit)suit);
       }

   }

     /* while(count < 52){
       Card card = Card(rank,(Card::Suit)suit);
       myCards[count] = card;
       rank++;
       count++;

       if((rank%13) == 0){
           suit++;
           rank=0;
       }

   }*/

    myIndex=0;

}

 // pristine, sorted deck

void Deck :: shuffle(){

    Card card1;
    Card card2;
    unsigned int currentTime =  (unsigned)time(0);
    cout << "current time " << currentTime << endl;
    srand(currentTime);  //seed the random number generator

   for (int i=0; i<SIZE ;i++) {
        // Random for remaining positions.
        int j = (rand() % (52));
        card1=myCards[i];
        card2=myCards[j];
        myCards[i]=card2;
        myCards[j]=card1;
    }

//   Card endCard= myCards[52];
//   endCard.

};   // shuffle the deck, all 52 cards present

int Deck:: size() const{

    return  myIndex;

}; // # cards left in the deck

Card Deck :: dealCard(){

    Card card;

    if(myIndex < SIZE){
        card = myCards[myIndex];
        myIndex++;
        return card;
    }

    /*else{

        card = Card(-1, (Card::Suit))

    }
*/



};