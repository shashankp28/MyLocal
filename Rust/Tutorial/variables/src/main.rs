fn another_function(x: i32, y: i32) -> i32 {
    println!("Hello From here! {}, {}", x, y);
    x*y
}

fn main() {
    let tup = ("Hello, World", 45, 12);
    let (sentance, age, street) = tup;
    let street2 = tup.2;

    let fibs = [0, 1, 1, 2, 3, 5, 8, 13];
    let fifth_term = fibs[4];
    let byte = [8; 35];

    println!("{}, {}, {}", sentance, age, street);
    println!("{}, {}, {}", fifth_term, byte[5], street2);

    let mul = another_function(34, 265);
    println!("multiply is {}", mul);


    let num = false;
    if num {
        println!("If block");
    }
    else {
        println!("Else block")
    }
    let number = if num {10} else {50};
    println!("The number is {}", number);

    let mut i = 0;
    let result = loop {
        println!("This is a loop {}", i);
        i+=4;
        if i>10 {
            break i;
        }
    };
    println!("The final i value is {}", result);

    let mut i = 0;
    while i<10 {
        println!("Counting Up! {}", i);
        i+=4;
    }

    for num in fibs.iter() {
        println!("Fibonacci number {}", num);
    }

    for num in 1..4 {
        println!("Normal number {}", num);
    }

    // Line Comment
    /*
        Block comments
     */
}