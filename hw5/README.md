# HW5 E24066242 劉祐誠

## 0-1 Knapsack Problem
### User guide
After generating the executable file, please use the following command to execute:

```
./knapsack.exe input.txt
```
My environment: gcc 7.4.0
### Algorithm analysis
Use dynamic programming to solve the problem:
1. Optimal structure
We construct an array _K[0..n,0..W]_
For 1 ≤ i ≤ n, and 0 ≤ w ≤ W, the entry _K[i,w]_ will store the maximum value when the weight is _w_, and we have _i_ item to choose.
If we can compute all the entries of this array, then
the array entry _K[n,W]_ will contain the maximum value in the constraint wigth, which is the optimal solution to our problem.

2. Recursive formulation
```
k(i,w) = 0                                        , if n = 0
       = k(n-1,w)                                 , if n > 0 and w-weight[n] < 0
       = max(k(i-1,w),k(i-1,w-weight[i])+cost[i]) , otherwise

```
3. Compute the value of an optimal solution (by `bottom-up` fashion)
```c++
0-1-KNAPSACK(n, W)
  for i = 1 to n
    c[i] = 0
  for i = 1 to n
    j = W
    while j - i.weight ≥ 0
      c[j] = max(c[j], c[j-i.weight] + cost)
      j = j -1
```

* _Time complexity_ **_O(nW)_**
