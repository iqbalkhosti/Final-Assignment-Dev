#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <math.h>
//#include <Windows.h>
#include <unistd.h>
using namespace std;



struct Deck{
        vector<string> deck{"A♠","2♠","3♠","4♠","5♠","6♠","7♠","8♠","9♠","10♠","J♠","Q♠","K♠", 
                             "A♥","2♥","3♥","4♥","5♥","6♥","7♥","8♥","9♥","10♥","J♥","Q♥","K♥",
                            "A♦","2♦","3♦","4♦","5♦","6♦","7♦","8♦","9♦","10♦","J♦","Q♦","K♦", 
                            "A♣" ,"2♣","3♣","4♣","5♣","6♣","7♣","8♣","9♣" ,"10♣" ,"J♣","Q♣","K♣" 
};



            void Shuffle(){
                 for(int i=0;i<52;i++){
                     swap(deck.at(i),deck.at(rand()%52));
                     
                    
                }
                // wait=deck[rand()%51];
                // deck[rand()%51]="0";
                // for(int i=0,i<52,i++){
                //     string wait2;
                    
                }
            string Draw(){
                string draw=deck.back();
                deck.pop_back();
                return draw;
            }
                
            void Restock(){
                deck={/*"A♠","2♠","3♠","4♠","5♠","6♠","7♠","8♠","9♠","10♠","J♠","Q♠","K♠",*/
                            "A♥","2♥","3♥","4♥","5♥","6♥","7♥","8♥","9♥","10♥","J♥","Q♥","K♥",
                            "A♦","2♦","3♦","4♦","5♦","6♦","7♦","8♦","9♦","10♦","J♦","Q♦","K♦",
                            "A♣"/*,"2♣","3♣","4♣","5♣","6♣","7♣","8♣","9♣"*/,"10♣"/*,"J♣","Q♣","K♣"*/};
            
            }    
                
                    
            
            
                        



};
int BValuecheck(vector<string> deck){
                int value=0;
                 for(int i=0;i<deck.size();i++){
                     if (deck.at(i).find("A") != std::string::npos) {
                             value=value+11;
                        }
                     if (deck.at(i).find("2") != std::string::npos) {
                             value=value+2;
                        }
                     if (deck.at(i).find("3") != std::string::npos) {
                             value=value+3;
                        }
                     if (deck.at(i).find("4") != std::string::npos) {
                             value=value+4;
                        }
                     if (deck.at(i).find("5") != std::string::npos) {
                             value=value+5;
                        }
                     if (deck.at(i).find("6") != std::string::npos) {
                             value=value+6;
                        }
                     if (deck.at(i).find("7") != std::string::npos) {
                             value=value+7;
                        }
                     if (deck.at(i).find("8") != std::string::npos) {
                             value=value+8;
                        }
                     if (deck.at(i).find("9") != std::string::npos) {
                             value=value+9;
                        }
                     if (deck.at(i).find("10") != std::string::npos) {
                             value=value+10;
                        }
                     if (deck.at(i).find("J") != std::string::npos) {
                             value=value+10;
                        }
                     if (deck.at(i).find("Q") != std::string::npos) {
                             value=value+10;
                        }
                     if (deck.at(i).find("K") != std::string::npos) {
                             value=value+10;
                        }
                     if (deck.at(i).find("A") != std::string::npos && value>21) {
                             value=value-10;
                        }

                }




return value;

}

void    StartHand(Deck &deck,vector<string> &Hand){
                                      //creates initial hand
                
                Hand.push_back(deck.Draw());
                Hand.push_back(deck.Draw());
                cout<<"Current Hand: {";
                for(int i=0;i<Hand.size();i++){
                    cout<<" "<<Hand.at(i);
                    }
                cout<<" }"<<endl;
                if(BValuecheck(Hand)>21){
                    cout<<"It's a bust, Hand value: "<<BValuecheck(Hand)<<endl;
                }
                if(BValuecheck(Hand)==21){
                    cout<<"congrats you are a winner"<<endl;
                }
            }

int main(){
    srand(time(NULL));
        
        int wallet=50;
        int wager;
        Deck a;
        bool playmore=false;

        while(!playmore){
        vector<string> Hand1;            
            
            bool winner=false;
            int cardcount=2;
            a.Shuffle();
            cout<<"What would you like to wager"<<endl;
            cin>>wager;
            wallet=wallet-wager;
            StartHand(a,Hand1);
            if(BValuecheck(Hand1)>21){
                   winner=true;
                }
             if(BValuecheck(Hand1)==21){
                   winner=true;
                }
            while(!winner){
               
            
                Hand1.push_back(a.Draw());
                cardcount++;
                if(BValuecheck(Hand1)==21){
                    cout<<"congrats you are a winner"<<endl;
                            
                            winner=true;
                    break;
            
                }
                if(BValuecheck(Hand1)>21){ //checks if initial hand value is over 21
                    cout<<"It's a bust, Hand value: "<<BValuecheck(Hand1)<<endl;
                    cout<<"Current Hand: {";
                    for(int i=0;i<Hand1.size();i++){
                        cout<<" "<<Hand1.at(i);
                        }
                    cout<<" }"<<endl;
                    break;
                }
                cout<<"Current Hand: {";
                    for(int i=0;i<Hand1.size();i++){
                        cout<<" "<<Hand1.at(i);
                        }
                cout<<" }"<<endl;
                
                cout<<"Would you like to hold?"<<endl;
                string choice;
                cin>>choice;
                if(choice=="yes"){
                    cout<<"Final Hand value: "<<BValuecheck(Hand1)<<endl;
                    if(BValuecheck(Hand1)==21){
                        cout<<"congrats you are a winner "<<endl;
                            
                            winner=true;
                        }
                        cout<<"How unfortunate quit before you made it big ";
                        
                        break;   
                    }
            
            
        
        
        
            }
            if(winner==true&&BValuecheck(Hand1)==21){
            wallet=wager*1.5+wallet;
            }
            cout<<"Wallet value: "<<wallet<<endl;
            cout<<"Would you like to play more?"<<endl;
            string choice;
            cin>>choice;
            if(choice=="yes"){
                    playmore=false;  
                    }
            else{
                playmore=true;
            }
            a.Restock();
        }
        
        



    return 0;
}