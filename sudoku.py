sudoku_grid = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

def empty_space(grid):
    for r in range(9):
        for c in range(9):
            if grid[r][c] == 0:
                return r, c
    return None, None

def is_valid(row, col, grid, guess):
    # Check if the guess is valid for the current cell
    # Check the row
    if guess in grid[row]:
        return False

    # Check the column
    if guess in [grid[i][col] for i in range(9)]:
        return False

    # Check the 3x3 box
    row_start, col_start = 3 * (row // 3), 3 * (col // 3)
    for i in range(row_start, row_start + 3):
        for j in range(col_start, col_start + 3):
            if grid[i][j] == guess:
                return False

    return True

def solve_sudoku(grid):
    row, col = empty_space(grid)
    if row is None:
        return True  # No empty spaces, puzzle is solved

    for guess in range(1, 10):
        if is_valid(row, col, grid, guess):
            grid[row][col] = guess

            if solve_sudoku(grid):
                return True

            # Backtrack if the current guess doesn't lead to a solution
            grid[row][col] = 0

    return False

if solve_sudoku(sudoku_grid):
    print("Solved Sudoku:")
    for row in sudoku_grid:
        print(" ".join(map(str, row)))
              