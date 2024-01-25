mod primality;
mod operations;
mod generators;
mod parser;

use clap::Parser;
use std::time::Instant;
use parser::Args;
use generators::get_max_primes;
use primality::{ standard, fermat };
use operations::pow;

fn main() {
    let args = Args::parse();

    let now = Instant::now();

    match args.get_action() {
        parser::Action::Power => {
            let target = args.get_target();
            let power = args.get_power();
            println!("Prime power {}: {}", target, pow(&target, &power));
        }
        parser::Action::Standard => {
            let target = args.get_target();
            let is_prime = standard(&target);
            println!("Standard Test: {} is prime: {}", target, is_prime);
        }
        parser::Action::Fermat => {
            let target = args.get_target();
            let is_prime = fermat(&target);
            println!("Fermat Test: {} is prime: {}", target, is_prime);
        }
        parser::Action::Generate => {
            let maximum = args.get_maximum();
            let primes = get_max_primes(maximum);
            println!("Primes upto {}: {:?}", maximum, primes);
        }
    }
    let taken = now.elapsed();
    println!("Total time: {:?}", taken);
}
