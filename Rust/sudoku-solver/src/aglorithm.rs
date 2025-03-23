use crate::def::Sudoku;

impl Sudoku {
    pub fn solve_remaining_block(&mut self) -> bool {
        // For each block iterate through required nums.
        // For that number check if only one coordinate is possible
        // If no coordinate is possible return false (unsolvable)
        let mut found: bool = false;
        for req in 1..10 {
            for block_index in 0..9 {
                if !self.block_remaining[block_index].contains(&req) {
                    continue;
                }
                let mut temp_found: Option<(usize, usize, u8)> = None;
                let mut repeat: bool = false;
                for block_offset in 0..9 {
                    let coord = self.block_to_coordinates(block_index, block_offset);
                    let x = coord.0;
                    let y = coord.1;
                    if self.add(x, y, req, true) {
                        match temp_found {
                            Some(_) => {
                                repeat = true;
                                break;
                            }
                            None => {
                                temp_found = Some((x, y, req));
                            }
                        }
                    }
                }
                match temp_found {
                    Some(val) => {
                        if !repeat {
                            self.add(val.0, val.1, val.2, false);
                            found = true;
                        }
                    }
                    None => {
                        panic!(
                            "No place is possbile for a required num: {} in block: {}",
                            req,
                            block_index
                        );
                    }
                }
            }
        }
        return found;
    }

    pub fn solve_remaining_col(&mut self) -> bool {
        // For each column iterate through required nums.
        // For that number check if only one coordinate is possible
        // If no coordinate is possible return false (unsolvable)
        let mut found: bool = false;
        for req in 1..10 {
            for col_num in 0..9 {
                if !self.col_remaining[col_num].contains(&req) {
                    continue;
                }
                let mut temp_found: Option<(usize, usize, u8)> = None;
                let mut repeat: bool = false;
                for row_num in 0..9 {
                    let x = row_num;
                    let y = col_num;
                    if self.add(x, y, req, true) {
                        match temp_found {
                            Some(_) => {
                                repeat = true;
                                break;
                            }
                            None => {
                                temp_found = Some((x, y, req));
                            }
                        }
                    }
                }
                match temp_found {
                    Some(val) => {
                        if !repeat {
                            self.add(val.0, val.1, val.2, false);
                            found = true;
                        }
                    }
                    None => {
                        panic!(
                            "No place is possbile for a required num: {} in coloumn: {}",
                            req,
                            col_num
                        );
                    }
                }
            }
        }
        return found;
    }

    pub fn solve_remaining_row(&mut self) -> bool {
        // For each row iterate through required nums.
        // For that number check if only one coordinate is possible
        // If no coordinate is possible return false (unsolvable)
        let mut found: bool = false;
        for req in 1..10 {
            for row_num in 0..9 {
                if !self.row_remaining[row_num].contains(&req) {
                    continue;
                }
                let mut temp_found: Option<(usize, usize, u8)> = None;
                let mut repeat: bool = false;
                for col_num in 0..9 {
                    let x = row_num;
                    let y = col_num;
                    if self.add(x, y, req, true) {
                        match temp_found {
                            Some(_) => {
                                repeat = true;
                                break;
                            }
                            None => {
                                temp_found = Some((x, y, req));
                            }
                        }
                    }
                }
                match temp_found {
                    Some(val) => {
                        if !repeat {
                            self.add(val.0, val.1, val.2, false);
                            found = true;
                        }
                    }
                    None => {
                        panic!(
                            "No place is possbile for a required num: {} in row: {}",
                            req,
                            row_num
                        );
                    }
                }
            }
        }
        return found;
    }

    pub fn solve_remaining_number(&mut self) -> bool {
        // For each cell, iterate through all numbers 1-9
        // If exactly one number can be added then add the number
        // If no number can be added panic as cell cannot remain empty
        let mut found: bool = false;
        for x in 0..9 {
            for y in 0..9 {
                if self.row[x][y] != 0 {
                    continue;
                }
                let mut temp_found: Option<(usize, usize, u8)> = None;
                let mut repeat: bool = false;
                for num in 1..10 {
                    if self.add(x, y, num, true) {
                        match temp_found {
                            Some(_) => {
                                repeat = true;
                                break;
                            }
                            None => {
                                temp_found = Some((x, y, num));
                            }
                        }
                    }
                }
                match temp_found {
                    Some(val) => {
                        if !repeat {
                            self.add(val.0, val.1, val.2, false);
                            found = true;
                        }
                    }
                    None => {
                        panic!("No Number can be placed at coordinate: ( {}, {} )", x, y);
                    }
                }
            }
        }
        return found;
    }

    pub fn solve_rec(&mut self) -> bool {
        if self.solved() {
            return true;
        }
        let mut solved = false;
        for x in 0..9 {
            for y in 0..9 {
                for num in 0..10 {
                    if self.row_remaining[x].contains(&num) {
                        let added = self.add(x, y, num, false);
                        if added {
                            solved = self.solve_rec();
                            if solved {
                                break;
                            }
                            self.remove(x, y, false);
                        }
                    }
                }
            }
            if solved {
                break;
            }
        }
        return solved;
    }

    pub fn solve(&mut self) -> bool {
        let mut found = true;
        while found && !self.solved() {
            found = false;
            found = found || self.solve_remaining_block();
            found = found || self.solve_remaining_col();
            found = found || self.solve_remaining_row();
            found = found || self.solve_remaining_number();
            if !found {
                break;
            }
            self.print_board();
        }
        return self.solve_rec();
    }
}
