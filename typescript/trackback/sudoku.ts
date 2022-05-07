/** 
 * 数独求解
*/

const usedInRow = (matrix: number[][], row: number, num: number) => {
  return matrix[row].some((val: number) => val === num);
}

const usedInCol = (matrix: number[][], col: number, num: number) => {
  for (let row = 0; row < matrix.length; row++) {
    if (matrix[row][col] === num) {
      return true;
    }
  }
  return false;
};

const usedInBox = (matrix: number[][], boxStartRow: number, boxStartCol: number, num: number) => {
  for (let row = 0; row < 3; row++) {
    for (let col = 0; col < 3; col++) {
      if (matrix[row + boxStartRow][col + boxStartCol] === num) {
        return true;
      } 
    }
  }
  return false;
}
const isSafe = (matrix: number[][], row: number, col: number, num: number) => {
  return (
    !usedInRow(matrix, row, num) &&
    !usedInCol(matrix, col, num) &&
    !usedInBox(matrix, row - (row % 3), col - (col % 3), num)
  );
}

const UNASSIGNED = 0;
const solveSudoku = (matrix: number[][]) => {
  let row = 0, col = 0, checkBlankSpaces = false;
  for(row = 0; row < matrix.length; row++) {
    for(col = 0; col < matrix[row].length; col++) {
      if(matrix[row][col] === UNASSIGNED) {
        checkBlankSpaces = true;
        break;
      }
    }
    if(checkBlankSpaces === true) {
      break;
    }    
  }
  if(checkBlankSpaces === false) {
    return true;
  }

  for(let num = 1; num <= 9; num++) {
    if(isSafe(matrix, row, col, num)) {
      matrix[row][col] = num;
      if(solveSudoku(matrix)) {
        return true;
      }
      matrix[row][col] = UNASSIGNED;
    }
  }
  return false;
}

const sudokuSolver = (matrix: number[][]) => {
  if(solveSudoku(matrix) === true) {
    return matrix;
  }

  return 'no answer!';
}

const sudokuGrid = [
[5, 3, 0, 0, 7, 0, 0, 0, 0],
[6, 0, 0, 1, 9, 5, 0, 0, 0],
[0, 9, 8, 0, 0, 0, 0, 6, 0],
[8, 0, 0, 0, 6, 0, 0, 0, 3],
[4, 0, 0, 8, 0, 3, 0, 0, 1],
[7, 0, 0, 0, 2, 0, 0, 0, 6],
[0, 6, 0, 0, 0, 0, 2, 8, 0],
[0, 0, 0, 4, 1, 9, 0, 0, 5],
[0, 0, 0, 0, 8, 0, 0, 7, 9]
];
console.log(sudokuSolver(sudokuGrid));