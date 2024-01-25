mod primality;
mod operations;
mod generators;

use std::time::Instant;
use generators::get_max_primes;
use num_bigint::BigUint;
use primality::{ standard, fermat };
use operations::pow;

fn main() {
    // Take input command line argument
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        println!("Usage: <executable> <prime number index>");
        return;
    }

    let maximum: u64 = args[1].parse().unwrap();

    // Print prime numbers up to 100
    let primes = get_max_primes(maximum);
    println!("Number of primes up to {}: {}", maximum, primes.len());

    // Get the last prime number
    let target = primes.last().unwrap().clone();

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
