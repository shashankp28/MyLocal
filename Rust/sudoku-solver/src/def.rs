use std::collections::HashSet;

#[derive(Debug)]
pub struct Sudoku {
    pub row: [[u8; 9]; 9],
    pub col: [[u8; 9]; 9],
    pub block: [[u8; 9]; 9],

    pub row_remaining: [HashSet<u8>; 9],
    pub col_remaining: [HashSet<u8>; 9],
    pub block_remaining: [HashSet<u8>; 9],
}
