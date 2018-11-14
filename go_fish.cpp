// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


void takeTurn(Deck &d, Player &currPlayer, Player &otherPlayer,Card c1){



//        while(otherPlayer.sameRankInHand(c1) && otherPlayer.getHandSize() > 0){//change
//     for(int i=0;i<otherPlayer.getHandSize();i++){
    Card card = otherPlayer.removeCardFromHand(c1);
    currPlayer.addCard(card);

    Card temp1,temp2;

//    if(currPlayer.checkHandForBook(temp1,temp2)){

//    }

 //   }
//}

//        if(otherPlayer.getHandSize() == 0 && d.size() > 0){// change
//            int n = 7;
  //          dealHand(d,otherPlayer,n);
 //       }



//        while(currPlayer.checkHandForBook(temp1,temp2)){
//    if(currPlayer.checkHandForBook(temp1,temp2)){
        currPlayer.bookCards(c1,card);
        currPlayer.removeCardFromHand(c1);
        currPlayer.removeCardFromHand(card);



//    }
//}

//    cout << currPlayer.getName() << " has : " << currPlayer.getBookSize() << endl;
//    cout << otherPlayer.getName() << " has : " << otherPlayer.getBookSize() << endl;
//    cout << currPlayer.getName() << " has : " << currPlayer.getHandSize() << endl;
//    cout << otherPlayer.getName() << " has : " << otherPlayer.getHandSize() << endl;

}

int main( ) {

    ofstream myfile("gofish_results.txt");

    int numCards = 7;

    bool sucessRequest = false;

    Player p1("Neo");
    Player p2("Smith");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Player *currPlayer = &p1;
    Player *otherPlayer = &p2;
    Player *temp;


    Card c1;
    Card c2;

    while (p1.checkHandForBook(c1, c2)) {//ASK!!
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }

    while (p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }


    while (((p1.getBookSize()) / 2) + ((p2.getBookSize()) / 2) < 26) {

        if (currPlayer->getName() == p1.getName()) {

            c1 = currPlayer->chooseCardFromHand();

            string rank = c1.rankString(c1.getRank());
            cout << currPlayer->getName() << " asks - Do you have a " << rank << "?" << endl;

            if (myfile.is_open()) {
                myfile << currPlayer->getName() << " asks - Do you have a " << rank << "?" << endl;

            } else {

                cout << "Unable to Open." << endl;
            }


            if (p2.sameRankInHand(c1)) {
                takeTurn(d, *currPlayer, *otherPlayer, c1);
            } else {
                cout << p2.getName() << " says - Go Fish" << endl;
                myfile << p2.getName() << " says - Go Fish " << rank <<endl;

                if(d.size()<52){
                    Card addHand = d.dealCard();
                    p1.addCard(addHand);
                }

                else{
                    while (p1.checkHandForBook(c1, c2)) {//ASK!!
                        p1.bookCards(c1, c2);
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);
                    }
                }

                temp = currPlayer;
                currPlayer = otherPlayer; //ASK!!!!
                otherPlayer = temp;
            }

        }


        if (currPlayer->getName() == p2.getName()) {

            if(currPlayer->getHandSize()>0){

            }

            c1 = currPlayer->chooseCardFromHand();
            string rank = c1.rankString(c1.getRank());
            cout << currPlayer->getName() << " asks - Do you have a " << rank << "?" << endl;

            if (myfile.is_open()) {
                myfile << currPlayer->getName() << " asks - Do you have a " << rank << "?" << endl;

            } else {
                cout << "Unable to Open." << endl;
            }

                if (p1.sameRankInHand(c1)) {
                    takeTurn(d, *currPlayer, *otherPlayer, c1);
                } else {
                    cout << p1.getName() << " says - Go Fish" << endl;
                    myfile << p1.getName() << " says - Go Fish " << endl;

                    if(d.size()<52){
                        Card addHand = d.dealCard();
                        p2.addCard(addHand);
                    }

                    else{
                        while (p2.checkHandForBook(c1, c2)) {
                            p2.bookCards(c1, c2);
                            p2.removeCardFromHand(c1);
                            p2.removeCardFromHand(c2);
                        }
                    }

                    temp = currPlayer;
                    currPlayer = otherPlayer;
                    otherPlayer = temp;
                }

            }

        }



//    myfile << p1.getName() << " has : " << p1.showBooks() << endl;
//    myfile << p2.getName() << " has : " << p2.showBooks() << endl;

    if(p1.getBookSize()>p2.getBookSize()){
        myfile << p1.getName() << " has won. " << endl;
        myfile << p1.getName() << " has : " << (p1.getBookSize())/2 << " books." << endl;
    } else{
        myfile << p2.getName() << " has won. " << endl;
        myfile << p2.getName() << " has : " << (p2.getBookSize())/2 << " books." << endl;
    }

    myfile.close();

     cout << p1.getName() << " has : " << p1.getBookSize() << endl;
     cout << p2.getName() << " has : " << p2.getBookSize() << endl;
    cout << p1.getName() << " has : " << p1.getHandSize() << endl;
    cout << p2.getName() << " has : " << p2.getHandSize() << endl;

     return EXIT_SUCCESS;

}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



