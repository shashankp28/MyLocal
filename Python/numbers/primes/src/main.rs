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
    if args.analysis == parser::Analysis::Power {
        let power = match args.power {
            Some(power) => power,
            None => {
                println!("Use <exe> --help for more information (--power is required)");
                return;
            }
        };
        println!("Prime power {}: {}", args.target, pow(&args.target, &power));
    } else if args.analysis == parser::Analysis::Standard {
        let now = Instant::now();
        let is_prime = standard(&args.target);
        let elapsed = now.elapsed();
        println!("Standard: {} is prime: {} in {:?}", args.target, is_prime, elapsed);
    } else if args.analysis == parser::Analysis::Fermat {
        let now = Instant::now();
        let is_prime = fermat(&args.target);
        let elapsed = now.elapsed();
        println!("Fermat: {} is prime: {} in {:?}", args.target, is_prime, elapsed);
    } else if args.analysis == parser::Analysis::Generate {
        let maximum = match args.maximum {
            Some(maximum) => maximum,
            None => {
                println!("Use <exe> --help for more information (--maximum is required)");
                return;
            }
        };
        let primes = get_max_primes(maximum);
        println!("Primes upto {}: {:?}", maximum, primes);
    } else {
        println!("Use <exe> --help for more information");
    }
    let taken = now.elapsed();
    println!("Total time: {:?}", taken);
}
