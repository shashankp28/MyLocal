use rand::{Rng, CryptoRng};
use std::io::{self, Write};
use std::io::*;

fn serve_order() {}

mod front_of_house;

mod back_of_the_house {
    fn fix_incorrect_order() {
        cook_order();
        super::serve_order();
    }
    fn cook_order() {}

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    pub enum Appetizer {
        Soup,
        Salad,
    }
}


pub use self::front_of_house::hosting;
use std::fmt::Result;
use std::io::Result as IoResult;

pub fn eat_at_restaurant() {
    crate::front_of_house::hosting::add_to_waitlist();
    front_of_house::hosting::add_to_waitlist();
    let mut meal = back_of_the_house::Breakfast::summer("Bread");
    meal.toast = String::from("Rye");

    let order1 = back_of_the_house::Appetizer::Soup;
    let order2 = back_of_the_house::Appetizer::Salad;

    hosting::add_to_waitlist();
    hosting::add_to_waitlist();
    hosting::add_to_waitlist();

    let secret_number = rand::thread_rng().gen_range(0..10);
}