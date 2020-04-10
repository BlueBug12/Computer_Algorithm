#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(NULL));
	fstream file;
	int list[100000];
	file.open("input.text",ios::out);
	if(!file){
		cout<<"Can not open file!"<<endl;
		exit(1);
	}
	for(int i=0;i<100000;++i){
		list[i]=i;
	}
	for(int i=0;i<100000;++i){
		int j=rand()%100000;
		swap(list[i],list[j]);
	}
	file<<100000<<endl;
	for(int i=0;i<100000;++i){
		file<<list[i]<<endl;
	}
	file.close();
	return 0;

}
