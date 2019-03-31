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

#define ALPHABET_SIZE (26)		// Alphabet size (# of symbols)

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    struct TrieNode *father[18];
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
          //  cout<<"get new node"<<endl;
        }
        else{
        	//cout<<"no new node"<<endl;
        }
   // cout<<pCrawl<<"-->";
    pCrawl->children[index]->depth = (pCrawl->depth)+1;


    pCrawl->children[index]->father[0] = pCrawl;
    pCrawl->children[index]->father[1] = pCrawl->father[0];
    pCrawl->children[index]->father[2] = pCrawl->father[0]->father[1];
    pCrawl->children[index]->father[3] = pCrawl->father[1]->father[1];
    pCrawl->children[index]->father[4] = pCrawl->father[1]->father[2];
    pCrawl->children[index]->father[5] = pCrawl->father[2]->father[2];
    pCrawl->children[index]->father[6] = pCrawl->father[2]->father[3];
    pCrawl->children[index]->father[7] = pCrawl->father[3]->father[3];
    pCrawl->children[index]->father[8] = pCrawl->father[3]->father[4];
    pCrawl->children[index]->father[9] = pCrawl->father[4]->father[4];
    pCrawl->children[index]->father[10] = pCrawl->father[4]->father[5];
    pCrawl->children[index]->father[11] = pCrawl->father[5]->father[5];
    pCrawl->children[index]->father[12] = pCrawl->father[5]->father[6];
    pCrawl->children[index]->father[13] = pCrawl->father[6]->father[6];
    pCrawl->children[index]->father[14] = pCrawl->father[6]->father[7];
    pCrawl->children[index]->father[15] = pCrawl->father[7]->father[7];
    pCrawl->children[index]->father[16] = pCrawl->father[7]->father[8];
    pCrawl->children[index]->father[17] = pCrawl->father[8]->father[8];



    pCrawl = pCrawl->children[index]; 
	//cout<<pCrawl<<"   "<<endl;
  	//cout<<"My depth is "<<pCrawl->depth<<endl;
  	//cout<<"My father is "<<pCrawl->father<<endl;
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
    return pCrawl;
} 
int LCP(struct TrieNode *com1,struct TrieNode *com2){
    int a,b,c;
    a=com1->depth - com2->depth;
    c=0;
    if(a>0){
        for(int i=0;i<18;i++){
            if(a%2==1){
                com1=com1->father[c];
            }
            a=a/2;
            c=c+1;
        }
    }else if(a<0){
        b=-a;
        for(int i=0;i<18;i++){
            if(b%2==1){
                com2=com2->father[c];
            }
            b=b/2;
            c=c+1;
        }
    }
    for(int i=17;i>=0;i--){
        if(com1->father[i]!=com2->father[i]){
            com1=com1->father[i];
            com2=com2->father[i];
        }
    }
    while(com1!=com2){
        com1=com1->father[0];
        com2=com2->father[0];
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
    for(int i=0;i<18;i++)
        Triedata[0]->father[i]=Triedata[0];
    int j,k;
    char ch1;
    for(int i=1;i<=input_n;i++){
    	test1>>j>>ch1;

    	//cout<<"Add input "<<i<<" to node "<<j<<" with string "<<ch1<<endl;
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