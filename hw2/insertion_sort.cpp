#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

void insertion(int* list, const int size){
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
}

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
int main(int argc, char **argv){
	int size = 0;
	int* list = read_file(argv[1],size);
	clock_t start,end;
  double cpu_time_used;
	start = clock();
	insertion(list,size);
	end = clock();
	cpu_time_used = (double(end - start)) / CLOCKS_PER_SEC;
  cout<<"Insertion sort take "<<cpu_time_used<<" s to finish."<<endl;
	write_file(list,size);
	delete [] list;
	return 0;

}
