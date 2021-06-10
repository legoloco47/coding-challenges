public class HelloWorld {

  public static void main(String[] args){
    //Prints "Hello, World" to the terminal
    System.out.println("Hello, World");
  }

  
  /* Write a function that, given a list of integers (both positive and negative)
 * returns the sum of the contiguous subsequence with maximum sum.
 * Thus, given the sequence (1, 2, -4, 1, 3, -2, 3, -1) it should return 5
 */
 // 1, 3, -2, 3, -1
  
  
  1, 2, -4, 1, 3, -2, 3, -1
    
  1, 2, -1, 1, 3, -2, 3, -1  
    
  1, 5, -1, 2
  1, 5, -10, 2
    
  max -1
int maxContiguousSubsequenceSum(int[] arr) {
    // implementation here
    int N = arr.size();
    if (N ==0) return 0;
    
    int largestMaxSumSoFar = currentSum = 0;
  
    // iterate over every element in the array
    for (int i = 0; i < N; i < i++) {
        currentSum += arr[i];
        
      if (currentSum < 0) {
        currentSum = 0;
      }
      
      if (currentSum > largestMaxSum) {
        largestMaxSum = currentSum;
      }
      
    }
    
    return largestMaxSum;  
  
}

1, 2, -4, 1, 3, -2, 3, -1
  
currSum = 2 + 3 = 5 + -1 = 4
  
LargestSum = 5
  
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
  
  
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
  
  ["X","X","0"]"0","0"],
  ["X","X","0"],"0","0"],
  ["0","0","X"],"0","0"],
 
  
  
class Solution {
private:
  void islandFinder(vector<vector<char>>& grid), int x, int y, int rows, int cols) {
    
    if (grid[x][y] == "0" || grid[x][y] == "X") {
      return;
    }
    //change current spot to an X
    grid[x][y] = "X";

    if (x-1 >= 0) {
        islandFinder(grid, x-1, y, rows, cols); 
    }
    if (y-1 >= 0) {
        islandFinder(grid, x, y-1, rows, cols); 
    }
    if (x+1 < rows) {
        islandFinder(grid, x+1, y, rows, cols); 
    }
    if (y+1 < cols) {
        islandFinder(grid, x, y+1, rows, cols); 
    }
  }
          
          
public:
    int numIslands(vector<vector<char>>& grid) {
      int islandsFound = 0;
      int rows = grid.length();
      int cols = grid[0].lenght();
      
      for (int x = 0; x < rows; x++) {
          for (int y = 0; y < cols; y++) {
            if (grid[x][y] = "1") {
                islandFinder(grid, x, y, rows, cols);
                islandsFound++;           
              }
          }
      }
      return islandsFound;
    }
};
  
  
  