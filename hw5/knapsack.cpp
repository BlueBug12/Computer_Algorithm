#include <iostream>
#include <fstream>
#include <vector>
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

void write_file(const int value, const vector<int>& ans){
	fstream file;
	file.open("output.txt",ios::out);
	if(!file){
		cout<<"Can not open output.txt"<<endl;
		exit(1);
	}
  file<<"Total revenue = "<<value<<endl;
  cout<<"Total revenue = "<<value<<endl;
  file<<"Selected item : ";
  cout<<"Selected item : ";
  //to reverse the back trace answer, start from the tail
  for(int i=ans.size()-1;i>=0;--i){
    file<<ans.at(i)<<" ";
    cout<<ans.at(i)<<" ";
  }
	file<<endl;
	file.close();
}

void knapsack(int n, int w, item* list, int* cost, item** record){
  for(int i=0;i<n;++i){
    //the second for loop start from the tail because we need to avoid taking item more than once
    for(int j=w;j>=list[i].weight;--j){
      //cost[j]=max(cost[j-list[i].weight]+list[i].value,cost[j]);
      if(cost[j-list[i].weight]+list[i].value>cost[j]){
        //choose the item and deduct the total weight
        cost[j] = cost[j-list[i].weight] + list[i].value;
        //record the chosen item by pointer
        record[j]=list+i;
      }
    }
  }
}

int main(int argc, char** argv){
  if(argc!=2){
    cout<<"Wrong parameters!"<<endl;
    return -1;
  }
  int n,w;
  item* list=read_file(argv[1],&n,&w);

  //create and initialize the record list
  item** record = new item*[w+1];
  for(int i=0;i<w;++i){record[i]=NULL;}

  //creat and initialize the cost list
  int* cost=new int[w+1];
  for(int i=0;i<w;++i){cost[i]=0;}

  knapsack(n,w,list,cost,record);

  int total_weight=w;
  vector<int>ans;
  //back trace the answer and push it in vector
  while(total_weight>0){
    ans.push_back(record[total_weight]->index);
    total_weight-=record[total_weight]->weight;
  }

  write_file(cost[w],ans);
  delete[] record;
  delete[] cost;
  delete[] list;
}
