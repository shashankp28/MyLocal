use std::env;
use std::f64;

fn random_double(min: f64, max: f64) -> f64 {
    min + (max - min) * rand::random::<f64>()
}

fn generate_random_matrix(rows: usize, cols: usize, min: f64, max: f64) -> Vec<Vec<f64>> {
    (0..rows)
        .map(|_| (0..cols).map(|_| random_double(min, max)).collect())
        .collect()
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 4 {
        eprintln!("Usage: {} a b c", args[0]);
        std::process::exit(1);
    }

    let a: usize = args[1].parse().expect("a must be a positive integer");
    let b: usize = args[2].parse().expect("b must be a positive integer");
    let c: usize = args[3].parse().expect("c must be a positive integer");

    if a <= 0 || b <= 0 || c <= 0 {
        eprintln!("Matrix dimensions must be positive integers.");
        std::process::exit(1);
    }

    let matrix_a = generate_random_matrix(a, b, 0.0, 1.0);
    let matrix_b = generate_random_matrix(b, c, 0.0, 1.0);
    let mut matrix_c = vec![vec![0.0; c]; a];

    for i in 0..a {
        for j in 0..c {
            for k in 0..b {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    println!("Matrix Multiplication Completed");
}
