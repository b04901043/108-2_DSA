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
#include <unordered_map>
#include <string>
#include <bitset>
#include <time.h>
using namespace std;
unordered_map<unsigned long long, int> umap;
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
ostream& operator<<(ostream& out, const card& cards) {
  out << "Card " << cards.suit << cards.number << ".\n";

  return out;
}
int Bob_play(int ,const card [],const card [], int, int, int);
int Alice_play(int play_num,const card AA[],const card BB[], int num, int alpha, int beta){
    card A[num],B[num];
    for(int i=0;i<num;i++){
        A[i]=AA[i];
        B[i]=BB[i];
    }
    if(play_num!=-1) B[play_num].status=false;

    unsigned long long c2,d2;
    if(play_num!=-1){
        string c="";
        for(int i=0;i<num;i++){
            if(A[i].status==true) c.append("1");
            else c.append("0");
        }
        for(int i=0;i<num;i++){
            if(B[i].status==true) c.append("1");
            else c.append("0");
        }
        c.append("1");//Alice play

        if(B[play_num].suit=='C') c.append("00");
        else if(B[play_num].suit=='D') c.append("01");
        else if(B[play_num].suit=='H') c.append("10");
        else if(B[play_num].suit=='S') c.append("11");

        if(B[play_num].number==1) c.append("0000");
        else if(B[play_num].number==2) c.append("0001");
        else if(B[play_num].number==3) c.append("0010");
        else if(B[play_num].number==4) c.append("0011");
        else if(B[play_num].number==5) c.append("0100");
        else if(B[play_num].number==6) c.append("0101");
        else if(B[play_num].number==7) c.append("0110");
        else if(B[play_num].number==8) c.append("0111");
        else if(B[play_num].number==9) c.append("1000");
        else if(B[play_num].number==10) c.append("1001");
        else if(B[play_num].number==11) c.append("1010");
        else if(B[play_num].number==12) c.append("1011");
        else if(B[play_num].number==13) c.append("1100");
        string d(c);
        c.append("0");//0 for alpha number;
        d.append("1");//1 for beta number;
        bitset<64> c1(c);
        bitset<64> d1(d);
        c2 = c1.to_ulong();
        d2 = d1.to_ulong();

        if(umap.find(c2)==umap.end()){
           // cout<<"not found\n";
        }
        else { 
           // cout<<"yeah\n";
            return umap.find(c2)->second;
        }
        

    }


    int score=-1000,out;
    if(isEnd(B,num)){
        int k=-gameScore(A,num);
        //cout<<"A win "<<k<<" score.\n";
        return k;
    }
    if(play_num!=-1){
        if(nothingPlay(B[play_num],A,num)) {
            out=Bob_play(-1,A,B,num,alpha,beta);
            if(alpha>out) alpha=out;
            if(out>score) score=out;
        }
        else{
            for(int i=0;i<num;i++){
                if(A[i].status==true){
                    if(B[play_num].number==A[i].number || B[play_num].suit==A[i].suit){
                        //cout<<A[i];
                        //A[i].status=false;
                        out=Bob_play(i,A,B,num,alpha,beta);
                        if(alpha<out) alpha=out;
                        if(out>score) score=out;
                        if(alpha>beta) {
                            //cout<<"break\n";
                            break;
                        }
                    }
                }
            }
        }
    }
    else{//Alice can play any kind of card
        for(int i=0;i<num;i++){
            if(A[i].status==true){
                //cout<<A[i];
               //A[i].status=false;
                out=Bob_play(i,A,B,num,alpha,beta);
                if(out>alpha) alpha=out;
                if(out>score) score=out;
                if(alpha>beta) {
                    //cout<<"break\n";
                    break;
                }
            }
        }
    }
    
    umap[c2]=score;
    umap[d2]=beta;

    return score;
}
int Bob_play(int play_num,const card AA[],const card BB[], int num,int alpha, int beta){
    card A[num],B[num];
    for(int i=0;i<num;i++){
        A[i]=AA[i];
        B[i]=BB[i];
    }
    if(play_num!=-1) A[play_num].status=false;
    int score=1000,out;
    if(isEnd(A,num)){
        int k=gameScore(B,num);
        //cout<<"A win "<<k<<" score.\n";
        return k;
    }
    if(play_num!=-1){
        if(nothingPlay(A[play_num],B,num)) {
            out=Alice_play(-1,A,B,num,alpha,beta);
            if(beta<out) beta=out;
            if(out<score) score=out;
        }
        else{
            for(int i=0;i<num;i++){
                if(B[i].status==true){
                    if(A[play_num].number==B[i].number || A[play_num].suit==B[i].suit){
                        //cout<<B[i];
                        //B[i].status=false;
                        out=Alice_play(i,A,B,num,alpha,beta);
                        if(beta>out) beta=out;
                        if(out<score) score=out;
                        if(alpha>beta) {
                            //cout<<"break\n";
                            break;
                        }
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<num;i++){
            if(B[i].status==true){
                //cout<<B[i];
                //B[i].status=false;
                out=Alice_play(i,A,B,num,alpha,beta);
                if(out<beta) beta=out;
                if(out<score) score=out;
                if(alpha>beta) {
                   // cout<<"break\n";
                    break;
                }
            }
        }
    }
    return score;
}

int main(int argc, char* argv[]) 
{ 
    // 儲存時間用的變數
    clock_t start, end;
    double cpu_time_used;
    start = clock();
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
    int alpha,beta;
    alpha=-10000;
    beta=10000;
    int out;
    out=Alice_play(-1,Alice_card,Bob_card,numofcards,alpha,beta);
    cout<<"The answer is: "<<out<<'\n';
   // cout<<out<<'\n';

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time = %f\n", cpu_time_used);

}