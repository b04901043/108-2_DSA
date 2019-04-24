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
using namespace std;
void change(int a[]){
    a[2]=22;
}
unordered_map<unsigned long long, int> umap;
int main() 
{ 
    string c="1111000";
    c.append("1");
    bitset<64> b(c);
    unsigned long long a = b.to_ulong();
    printf("%llu\n", a);

    
 
	// inserting values by using [] operator
	umap[a] = 120;
	c.append("1");

   // bitset<64> b1(c);
	//cout<<umap.find(a)->second<<endl;
    //unsigned long long a2 = b1.to_ulong();
    //cout<<umap.find(a2)->first;
	//if(umap.find(a2)==umap.end())
	//	cout<<"not found";

	unsigned long long aaa=0;
	aaa+=1;
	aaa*=2;
	cout<<aaa;
}