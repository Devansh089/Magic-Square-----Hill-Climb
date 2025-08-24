# Magic-Square-----Hill-Climb

# Magic Square Generator

This project generates **Magic Squares** of any order `n ≥ 3` using different algorithms depending on the parity of `n`:

1. **Odd Order Magic Square** (n is odd) — Siamese method
2. **Doubly Even Order Magic Square** (n divisible by 4) — Inversion method
3. **Singly Even Order Magic Square** (n divisible by 2 but not by 4) — Strachey method

---

## **1. Odd Order Magic Square (Siamese Method)**
- Works for odd values of `n` (e.g., 3, 5, 7...).
- Start at the middle row and last column, placing numbers sequentially.
- If the next position is out of bounds, wrap around.
- If the next position is already filled or both row and column go out of bounds, move one step left instead.

**Pseudocode:**
```text
Initialize n×n matrix with 0
Set position: row = n / 2, col = n - 1
For num from 1 to n*n:
    Place num at (row, col)
    If num % n == 0:
        Move left(col--)
    Else:
        Move up(row--) and move right(col++)
    Wrap around if row < 0 → row = n - 1
    Wrap around if col == n → col = 0
```

---

## **2. Doubly Even Order Magic Square (Inversion Method)**
- Works when `n % 4 == 0` (e.g., 4, 8, 12...).
- Fill matrix sequentially from 1 to n².
- Invert specific cells based on position patterns.

**Pseudocode:**
```text
Fill matrix with numbers from 1 to n*n
For each cell (i, j):
    If (i % 4 == j % 4) OR (i % 4 + j % 4 == 3):
        Replace value with (n*n + 1 - value)
```

---

## **3. Singly Even Order Magic Square (Strachey Method)**
- Works when `n % 2 == 0` but `n % 4 != 0` (e.g., 6, 10, 14...).
- Divide matrix into four quadrants.
- Fill each quadrant using the odd-order method.
- Swap certain columns between quadrants.

**Pseudocode:**
```text
Let halfN = n / 2
Generate odd-order magic square of size halfN
Place copies into 4 quadrants with offsets:
    Top-left: original values
    Top-right: + 2 * (halfN^2)
    Bottom-left: + 3 * (halfN^2)
    Bottom-right: + (halfN^2)
Determine k = (n - 2) / 4
Swap columns in first k and last k positions between top and bottom halves
Swap two middle cells for symmetry correction
```

---

## **Time Complexity Analysis**

| Method                 | Time Complexity | Space Complexity | Notes |
|------------------------|----------------|-----------------|-------|
| Odd Order (Siamese)    | O(n²)          | O(n²)           | Simple and efficient |
| Doubly Even (Inversion)| O(n²)          | O(n²)           | Fast, pattern-based |
| Singly Even (Strachey) | O(n²)          | O(n²)           | More complex due to quadrant swaps |

---

## **How to Run**
1. Compile and execute:
    ```bash
    g++ magic_square.cpp -o magic_square
    ./magic_square
    ```
2. Enter the order of the magic square when prompted.

---

## **Example Output (n = 3)**

```
Enter order of magic square: 3
2 7 6
9 5 1
4 3 8
```

---

## **Conclusion**
- **Odd Order**: Best for small odd sizes — clean and quick.
- **Doubly Even**: Pattern-based, very fast.
- **Singly Even**: Most complex but handles remaining cases.



# Solving 8-Puzzle Using Hill Climbing  

## Aim  
The aim of this project is to solve the **8-puzzle problem** using the **Hill Climbing algorithm** with a simple heuristic function. The algorithm attempts to reach the goal state from a given initial configuration by minimizing the heuristic cost (misplaced tiles).  

---

## Data Structures Used  
1. **`vector<vector<int>>` (Board)** – Represents the puzzle board as a 3x3 matrix.  
2. **`vector<pair<int, Board>>` (Queue)** – Stores states along with their heuristic values for processing.  
3. **`vector<Board>` (Visited List)** – Keeps track of already visited states to avoid revisiting.  
4. **`pair<int,int>`** – Used to represent the position of the blank tile (0).  

---

## ⚙️ Algorithm – Hill Climbing for 8 Puzzle  
1. Start with the initial configuration of the board.  
2. Compute the heuristic value **h(n)** (number of misplaced tiles).  
3. Generate possible child states by moving the blank tile (`0`) **up, down, left, right**.  
4. Evaluate each child using the heuristic.  
5. Choose the child with the **lowest heuristic value**.  
6. If no better child is found (local maxima), terminate.  
7. Repeat until the **goal state** is reached or no improvement is possible.  

---

## State Generation  
The blank tile (`0`) can be moved in **four directions** (if valid):  
- **Up** → `up(Board s)`  
- **Down** → `down(Board s)`  
- **Left** → `left(Board s)`  
- **Right** → `right(Board s)`  

Each function swaps the blank tile with its neighboring tile to produce a new board configuration.  

---

## Utility Functions  
- **`heuristic(Board curr, Board goal)`** → Returns the number of misplaced tiles.  
- **`find_pos(Board s)`** → Finds the position of the blank tile (0).  
- **`compare(Board a, Board b)`** → Checks if two boards are the same.  
- **`up/down/left/right(Board s)`** → Generates child states.  
- **`search(Board start, Board goal)`** → Performs hill climbing search and prints the result.  

---

## Use Cases  
- Solving small-scale puzzle problems.  
- Understanding **local search algorithms** (Hill Climbing).  
- Demonstrating concepts of **heuristic functions** in Artificial Intelligence.  
- Comparing heuristic-based approaches with **A*** or **BFS/DFS**.  

---

## Time Complexity  
- **State Generation**: O(1) per move.  
- **Heuristic Calculation**: O(9) = O(1).  
- **Search Loop**: Worst case explores multiple states → O(b^d),  
  where **b = branching factor (≤4)**, **d = depth of solution**.  
- **Overall Complexity**: Exponential in worst case.  

## Space Complexity  
- Storing visited states: O(n), where n is the number of unique states encountered.  
- Each state requires O(9) = O(1) space.  
- **Overall Space**: O(n).  

---


## Sample Output  

### Example 1 – Solvable Case  
Initial:  
```text
1 2 3
4 5 6
8 7 0
```
Goal:
```text
1 2 3
4 5 6
7 8 0
```
Output:
```text
Heuristic of child greater than parent: 3 > 2
Execution time: 2 ms
```

---

## Limitations  
- Can get stuck in **local maxima** or **plateaus**.  
- Not guaranteed to find the optimal solution.  
- Works best for demonstrating **hill climbing principles** rather than solving large puzzles.  
