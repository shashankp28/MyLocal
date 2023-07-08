fn main() {
    println!("Hello, world!");

    let mut x: i32 = -8;
    println!("x = {}", x);
    x = -6;
    println!("x = {}", x);
    let floating: f32 = 78.123;
    println!("floating = {}", floating);

    let true_or_false: bool = true;
    println!("bool = {}", true_or_false);

    let letter: char = 'a';
    println!("letter = {}", letter);

    let mut tup: (i32, bool, char) = (4, false, 'a');
    tup.0 = 6;
    println!("tup = {}", tup.0);

    let mut arr = [1, 2, 3, 4, 5];
    arr[2] = 5;
    println!("arr = {}", arr[2]);

    let arr2: [i32; 3] = [1, 2, 3];
    println!("arr = {}", arr2[2]);

    let x:f32 = 4.34;
    let y:i32 = x as i32;
    println!("{}, {}", x, y);
}
