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
    pCrawl = pCrawl->children[index]; 
    cout<<pCrawl<<"   "<<endl;
    cout<<"My depth is "<<pCrawl->depth<<endl;
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
    return pCrawl;
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

    int j;
    char ch1;
    for(int i=1;i<=input_n;i++){
        test1>>j>>ch1;

        cout<<"Add input "<<i<<" to node "<<j<<" with string "<<ch1<<endl;
        Triedata[i] = insert(Triedata[j],ch1); 
    }


  }