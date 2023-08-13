#[derive(Debug)]
enum IpAddrKind {
    V4(u8, u8, u8, u8),
    V6(String),
}

enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn some_function(&self) {
        match self {
            Message::Quit => {
                println!("Quitting the application");
            }
            Message::Move { x, y } => {
                println!("Moving to x: {} and y: {}", x, y);
            }
            Message::Write(text) => {
                println!("Writing message: {}", text);
            }
            Message::ChangeColor(r, g, b) => {
                println!("Changing color to RGB({}, {}, {})", r, g, b);
            }
        }
    }
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(State),
}

#[derive(Debug)]
enum State {
    Karnataka,
}

impl Coin {
    fn value_in_cents(&self) -> u8 {
        match self {
            Coin::Penny => 1,
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter(state) => {
                println!("The state is {:?}", state);
                25
            },
        }
    }
}

fn add_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i+1),
    }
}

fn add_one_default(x: Option<i32>) -> Option<i32> {
    match x {
        Some(i) => Some(i+1),
        _ => None,
    }
}

fn check_str(s: &Option<String>) {
    match s {
        None => println!("This is None"),
        Some(s) => println!("This is string {}", s),
    }
}

fn main() {
    let four = IpAddrKind::V4(127, 0, 0, 1);
    let six = IpAddrKind::V6(String::from("Ipv6 Address"));

    println!("{:?}, {:?}", four, six);
    let message1 = Message::Quit;
    let message2 = Message::Move{x:5, y:8};
    let message3 = Message::Write(String::from("My Signature"));
    let message4 = Message::ChangeColor(84, 32, 14);
    message1.some_function();
    message2.some_function();
    message3.some_function();
    message4.some_function();

    let some_number = Some(5);
    let some_string = Some(String::from("hello-world"));
    let null_string: Option<String> = None;

    println!("{:?}, {:?}, {:?}", some_number, some_string, null_string);

    let x = Some(8);
    let y = 5;
    let z = None;
    let w = y;
    println!("{:?}, {}, {:?}, {}", x, y, z, w);

    println!("{}", x.unwrap_or(0)+z.unwrap_or(0));

    let coin = Coin::Penny;
    let nickel = Coin::Nickel;
    let dime = Coin::Dime;
    let quarter = Coin::Quarter(State::Karnataka);
    println!("{}, {}, {}, {}", 
        coin.value_in_cents(),
        nickel.value_in_cents(),
        dime.value_in_cents(),
        quarter.value_in_cents(),
     );

    let five = Some(5);
    let six = add_one(five);
    let six2 = add_one_default(five);
    let none = add_one(None);

    println!("{:?}, {:?}, {:?}, {:?}", five, six, six2, none);

    let st = Some(String::from("Hello World"));
    check_str(&st);
    println!("{:?}", st);

    if let Some(5) = five {
        println!("{:?}", five);
    }
}
