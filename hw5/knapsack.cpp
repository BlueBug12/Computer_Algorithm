#include <iostream>
#include <fstream>
using namespace std;

//define the item's value and weight as a structure
struct item{
  int value;
  int weight;
  int index;
};

//read in the number of item, total weight constraint and all item attributes
item* read_file(const char* file_name, int* n, int* w){
	fstream file;
	file.open(file_name,ios::in);
	if(!file){
		cout<<"Can not open "<<file_name<<endl;
    exit(1);
	}
	int input;
	file>>input;
	*n = input;// number of item
  file>>input;
  *w = input;// corstraint weight
  int index=0;
	item* list = new item[*n];

  //read the item attributes
	for(int i=0;i<*n;++i){
		file>>input;
		list[i].value=input;
    file>>input;
    list[i].weight=input;
    //record the item index to recogniz which item we choose for the answer
    list[i].index=++index;
	}

  file.close();
  //return the item list
	return list;
}

void write_file(const int value, const int* list, const int size){
	fstream file;
	file.open("output.txt",ios::out);
	if(!file){
		cout<<"Can not open output.txt"<<endl;
		exit(1);
	}
  file<<"Total revenue = "<<value<<endl;
  file<<"Selected item : ";
  for(int i=0;i<size;++i){
    file<<list[i]<<" ";//print the selected items
  }
	file<<endl;
	file.close();
}

void knapsack(int n, int w, item* list, int* cost, item** record){
  for(int i=0;i<n;++i){
    for(int j=w;j>=list[i].weight;--j){
      if(cost[j-list[i].weight]+list[i].value>cost[j]){
        cout<<cost[j-list[i].weight]<<","<<list[i].value<<endl;
        cost[j] = cost[j-list[i].weight] + list[i].value;
        //record the chosen item by pointer
        record[j-list[i].weight]=list+i;
      }
    }
    for(int j=0;j<i;++j){cout<<cost[j]<<" ";}
    cout<<endl;
  }
}
int main(int argc, char** argv){
  if(argc!=2){
    cout<<"Wrong parameters!"<<endl;
    return -1;
  }
  int n,w;
  item* list=read_file(argv[1],&n,&w);
  cout<<"weight: ";
  for(int i=0;i<n;++i){
    cout<<list[i].weight<<" ";
  }
  cout<<endl;
  //create and initialize the record list
  item** record = new item*[w];
  for(int i=0;i<w;++i){record[i]=NULL;}

  //creat and initialize the cost list
  int* cost=new int[n];
  for(int i=0;i<n;++i){cost[i]=0;}

  knapsack(n,w,list,cost,record);

  for(int i=0;i<w;++i){
    if(record[i]!=NULL)
      cout<<record[i]->weight<<" ";
    else{
      cout<<"0 ";;
    }
  }
  cout<<endl;
  for(int i=0;i<n;++i){
    cout<<cost[i]<<" ";
  }
  cout<<endl;
}
