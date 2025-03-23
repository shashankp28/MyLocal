use crate::def::Sudoku;

impl Sudoku {
    pub fn print_board(&self) {
        println!("+-------+-------+-------+");
        for i in 0..9 {
            if i % 3 == 0 && i != 0 {
                println!("|-------+-------+-------|");
            }
            print!("| ");
            for j in 0..9 {
                if j % 3 == 0 && j != 0 {
                    print!("| ");
                }
                if self.row[i][j] == 0 {
                    print!(". ");
                } else {
                    print!("{} ", self.row[i][j]);
                }
            }
            println!("|");
        }
        println!("+-------+-------+-------+\n\n\n");
    }

    pub fn add(&mut self, x: usize, y: usize, num: u8, nop: bool) -> bool {
        if x >= 9 || y >= 9 || num < 1 || num > 9 {
            panic!("Invalid coordinates or number out of range");
        }

        let block_index = (x / 3) * 3 + y / 3;

        if self.row[x][y] != 0 {
            return false;
        }
        if
            !self.row_remaining[x].contains(&num) ||
            !self.col_remaining[y].contains(&num) ||
            !self.block_remaining[block_index].contains(&num)
        {
            return false;
        }
        if !nop {
            self.row[x][y] = num;
            self.col[y][x] = num;
            let block_pos = (x % 3) * 3 + (y % 3);
            self.block[block_index][block_pos] = num;

            self.row_remaining[x].remove(&num);
            self.col_remaining[y].remove(&num);
            self.block_remaining[block_index].remove(&num);
        }
        return true;
    }

    pub fn remove(&mut self, x: usize, y: usize, nop: bool) -> bool {
        if x >= 9 || y >= 9 {
            return false;
        }

        let num = self.row[x][y];
        if num == 0 {
            return false;
        }

        if !nop {
            let block_index = (x / 3) * 3 + y / 3;
            let block_pos = (x % 3) * 3 + (y % 3);

            self.row_remaining[x].insert(num);
            self.col_remaining[y].insert(num);
            self.block_remaining[block_index].insert(num);

            self.row[x][y] = 0;
            self.col[y][x] = 0;
            self.block[block_index][block_pos] = 0;
        }
        return true;
    }

    pub fn block_to_coordinates(&self, block_index: usize, pos: usize) -> (usize, usize) {
        if block_index >= 9 || pos >= 9 {
            panic!("Invalid block index or position");
        }

        let block_row = block_index / 3;
        let block_col = block_index % 3;
        let x = block_row * 3 + pos / 3;
        let y = block_col * 3 + (pos % 3);

        (x, y)
    }

    pub fn coordinates_to_block(&self, x: usize, y: usize) -> (usize, usize) {
        if x >= 9 || y >= 9 {
            panic!("Invalid coordinates");
        }

        ((x / 3) * 3 + y / 3, (x % 3) * 3 + (y % 3))
    }

    pub fn solved(&self) -> bool {
        let mut solved = true;
        for row in 0..9 {
            solved = solved && self.row_remaining[row].is_empty();
        }
        return solved;
    }
}
