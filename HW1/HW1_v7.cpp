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

int locationSearch(vector<int> A,int key,int left,int right){
	int k=right;
	while (left<=right){
		int mid=left+(right-left)/2;
		if(A[mid]>=key && A[mid-1]<=key)
			return mid;
		if(A[mid]>=key && A[mid-1]>=key)
			right=mid-1;
		else left=mid+1;
	}
	if(right==0)return 0;
	else return k;
}

int main()
{

    int N;
    int M;
    int K;

    cin>>N>>M>>K;

	int ouputlength=N-M+1;    
    int output;
    vector<int> sorted_array;
    deque<int> unsorted_array;
    int buffer;
    int replaced_num;

    for(int i=0;i<M;i++){
    	cin>>buffer;
    	sorted_array.push_back(buffer);
    	unsorted_array.push_back(buffer);
    }
    sort(sorted_array.begin(), sorted_array.end()); 


	int j;
	vector<int>::iterator it;
	int insert_num;

	//cout<<"The answer:"<<endl;
	for(int i=0;i<ouputlength;i++){
		output=sorted_array[K-1];
		cout<<output<<"\n";
		if((ouputlength-1)!=i){
			cin>>buffer;
			//remove orgindata[i]
			replaced_num=binarySearch(sorted_array,unsorted_array[0],0,M);
			unsorted_array.pop_front();
			//insert buffer to sorted_array
			it=sorted_array.begin();
			//cout<<replaced_num;
			//cout<<"Removed :"<<*(it+replaced_num)<<endl;
			sorted_array.erase(it+replaced_num);

			insert_num=locationSearch(sorted_array,buffer,0,M-1);
			//cout<<"insert :"<<insert_num<<endl;
			it=sorted_array.begin();
			sorted_array.insert(it+insert_num,buffer);

			
			unsorted_array.push_back(buffer);
		}
	}


}

