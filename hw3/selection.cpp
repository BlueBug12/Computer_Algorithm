#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int* read_file(const char* file_name, int* size, int* rank){
	fstream file;
	file.open(file_name,ios::in);
	if(!file){
		cout<<"Can not open input file!"<<endl;
    exit(1);
	}
	string input;
	file>>input;
	*size = stoi(input);
  file>>input;
  *rank = stoi(input);

	int* list = new int[*size];
	for(int i=0;i<*size;++i){
		file>>input;
		list[i]=stoi(input);
	}
	return list;
}

int insertion_sort(int* list, const int size){
	int key,j;
	for(int i=1;i<size;++i){
		key = list[i];
		j = i -1;
		while(j>=0&&list[j]>key){
			list[j+1]=list[j];
			j-=1;
		}
		list[j+1]=key;
	}
  return list[size/2];//return the median of list
}
int find_median(int* list, const int size){

  if(size==1){return list[0];}
	int median_size = size/5+(size%5)%2;
	int* median_list=new int[median_size];
  for(int i=0;i<size;i+=5){
    if((size-i)<5)
			median_list[i/5]=insertion_sort(list+i,size-i);

    else
			median_list[i/5]=insertion_sort(list+i,5);
  }

	int target;
  if(median_size<=5){
		target=insertion_sort(median_list,median_size);
	}
  else{
		target=find_median(median_list,median_size);
	}
	delete[] median_list;
	return target;
}
int find_index(int* list,const int size,const int median){
    for (int i = 0; i <size; ++i){
        if (list[i] == median)
            return i;
    }
		cout<<"Can't find the index !"<<endl;
    return -1;
}
int selection(int* list,int size, int rank){
    int median = find_median(list,size);
    int index = find_index(list,size,median);
    //before partion, swap the pivot element and the left element
    swap(list[index], list[0]);
    //partion
    int pivot = list[0];
    int i = 0;
    int j = size;
    do{
      do i++;while(list[i]<pivot);
      do j--;while(list[j]>pivot);
      if(i<j)swap(list[i],list[j]);
    }while(i<j);
    swap(list[0],list[j]);

    if (j == rank)
        return list[j];
    else if(j > rank)
        return selection(list,j,rank);
    else
        return selection(list+j+1,size-j-1,rank-j-1);
}

int main(int argc, char **argv){

  if(argc!=2){cout<<"Wrong input parameters!"<<endl;exit(1);}
  int size,rank;
  int* list = read_file(argv[1],&size,&rank);

  if(rank>size){
    cout<<"Invalid rank!"<<endl;
    return 1;
  }
  int i = selection(list,size,--rank);

  cout << i << endl;
  delete[] list;
  return 0;
}
