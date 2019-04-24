#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
struct card
{
    char suit;
    int number;
    bool status; //true for available
};
bool isEnd(card A[], int num){
    for(int i=0;i<num;i++){
        if(A[i].status==true)return false;
    }
    return true;
}
int gameScore(card A[], int num){
    int score=0;
    for(int i=0;i<num;i++){
        if(A[i].status==true) score+=A[i].number;
    }
    return score;
}
bool nothingPlay(card last, card A[], int num){
    for(int i=0;i<num;i++){
        if(A[i].status==true){
            if(A[i].suit==last.suit)return false;
            if(A[i].number==last.number)return false;
        }
    }
    return true;
}
int Bob_play(int , card [], card [],int );
int Alice_play(int play_num, card A[],card B[], int num){
    int score=-1,out;
    if(isEnd(B,num))return gameScore(A,num);
    if(nothingPlay(B[play_num],A,num)) out=Bob_play(-1,A,B,num);
    else{
        for(int i=0;i<num;i++){
            if(A[i].status==true){
                if(play_num==-1 || B[play_num].number==A[i].number || B[play_num].suit==A[i].suit){
                    A[i].status=false;
                    out=Bob_play(i,A,B,num);
                    if(out>score) out=score;
                }
            }
        }
    }
    return out;
}
int Bob_play(int play_num, card A[],card B[], int num){
    int score=-1,out;
    if(isEnd(A,num))return gameScore(B,num);
    if(nothingPlay(A[play_num],B,num)) out=Alice_play(-1,A,B,num);
    else{
        for(int i=0;i<num;i++){
            if(B[i].status==true){
                if(play_num==-1 || A[play_num].number==B[i].number || A[play_num].suit==B[i].suit){
                    B[i].status=false;
                    out=Alice_play(i,A,B,num);
                    if(out>score) out=score;
                }
            }
        }
    }
    return out;
}

int main(int argc, char* argv[]) 
{ 
    ifstream test1;
    test1.open(argv[1]);
    if(!test1){ 
        return 1; 
    }
    int numofcards;
    test1>>numofcards;
    card Alice_card[numofcards];
    card Bob_card[numofcards];
    for(int i=0;i<numofcards;i++){
        string a;
        test1>>a;
        Alice_card[i].suit=a[0];
        Alice_card[i].status=true;
        if(a[1]=='A')
            Alice_card[i].number=1;
        else if(a[1]=='T')
            Alice_card[i].number=10;
        else if(a[1]=='J')
            Alice_card[i].number=11;
        else if(a[1]=='Q')
            Alice_card[i].number=12;
        else if(a[1]=='K')
            Alice_card[i].number=13;
        else
            Alice_card[i].number=a[1]-'0';
    }
    for(int i=0;i<numofcards;i++){
        string a;
        test1>>a;
        Bob_card[i].suit=a[0];
        Bob_card[i].status=true;
        if(a[1]=='A')
            Bob_card[i].number=1;
        else if(a[1]=='T')
            Bob_card[i].number=10;
        else if(a[1]=='J')
            Bob_card[i].number=11;
        else if(a[1]=='Q')
            Bob_card[i].number=12;
        else if(a[1]=='K')
            Bob_card[i].number=13;
        else
            Bob_card[i].number=a[1]-'0';
    }
    int Alice_left=numofcards,Bob_left=numofcards;
    int a=0,out;
    //cout<<sizeof(Bob_card);
    for(int i=0;i<numofcards;i++){
        Alice_card[i].status=false;
        out=Alice_play(i,Alice_card,Bob_card,numofcards);
        if(out>a) a=out;
    }
    cout<<out<<'\n';

}