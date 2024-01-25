mod primality;
mod operations;
mod generators;

use std::time::Instant;
use generators::get_max_primes;
use num_bigint::BigUint;
use primality::{ standard, fermat };
use operations::pow;

fn main() {
    // Print prime numbers up to 100
    let primes = get_max_primes(1000);
    println!("Primes up to 100: {:?}", primes);

    // Get a random prime number
    let target = primes[50].clone();

    let now = Instant::now();
    let is_prime = standard(&target);
    let elapsed = now.elapsed();
    println!("Standard: {} is prime: {} in {:?}", target, is_prime, elapsed);

    let now = Instant::now();
    let is_prime = fermat(&target);
    let elapsed = now.elapsed();
    println!("Fermat: {} is prime: {} in {:?}", target, is_prime, elapsed);

    // Print Prime power 5
    println!("Prime power 5: {}", pow(&target, &BigUint::from(5u32)));
}
