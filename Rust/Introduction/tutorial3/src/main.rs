fn main() {
    let mut x = 4;
    println!("Value of x is: {}", x);

    {
        let x = x + 10;
        println!("Inside Value of x is: {}", x);
    }

    x = x + 2;
    println!("Value of x is: {}", x);

    const SECOND: i32 = 1;
    println!("second is: {}", SECOND);
}
