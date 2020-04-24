# HW3 E24066242 劉祐誠


## BINARY SEARCH TREE
### User guide
After generating the executable file, please use the following command to execute:

```
./binary_tree.exe binary_tree_input.txt
```
Example format of `binary_tree_input.txt`:
```txt
18 //number of commands
insert 3
insert 2
insert 1
insert 8
insert 7
traverse
delete 3
delete 1
search 3
traverse
insert 5
insert 9
max
min
successor 5
predecessor 9
search 7
traverse
```
And the ouput would be printed like:
```output
Insert 3
Insert 2
Insert 1
Insert 8
Insert 7
Inorder traversing result: 1 2 3 7 8
Delete 3
Delete 1
Search 3 : not found
Inorder traversing result: 2 7 8
Insert 5
Insert 9
Max: 9
Min: 2
Successor of 5 : 7
Predecessor of 9 : 8
Search 7 : found
Inorder traversing result: 2 5 7 8 9
```
### Function Introduction
* **_inorder_traverse_** :
Inorder tree walk, and print the key of node.
  ```c++
  void inorder_traverse(node* n)
  ```
  * _Time complexity_ **_O(n)_**


* **_posorder_delete_** :
Posorder tree walk, delete the key of node after traversing.
  ```c++
  void posorder_delete(node* n)
  ```
  * _Time complexity_ **_O(n)_**


* **_root_node_** :
Return root node of the tree.
  ```c++
  node* root_node()
  ```
  * _Time complexity_ **_O(1)_**


* **_search_** :
Search the target key in the tree. If not found, return NULL.
  ```c++
  node* search(const int target)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_max_** :
Return the node of max key.
  ```c++
  node* max(node* n)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_min_** :
Return the node of max key.
  ```c++
  node* min(node* n)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_successor_** :
Return the successor of the node.
  ```c++
  node* successor(const node* n)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_predecessor_** :
Return the predecessor of the node.
  ```c++
  node* predecessor(const node* n)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_insert_node_** :
Find the proper place for the target, creat a new node and insert it. Notice that the program can't accept duplicated keys.
  ```c++
  void insert_node(int key)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)

* **_delete_node_** :
Delete the target node.
  ```c++
  void delete_node(node* n)
  ```
  * _Time complexity_ **_O(lgn)_** (for balanced tree)
  * _Time complexity_ **_O(n)_** (for unbalanced tree)


## SELECTION IN WORST CASE LINEAR TIME
### User guide
After generating the executable file, please use the following command to execute:
```
./selection.exe selection_input.txt /*generate selection_output.txt*/
```
Example format of `selection_input.txt`:
```txt
15 //number of elements
8  //target rank
17
31
0
100
88
55
10
9
7
43
11
12
50
333
1597
```
Example format of `selection_output.txt`:
```output
15 //number of elements
8  //target rank
31 //k-th smallest value
```
### Algorithm steps:
1. Divide the n elements of the input array into n/5 groups of 5 elements each and at most one group made up of the remaining n mod 5 elements.
2. Sort each group by _insertion sort_, and then pick the median from the sorted list of group elements to combine a `median array`.
3. Use SELECT recursively to find the `median-of-medians` x (median of the `median array` found in step 2).
4. Partition the input array around the pivot term x using the modified version of _PARTITION_. Let k be one more than the number of elements on the low side of the partition, so that x is the kth smallest element and there are n-k elements on the high side of the pivoit.
5. If i = k, then return x. Otherwise, use SELECT recursively to find the i th smallest element on the low side if i < k, or find the ith smallest element on the high side if i > k.
