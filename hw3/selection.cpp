#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int* read_file(const char* file_name, int* size, int* rank){
	fstream file;
	file.open(file_name,ios::in);
	if(!file){
		cout<<"Can not open input file!"<<endl;
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
  //if(size==1)
    //return list[0];
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

  //return list[size/2-size%2];
  return list[size/2];//return the median of list
}
int find_median(int* list,int* median_list, const int size){

  if(size==1){return list[0];}


  for(int i=0;i<size;i+=5){
    if(size-i<5)
      median_list[i/5]=insertion_sort(list+i,size-i);
    else
      median_list[i/5]=insertion_sort(list+i,5);
  }

  if(size/5<=1)
    return median_list[0];
  else
    return find_median(median_list,median_list,size/5+(size%5)%2);
}
int find_index(int* list,const int size,const int median){
    for (int i = 0; i <size; ++i){
        if (list[i] == median)
            return i;
    }
    return -1;
}
int selection(int* list,int* median_list,int left, int right, int k){

    int median = find_median(list,median_list,left-right+1);

    int index = find_index(list,left-right+1,median);
    swap(list[index], list[right]);
    //partion
    int pivot = list[right];
    int i = left;
    int j = right - 1;
    while (true){
        while(list[i] < pivot)
            i++;
        while(list[j] > pivot)
            j--;
        if (i < j)
            swap(list[i], list[j]);
        else
            break;
    }
    swap(list[i], list[right]);
    int m = i - left + 1;

    if (m == k)
        return list[i];
    else if(m > k)
        return selection(list,median_list, left, i - 1, k);
    else
        return selection(list,median_list, i + 1, right, k - m);
}

int main(int argc, char **argv){

  if(argc!=2){cout<<"Wrong input parameters!"<<endl;}
  int size,rank;
  int* list = read_file(argv[1],&size,&rank);
  int* median_list = new int[size/5+1];
  int i = selection(list,median_list, 0, size-1, rank);

  cout << i << endl;
  delete[] median_list;
  return 0;
}
