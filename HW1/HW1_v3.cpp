#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
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

int main(int argc, char* argv[])
{
	ifstream test1;
	test1.open(argv[1]);
	if(!test1){ 
        return 1; 
    }

    int N;
    int M;
    int K;

    test1>>N>>M>>K;

	int ouputlength=N-M+1;    
    int output;
    vector<int> sorted_array;
    deque<int> unsorted_array;
    int orgindata[N];
    int buffer;
    int replaced_num;

    for(int i=0;i<M;i++){
    	test1>>buffer;
    	orgindata[i]=buffer;
    	sorted_array.push_back(buffer);
    	unsorted_array.push_back(buffer);
    }
    sort(sorted_array.begin(), sorted_array.end()); 


	int j;
	// open a file in write mode.
	ofstream outfile;
	outfile.open(argv[2]);

	//cout<<"The answer:"<<endl;
	for(int i=0;i<ouputlength;i++){
		output=sorted_array[K-1];
		cout<<output<<"\n";
		outfile<<output<<'\n';

		test1>>buffer;
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

	// close the opened file.
	test1.close();
	outfile.close();


}

