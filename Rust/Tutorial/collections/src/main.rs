use unicode_segmentation::UnicodeSegmentation;
use std::collections::HashMap;

fn main() {
    let a = [1, 2, 3];
    println!("{:?}", a);
    let mut v: Vec<i32> = Vec::new();
    v.push(1);
    v.push(2);
    v.push(3);

    let mut v2 = vec![1, 2, 3, 4, 5];
    let third = &v2[2];
    println!("{}", third);

    match v2.get(20) {
        Some(ele) => println!("Third element {}", ele),
        None => println!("Index out of bounds!"),
    }

    for i in &mut v2 {
        *i += 50;
    }
    for i in &v2 {
        println!("{}", i);
    }

    enum SpreadSheet {
        Int(i32),
        Float(f32),
        Text(String),
    }

    let row = vec![
        SpreadSheet::Int(3),
        SpreadSheet::Float(1.25478),
        SpreadSheet::Text(String::from("hello World")),
    ];
    match &row[1] {
        SpreadSheet::Text(s) => {
            println!("The text is {}", s);
        },
        _ => println!("Nothing Interesting"),
    }

    // Strings
    let s1 = String::new();
    let s2 = "initial values";
    let s3 = s2.to_string();
    let mut s4 = String::from("Hello World");

    println!("{}, {}, {}, {}", s1, s2, s3, s4);

    s4.push_str("Hello");
    s4.push('!');
    println!("{}", s4);

    let mut s5 = s3 + &s4;
    println!("{}, {}", s4, s5);
    s5 = format!("{}{}", s5, s5);
    println!("{}", s5);

    let hello = String::from("नमस्ते");
    println!("{}", hello);

    // Bytes
    for b in hello.bytes() {
        println!("{}", b);
    }

    // Scalars
    for c in hello.chars() {
        println!("{}", c);
    }

    // Grapheme Clusters (Have to import)
    for g in hello.graphemes(true) {
        println!("{}", g);
    }

    let blue = String::from("Blue");

    let mut scores: HashMap<String, i32> = HashMap::new();
    scores.insert(blue, 52);

    let team_name = String::from("Blue");
    let score = scores.get(&team_name);
    match score {
        Some(x) => {
            println!("The team score is {}", x);
        }
        None => {
            println!("Team does not exist");
        }
    }

    scores.insert(String::from("Blue"), 20);
    scores.insert(String::from("Blue"), 30);

    scores.entry(String::from("Yellow")).or_insert(40);
    scores.entry(String::from("Yellow")).or_insert(50);

    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }

    // Word Counter
    let text = "hello world wonderful world hello hello";
    let mut wc: HashMap<&str, i32> = HashMap::new();

    for word in text.split_whitespace() {
        let count = wc.entry(word).or_insert(0);
        *count += 1;
    }
    println!("{:?}", wc);

}
