# Recursive Solutions and DP
Recusrive solution—built off solutions to subproblems
* i.e. f(n) is found using solution to f(n-1)
* ex: solve something for 1st half of data set, then for 2nd half.. then merge

## 3 ways to divide a problem into subproblems
1. Bottom-up approach
* start with solving for simplest case (list with 1 element). Then figure out for 2 elements. Then 3. Etc. 
* KEY: how to build the solution for one case based on previous cases

2. Top-down approach
* more complex because less concrete
* think abouyt how to divide the problem for case N into subproblems 
* be careful of overlap between cases

3. Half-and-half approach
* effective to think about dividing the data set in half
* ex: binary search--look for element in sorted array in half, then recurse
* ex: mergesort--sort half the array then merge togetger tge sorted halves

## Recursive vs iterative solutions
* recursive algorithms can be very space inefficient --> adds a new layer to the stack each call
* ALL recursive algorithms can be implemneted iteratively (although they might be more complex)

## Dynamic Programming and Memoization
### Dynamic programming
* taking a recursive algorithm, finding the overlapping subproblems (repeated calls) then caching those results for future uses (future recursive calls)


