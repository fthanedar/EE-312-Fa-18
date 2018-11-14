#include <iostream>
#include <string>
#include <vector>
#include "player.h"
using namespace std;


Player :: Player(){

    myName="";
    vector <Card> myHand;
    vector <Card> myBook;

};


void Player :: addCard(Card c){

    myHand.push_back(c);

};  //adds a card to the hand

void Player :: bookCards(Card c1, Card c2){

    if(c1.getRank() == c2.getRank()){
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

};

string Player :: showHand() const{

    int i=0;

    while(i<myHand.size()){
        Card card=myHand[i];
        string print= card.toString();
        cout<<print<<endl;
        i++;
    }

};
string Player :: showBooks() const{

    int i=0;

    while(i<myBook.size()){
        Card card=myBook[i];
        string print= card.toString();
        Card card2=myBook[i++];
        string print2= card.toString();

        if(card2.getRank() == card.getRank()){
            cout<<print<<endl;
        }

        i++;
    }

    // After booking remember to remove card from hand

};

int Player :: getHandSize() const{

         return static_cast<int>(myHand.size());

}

int Player :: getBookSize() const{

    return static_cast<int>(myBook.size());

}

Card Player :: removeCardFromHand(Card c){

    int i=0;
    bool check = false;

    while(i<myHand.size()){

        if(myHand[i].getRank() == c.getRank() ){ //changed
            check = true;
            c = myHand[i];
            break;
        }

        i++;

    }

    if(check){
        myHand.erase(myHand.begin()+i);
    }

    return c;


}

bool Player :: checkHandForBook(Card &c1, Card &c2){

    int i = 0;
    int j = 0;

    for(i;i<myHand.size();i++){

        c1 = myHand[i];

        for(j=i+1;j<myHand.size();j++){

            if(c1.getRank() == myHand[j].getRank()){
                c2=myHand[j];
                return true;
            }

        }

    }

   return false;

}

bool Player :: sameRankInHand(Card c) const{

    int i = 0;

    while(i<myHand.size()){

        if(myHand[i].getRank() == c.getRank()){
            return true;
        }

    i++;

    }

    return  false;

}

Card Player :: chooseCardFromHand() const {

//    if(myHand.size()>0){
        int j = (rand() % (myHand.size()));
        Card card = myHand[j];
        return card;
//    }

}
