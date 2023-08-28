use std::process;
use std::env;
use minigrep::Config;

  
fn main() {
    
    let err_handler = | err: &str | {
        eprintln!("Problem Parsing Arguments: {}", err);
        process::exit(1);
    };
    let config = Config::new(env::args()).unwrap_or_else(err_handler);

    println!("Searching: {}", config.query);
    println!("File: {}", config.filename);

    if let Err(e) = minigrep::run(config) {
        eprintln!("Application Error: {}", e);
        process::exit(1);
    }
}
