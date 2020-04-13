# HW1 E24066242 劉祐誠
# User guide
#### After generating the executable file, please use the following command to execute:
* for linux:
```
./ merge_sort.exe input.txt
```
* for windows:
```
merge_sort.exe input.txt
```
#### The ouput file would be _`ouput.txt`_
(with the number of keys sorted in the first line, followed by the sorted keys with one key in each line.)

# Merge sort
I use recursive function to implement merge sort because the algorithm implies the idea of `divide-and-conquer`.
It takes three part to complete, just see the code below:
```cpp
merge_sort(list,left,mid);
merge_sort(list,mid+1,right);
merge(list,left,right);
```
The first _`merge_sort()`_ sort the left-half of the list, and the second one sort the right-half of it. After that, use _`merge()`_ to merge two sublist to a sorted one. This step would require an additional space(summation lenght of two sublist) to store the unsorted one. Finally, take these steps recursively until the whole list are sorted.

# Summary
* Time complexity: _O(nlogn)_
* Space complexity: _O(nlogn)_
