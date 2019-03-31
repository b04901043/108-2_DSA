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

    int N;
    int M;
    int K;

    cin>>N>>M>>K;

	int ouputlength=N-M+1;    
    int output[ouputlength];
    vector<int> sorted_array;
    deque<int> unsorted_array;
    int orgindata[N];
    int buffer;
    int replaced_num;

    for(int i=0;i<M;i++){
    	cin>>buffer;
    	orgindata[i]=buffer;
    	sorted_array.push_back(buffer);
    	unsorted_array.push_back(buffer);
    }
    sort(sorted_array.begin(), sorted_array.end()); 


	int j;


	//cout<<"The answer:"<<endl;
	for(int i=0;i<ouputlength;i++){
		output[i]=sorted_array[K-1];
		cout<<output[i]<<"\n";
		if((ouputlength-1)!=i){
			cin>>buffer;
			unsorted_array.push_back(buffer);

			//remove orgindata[i]
			replaced_num=binarySearch(sorted_array,unsorted_array[0],0,M);
			//insert buffer to sorted_array
			sorted_array[replaced_num]=buffer;
			while(sorted_array[replaced_num]<sorted_array[replaced_num-1] && (replaced_num)!=0){
				j=sorted_array[replaced_num-1];
				sorted_array[replaced_num-1]=sorted_array[replaced_num];
				sorted_array[replaced_num]=j;
				replaced_num=replaced_num-1;
			}
			while(sorted_array[replaced_num]>sorted_array[replaced_num+1] && (replaced_num)!=M){
				j=sorted_array[replaced_num+1];
				sorted_array[replaced_num+1]=sorted_array[replaced_num];
				sorted_array[replaced_num]=j;
				replaced_num=replaced_num+1;
			}
			unsorted_array.pop_front();
		}
	}


}

