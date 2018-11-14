#include <iostream>
#include <string>
#include "card.h"
#include <cstring>
//#include <cstdlib>
#include <sstream>

using namespace std;


Card:: Card(){

    myRank=1;
    mySuit= spades;

}          // default, ace of spades

Card:: Card(int rank, Suit s){

    myRank = rank;
    mySuit = s;

}

string Card::toString() const {

    string card;
    int rankVal;
    string rank;
    string suit;
//    string out_string;
    stringstream ss;
    int base = 10;
    char buffer [33];
    rankVal= getRank();


    if(mySuit==spades){
        suit = "s";
    }

    if(mySuit==clubs){
        suit="c";
    }

    if(mySuit == hearts){
        suit = "h";
    }

    if(mySuit == diamonds){
        suit = "d";
    }

    if(rankVal == 1){
        rank = "A";
    }

    if(rankVal >1 && rankVal<11){
//        rank= to_string(rankVal);
        ss<<rankVal;
//        out_string = ss.str();
        rank = ss.str();

    }

    if(rankVal == 11){
        rank = "J";
    }

    if(rankVal == 12){
        rank = "Q";
    }

    if(rankVal == 13){
        rank = "K";
    }

    card =rank+suit;
    return card;

};  // return string version e.g. Ac 4h Js


bool Card:: sameSuitAs(const Card& c) const{

    if(c.mySuit == mySuit){
        return true;
    }

    return false;

}  // true if suit same as c
int Card:: getRank()                 const{

    return myRank;

};  // return rank, 1..13
string Card:: suitString(Suit s)const {

    string suit;

    if(s==spades){
        suit = "s";
    }

    if(s==clubs){
        suit="c";
    }

    if(s == hearts){
        suit = "h";
    }

    if(s == diamonds){
        suit = "d";
    }

};  // return "s", "h",...

string Card :: rankString(int r)const{

    string rank;
    stringstream ss;

    if(r == 1){
        rank = "A";
    }

    if(r >1 && r<11){
//        rank= to_string(r);
        ss << r;
        rank = ss.str();

    }

    if(r == 11){
        rank = "J";
    }

    if(r == 12){
        rank = "Q";
    }

    if(r == 13){
        rank = "K";
    }

    return rank;


};  // return "A", "2", ..."Q"


bool Card :: operator == (const Card& rhs) const{

    if(rhs.mySuit == mySuit && rhs.myRank == myRank){
        return true;
    }

    return  false;

};

bool Card :: operator != (const Card& rhs) const{

    if(rhs.mySuit != mySuit && rhs.myRank != myRank){
        return true;
    }

    return  false;
};

 ostream& operator << (ostream& out, const Card& c){
     out<<c.toString()<<endl;
    return out;
}

