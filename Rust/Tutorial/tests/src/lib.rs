#[derive(Debug)]
pub struct Rectangle {
    width: u32,
    height: u32
}

impl Rectangle {
    pub fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

pub fn greeting(name: &str) -> String {
    format!("Hello {}!", &name)
}

pub struct Guess {
    guess: i32
}

impl Guess {
    pub fn new(val: i32) -> Guess {
        if val < 1 {
            panic!("Guess must be greater than eq. 1");
        }
        else if val > 100 {
            panic!("Guess must be less than eq. 100");
        }
        Guess {guess: val}
    }
}

pub fn print_and_return_10(a: i32) -> i32 {
    println!("I got a value: {}", a);
    10
}

pub fn add_two(a: i32) -> i32 {
    inner_adder(a, 2)
}

fn inner_adder(a: i32, b: i32) -> i32 {
    a+b
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 10,
            height: 8
        };
        let smaller = Rectangle {
            width: 5,
            height: 4
        };
        assert!(larger.can_hold(&smaller));
    }

    #[test]
    fn smaller_cant_larger() {
        let larger = Rectangle {
            width: 10,
            height: 8
        };
        let smaller = Rectangle {
            width: 5,
            height: 4
        };
        assert_ne!(smaller.can_hold(&larger), true);
    }

    #[test]
    fn check_greetings() {
        let name = "Carol";
        let result = greeting(name);
        assert!(
            result.contains(name),
            "Greetings did not contain name but value `{}`",
            result
        );
    }

    #[test]
    #[should_panic(expected="Guess must be greater than eq. 1")]
    fn must_panic_guess() {
        let g = Guess::new(-2);
        println!("{}", g.guess);
    }

    #[test]
    fn checker() -> Result<(), String> {
        if 2+2==4 {
            Ok(())
        }
        else {
            Err(String::from("2+2 not equal to 4??!!"))
        }
    }

    #[test]
    fn it_works() -> Result<(), String> {
        if 2+2==4 {
            Ok(())
        }
        else {
            Err(String::from("2+2 is not equal to 4"))
        }
    }

    #[test]
    fn it_works_2() {
        assert_eq!(2+2, 4);
    }

    #[test]
    fn this_test_pass() {
        let val = print_and_return_10(4);
        assert_eq!(val, 10);
    }

    #[test]
    #[ignore]
    fn this_test_fail() {
        let val = print_and_return_10(4);
        assert_eq!(val, 4);
    }

    #[test]
    fn internal() {
        assert_eq!(4, inner_adder(2, 2));
    }

}
