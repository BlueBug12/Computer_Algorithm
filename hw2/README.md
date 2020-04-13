# HW2 E24066242 劉祐誠

# User guide
#### After generating the executable file, please use the following command to execute:
* for linux:
```
./insertion_sort.exe input.txt
./quick_sort.exe input.txt
./quick_insertion.exe input.txt n
```
n is the length of the sublist to be sorted by insertion sort. For example:
 ```./quick_insertion.exe input.txt 10 ```
* for windows:
```
insertion_sort.exe input.txt
quick_sort.exe input.txt
quick_insertion.exe input.txt n
```
n is the length of the sublist to be sorted by insertion sort. For example:
```quick_insertion.exe input.txt 10```

#### The ouput file would be _`ouput.txt`_
(with the number of keys sorted in the first line, followed by the sorted keys with one key in each line.)

# Insertion sort
```cpp
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
```
The basic idea of insertion is to divide the list into two part: unsorted one(right) and sorted one(left). So we start sorting from the left-most(but in the code I start from `i=1` becasue the case `i=0` doesn't need to compare). Copy the current value in variable `key`. Then, just compare forward to the other elements one-by-one. To sort in non-decreasing order, if the compared value is bigger than value of `key`, we pass the compared valude to the previous position(`j+1`). Until finding the correct position to place the value of key, we place it and end this round of comparison.

* Time complexity: _O(n^2)_
* Space complexity: _O(1)_

# Quick sort
```cpp
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
```
I use recursive function to implement merge sort because this algorithm implies the idea of `divide-and-conquer`.
First, we pick the `pivot` term from the left-most element in current list and find the element bigger than the `pivot` from the left and find the element smaller than compare from the right. Than swap these two selected value. We repeat this step until the left index(`i`) is bigger than the right index(`j`), which means that the elements at the left side of `pivot` are all smaller than it, and the elements at the rught side of `pivot` are all bigger than it. At this stage, we have divide the sorting problem into two sub-lists to sort, so we just need to repeat the previous steps to finish the sorting.

* Time complexity: _O(n^2)_ (when the list is sorted)
* Space complexity: _O(1)_
# Quick-insertion sort
```cpp
void quickSort(int* n,const int left,const int right){
  if(right-left<=10000){//length of the list to use insertion sort
    insertion(n+left,right-left+1);
    return ;
  }
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

```
It's a combination of insertion sort and quick sort. What we need to do is putting the insertion function into quick sort, and determining at what length of the sublist we need to use insertion sort instead of the quick sort.

* Time complexity: _O(n^2)_ (when the list is sorted)
* Space complexity: _O(1)_
# Result

##### quick-insertion for different n:
|n    | sec |
|:--: |:---:|
|10   |0.422|
|50   |0.406|
|100  |0.406|
|500  |0.406|
|1000 |0.39 |
|5000 |0.26 |
|10000|0    |


##### for 10000 input size with different sort-type:

|sort-type                  | sec |
|:------------:             |:---:|
| _insertion_               |  0  |
| _quick_                   | 0.56|
| _quick-insertion(n=10000)_| 0   |

# Summary
Because the input array is `nearly` sorted, so the time complexity of insertion sort may approach to O(n), and the time complexity of quick sort may approach to O(n^2). As a result, the quick-insertion sort may be redundant because insertion sort is faster than quick sort in this case. We can see that the bigger value of n we choose, the sorting is faster.
