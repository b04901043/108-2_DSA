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

#define ALPHABET_SIZE (26)      // Alphabet size (# of symbols)

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    struct TrieNode *father;
    int  depth;
    bool isEndOfWord; 
}; 
 // Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false;
    pNode->depth = 0;
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
struct TrieNode *insert(struct TrieNode *root, char key) 
{ 
    struct TrieNode *pCrawl = root; 

    int index = key - 'a'; //store index of a=0 b=1
   // cout<<index<<endl;
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode(); 
            cout<<"get new node"<<endl;
        }
        else{
            cout<<"no new node"<<endl;
        }
    cout<<pCrawl<<"-->";
    pCrawl->children[index]->depth = (pCrawl->depth)+1;
    pCrawl->children[index]->father = pCrawl;
    pCrawl = pCrawl->children[index]; 
    cout<<pCrawl<<"   "<<endl;
    //cout<<"My depth is "<<pCrawl->depth<<endl;
    //cout<<"My father is "<<pCrawl->father<<endl;
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
    return pCrawl;
} 
int LCP(struct TrieNode *com1,struct TrieNode *com2){
    while(com1->depth > com2->depth){
        //cout<<"com1 up";
        com1=com1->father;
    }
    while(com1->depth < com2->depth){
        //cout<<"com2 up";
        com2=com2->father;
    }
    while(com1!=com2){
        com1=com1->father;
        com2=com2->father;
    }
    return com1->depth;
}
int main(int argc, char* argv[]) 
{ 
    ifstream test1;
    test1.open(argv[1]);
    if(!test1){ 
        return 1; 
    }
    int input_n;
    test1>>input_n;

    TrieNode *Triedata[input_n+1];

    Triedata[0] = getNode(); 
    Triedata[0]->father=Triedata[0];
    int j,k;
    char ch1;
    for(int i=1;i<=input_n;i++){
        test1>>j>>ch1;

        cout<<"Add input "<<i<<" to node "<<j<<" with string "<<ch1<<endl;
        Triedata[i] = insert(Triedata[j],ch1); 
    }
  /*  cout<<"8 10 "<<LCP(Triedata[8],Triedata[10])<<endl;
    cout<<"1  7 "<<LCP(Triedata[1],Triedata[7])<<endl;
    cout<<"3  7 "<<LCP(Triedata[3],Triedata[7])<<endl;
    cout<<"0  5 "<<LCP(Triedata[0],Triedata[5])<<endl;*/
    int test_n;
    test1>>test_n;
    for(int i=0;i<test_n;i++){
        test1>>j>>k;

        cout<<LCP(Triedata[j],Triedata[k])<<endl;
    }


  }