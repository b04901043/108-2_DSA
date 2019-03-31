#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int binarySearch(vector<int> A,int key,int left,int right){
	while (left<=right){
		int mid=left+(right-left)/2;
		if(A[mid]==key)
			return mid;
		if(A[mid]<=key)
			left=mid+1;
		else right=mid-1;
	}
	return -1;
}

int main()
{
	vector<int>::iterator it;

    vector<int> sorted_array;
    sorted_array.push_back(3);
    sorted_array.push_back(5);
    sorted_array.push_back(6);
    sorted_array.push_back(8);
    sorted_array.push_back(34);
    sorted_array.push_back(70);
    for(it=sorted_array.begin();it<sorted_array.end();it++)
    	cout<<*it<<endl;
    cout<<"insert a num"<<endl;
    it = sorted_array.begin();

    sorted_array.insert(it+2,2);
    for(it=sorted_array.begin();it<sorted_array.end();it++)
    	cout<<*it<<endl;
    

 


}

