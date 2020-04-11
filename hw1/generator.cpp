#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char**argv){
	srand(time(NULL));
	fstream file;
	int size = atoi(argv[1]);
	int list[size];
	file.open("input.text",ios::out);
	if(!file){
		cout<<"Can not open file!"<<endl;
		exit(1);
	}
	for(int i=0;i<size;++i){
		list[i]=i;
	}
	for(int i=0;i<size;++i){
		int j=rand()%size;
		swap(list[i],list[j]);
	}
	file<<size<<endl;
	for(int i=0;i<size;++i){
		file<<list[i]<<endl;
	}
	file.close();
	return 0;

}
