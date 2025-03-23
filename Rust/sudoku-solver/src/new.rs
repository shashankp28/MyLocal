use crate::def::Sudoku;
use std::collections::HashSet;

impl Sudoku {
    pub fn new(board: [[u8; 9]; 9]) -> Self {
        let mut col = [[0; 9]; 9];
        let mut block = [[0; 9]; 9];

        let mut row_remaining: [HashSet<u8>; 9] = Default::default();
        let mut col_remaining: [HashSet<u8>; 9] = Default::default();
        let mut block_remaining: [HashSet<u8>; 9] = Default::default();

        // Initialize row, col, and block remaining sets
        for i in 0..9 {
            row_remaining[i] = (1..=9).collect();
            col_remaining[i] = (1..=9).collect();
            block_remaining[i] = (1..=9).collect();
        }

        // Populate column and block structures
        for r in 0..9 {
            for c in 0..9 {
                let val = board[r][c];
                col[c][r] = val;
                let block_index = (r / 3) * 3 + c / 3;
                let block_pos = (r % 3) * 3 + (c % 3);
                block[block_index][block_pos] = val;
                if val != 0 {
                    // Ensure val exists before removing, otherwise, it's an invalid board
                    assert!(
                        row_remaining[r].contains(&val),
                        "Invalid Sudoku Board: Duplicate value {} in row {}",
                        val,
                        r
                    );
                    assert!(
                        col_remaining[c].contains(&val),
                        "Invalid Sudoku Board: Duplicate value {} in column {}",
                        val,
                        c
                    );
                    assert!(
                        block_remaining[block_index].contains(&val),
                        "Invalid Sudoku Board: Duplicate value {} in block {}",
                        val,
                        block_index
                    );

                    row_remaining[r].remove(&val);
                    col_remaining[c].remove(&val);
                    block_remaining[block_index].remove(&val);
                }
            }
        }

        Sudoku {
            row: board,
            col,
            block,
            row_remaining,
            col_remaining,
            block_remaining,
        }
    }
}
