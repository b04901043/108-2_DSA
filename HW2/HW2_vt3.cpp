#include <iostream>
using namespace std;

#define ALPHABET_SIZE (26)
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    struct TrieNode *father[18];
    int  depth;
}; 

struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->depth = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
};

struct TrieNode *insert(struct TrieNode *root, char key) 
{ 
	struct TrieNode *pCrawl = root; 

	int index = key - 'a'; //store index of a=0 b=1
   // cout<<index<<endl;
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode(); 
          //  cout<<"get new node"<<endl;
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

    return pCrawl;
};
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
    while(com1->depth > com2->depth){
		//cout<<"com1 up";
		com1=com1->father[0];
	}
	while(com1->depth < com2->depth){
		//cout<<"com2 up";
		com2=com2->father[0];
	}
    if(com1==com2) return com1->depth;

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
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int input_n;
    cin>>input_n;

	TrieNode *Triedata[input_n+1];
    Triedata[0] = getNode();
    for(int i=0;i<18;i++)
        Triedata[0]->father[i]=Triedata[0];
    int j,k;
    char ch1;
    for(int i=1;i<=input_n;i++){
    	cin>>j>>ch1;
    	Triedata[i] = insert(Triedata[j],ch1); 
    }

    int test_n;
    cin>>test_n;
    for(int i=0;i<test_n;i++){
    	cin>>j>>k;

    	cout<<LCP(Triedata[j],Triedata[k])<<'\n';
    }

}