mod primality;
mod operations;

use num_bigint::BigUint;
use num_traits::One;

fn main() {
    let a_str = "1234567890123456789012345678901234567890";
    let p_str = "9876543210987654321098765432109876543210";

    let a = BigUint::parse_bytes(a_str.as_bytes(), 10).unwrap();
    let p = BigUint::parse_bytes(p_str.as_bytes(), 10).unwrap();

    let a_val = BigUint::from(10u32).pow(50) + BigUint::one();
    let p_val = BigUint::one() << (100 - 1);

    println!("Result: {}", a);
    println!("Result: {}", p);

    println!("Result: {}", a_val);
    println!("Result: {}", p_val);
}
