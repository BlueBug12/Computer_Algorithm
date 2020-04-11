#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
void quickSort(int* n,const int left,const int right){
  if(left<right){
    int i=left;
    int j=right+1;
    int pivot=n[left];

    do{
      do i++;while(n[i]<pivot);
      do j--;while(n[j]>pivot);
      if(i<j)swap(n[i],n[j]);
    }while(i<j);

    swap(n[left],n[j]);
    quickSort(n,left,j-1);
    quickSort(n,j+1,right);
  }
}

int main(int argc, char **argv){
  int size;
  cout<<argv[1]<<endl;
  int* list= read_file(argv[1],size);

  clock_t start,end;
  double cpu_time_used;

  start = clock();
  quickSort(list,0,size-1);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout<<"Quick sort take "<<cpu_time_used<<" s to finish."<<endl;
  delete [] list;
}
