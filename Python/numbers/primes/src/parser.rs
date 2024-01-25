use clap::Parser;
use num_bigint::BigUint;

#[derive(clap::ValueEnum, Clone, Debug, PartialEq, Eq)]
pub enum Analysis {
    Standard,
    Fermat,
    Generate,
    Power,
}

#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
pub struct Args {
    /// The target number to be analyzed
    #[arg(short, long)]
    pub target: BigUint,

    /// The analysis to be done
    #[arg(short, long)]
    pub analysis: Analysis,

    /// The power to be raised to (Only used when analysis is Power)
    #[arg(short, long)]
    pub power: Option<BigUint>,

    /// Number upto which primes to be generated (Only used when analysis is Generate)
    #[arg(short, long)]
    pub maximum: Option<u64>,
}
