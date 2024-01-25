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

    let maximum: u64 = 100;
    let target: u64 = args[1].parse().unwrap();

    // Print prime numbers up to 100
    let now = Instant::now();
    let primes = get_max_primes(maximum);
    let elapsed = now.elapsed();
    println!("Prime numbers upto {}, genrated in: {:?}", maximum, elapsed);

    println!("Number of primes up to {}: {}", maximum, primes.len());
    println!("Last prime number: {}", primes.last().unwrap());
    
    // Get the last prime number
    let target = BigUint::from(target);
    // Print Prime power 2
    println!("Prime power 2: {}", pow(&target, &BigUint::from(2u32)));
    
    println!();
    let now = Instant::now();
    let is_prime = standard(&target);
    let elapsed = now.elapsed();
    println!("Standard: {} is prime: {} in {:?}", target, is_prime, elapsed);

    let now = Instant::now();
    let is_prime = fermat(&target);
    let elapsed = now.elapsed();
    println!("Fermat: {} is prime: {} in {:?}", target, is_prime, elapsed);

}
