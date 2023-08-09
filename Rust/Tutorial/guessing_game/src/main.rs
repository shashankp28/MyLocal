use std::io;
use rand::Rng;
use std::cmp::Ordering;
use colored::*;

fn main() {
    loop{
        println!("\n\nGUESS THE NUMBER!");

        let secret_number = rand::thread_rng().gen_range(1..101);
        println!("----------------------------");
        println!("| The secret number is: {}  |", secret_number);
        println!("----------------------------\n");
        let mut max_chances = 5;
        loop{
            if max_chances<=0 {
                println!("{}", "Oh-Oh! Sorry you lost!!".red());
                break;
            }
            println!("{}", "Please input your guess:".blue());
            let mut guess: String = String::new();
            io::stdin().read_line(&mut guess).expect("Failed to Read Line");
            let guess: u32 = match guess.trim().parse() {
                Ok(num) => num,
                Err(_) => {
                    println!("{}", "Please enter a number!\n".red());
                    continue
                },
            };
            match guess.cmp(&secret_number) {
                Ordering::Less => println!("{}", "Too Small!\n".red()),
                Ordering::Greater => println!("{}", "Too Big!\n".red()),
                Ordering::Equal => {
                    println!("{}", "You Win!\n".green());
                    break;
                }
            };
            max_chances-=1;
            let message = format!("You have {} chances left!", max_chances);
            println!("{}", message.blue());
        }

        let mut retry = String::new();
        println!("Do you want to replay the game? (y/n)");
        io::stdin().read_line(&mut retry).expect("Failed to Read Line");
        let retry = retry.trim();
        if retry=="y" {
            continue;
        }
        else {
            break;
        }
    }
}
