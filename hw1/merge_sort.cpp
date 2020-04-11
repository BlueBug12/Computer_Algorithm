#include<iostream>
#include<fstream>
#include<string>
#include<climits>
#include <cstdlib>
#include <ctime>
using namespace std;

int* read_file(const char* file_name, int& size){
	fstream file;
	file.open(file_name,ios::in);
	if(!file){
		cout<<"Can not open file!"<<endl;
	}
	string input;
	file>>input;
	size = stoi(input);
	int* list = new int[size];
	for(int i=0;i<size;++i){
		file>>input;
		list[i]=stoi(input);
	}
	return list;

}
void write_file(const int* list, int size){
	fstream file;
	file.open("output.txt",ios::out);
	if(!file){
		cout<<"Can not open file!"<<endl;
		exit(1);
	}
	file<<size<<endl;
	for(int i=0;i<size;++i){
		file<<list[i]<<endl;
	}
	file.close();

}



void merge(int* list,const int left,const int right){
	int mid = (right+left)/2;
	int* lsub = new int[mid-left+2];
	int* rsub = new int[right-mid+1];
	for(int i=left;i<=mid;++i){
		lsub[i-left]=list[i];
	}
	lsub[mid-left+1]=INT_MAX;
	for(int i=mid+1;i<=right;++i){
		rsub[i-mid-1]=list[i];
	}
	rsub[right-mid]=INT_MAX;
	int indexl=0;
	int indexr=0;
	for(int i=left;i<=right;++i){
		if(lsub[indexl]<=rsub[indexr]){
			list[i]=lsub[indexl];
			++indexl;
		}
		else{
			list[i]=rsub[indexr];
			++indexr;
		}
	}
	delete []lsub;
	delete []rsub;
}

int merge_sort(int* list, const int left,const int right){
	//recursion version of merge sort
	if(left==right){return left;}
	int mid = (right+left)/2;
	merge_sort(list,left,mid);
	merge_sort(list,mid+1,right);
	merge(list,left,right);
}

void merge_sort(int* list, int size){
	merge_sort(list,0,size-1);
}

int main(int argc, char **argv){
	int size = 0;
	int* list = read_file(argv[1],size);
	clock_t start,end;
  double cpu_time_used;
	start = clock();
	merge_sort(list,size);
	end = clock();
	cpu_time_used = (double(end - start)) / CLOCKS_PER_SEC;
  cout<<"Merge sort take "<<cpu_time_used<<" s to finish."<<endl;
	write_file(list,size);
	delete [] list;
	return 0;

}
