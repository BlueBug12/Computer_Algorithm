# HW5 E24066242 劉祐誠

## 0-1 Knapsack Problem
### User guide
After generating the executable file, please use the following command to execute:

```
./knapsack.exe input.txt
```
And the ouput would be stored in `output.txt`
* My environment: gcc 7.4.0
### Problem description
Give a dynamic-programming solution to the _0_1 knapsack_ problem that runs in _O(nW)_ time, where nn is the number of items and _W_ is the maximum weight of items that the thief can put in his knapsack.
### Algorithm analysis
Use dynamic programming to solve the problem:
1. Optimal structure
We construct an array _c[0..W]_
For 0 ≤ i ≤ w, the entry _c[i]_ will store the maximum value when the weight is _i_, and we have _n_ item to choose.
If we can compute all the entries of this array, then
the array entry _c[W]_ will contain the maximum value in the constraint wigth, which is the optimal solution to our problem.

2. Recursive formulation
    ```
    c(i) = max(c(i),c(i-weight[i])+value[i])
    ```
3. Compute the value of an optimal solution
```c++
  0-1-KNAPSACK(n, W)
    for i = 1 to n
      c[i] = 0
    for i = 1 to n
      j = W
      while j - i.weight ≥ 0
        c[j] = max(c[j], c[j-i.weight] + i.value)
        j = j -1
```
* _Time complexity_ **_O(nW)_**

4. Construct the optimal solution
Every time the entry _c[i]_ is updated, we know which item is chosen.  So what we need to do is create another list _record[0...W]_ which has the equal length to _c_. When we update the total value at weight _w_, we record the pointer of the chosen item in _record[w]_. After finishing calculate the optimal solution, we back trace the total weight until it's 0. For example, the last item we add is _record[W]_(by address); and the previous one is _record[W-record[W]->weight]_..., and so on.
