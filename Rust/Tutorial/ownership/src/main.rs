fn takes_ownership(some_string: String) {
    println!("Some string is: {}", some_string);
}

fn makes_copy(x: i32) {
    println!("The square is {}", x*x);
}

fn take_and_give_back(a_string: String) -> String {
    a_string
}

fn get_length(str: &String) -> usize {
    str.len()
}

fn modify_string(str: &mut String) {
    str.push_str(", world");
}

// fn pointer_to_nothing() -> &String {
//     let s = String::from("world!!");
//     &s;
// }

fn first_word(str: &String) -> usize {
    for (i, ch) in str.chars().enumerate() {
        if ch==' ' {
            return i;
        }
    }
    str.len()
}

fn main() {
    let x = 5;
    let y = x;
    println!("{}, {}", x, y);

    let s1 = String::from("Hello");
    let s2 = s1.clone();
    println!("{}, {}", s1, s2);

    takes_ownership(s1.clone());
    makes_copy(x);

    let s3: String = take_and_give_back(s1);
    println!("s3: {}", s3);

    println!("Length of {} is {}", s3, get_length(&s3));

    let mut s4 = String::from("Hello");
    modify_string(&mut s4);
    println!("{}", s4);

    let r1 = &s4;
    let r2 = &s4;
    println!("{}, {}", r1, r2);
    
    let r3 = &mut s4;
    println!("{}", r3);

    let word = String::from("Helloooooooo World");
    println!("First word ends at: {}", first_word(&word));

    let s6 = String::from("Hello World Here!");
    let s7 = &s6[0..7];
    let s8 = &s6[4..8];
    println!("{}, {}, {}", s6, s7, s8);

    // let a = [0; 9];
    // let slice = &a[7..9];
}
