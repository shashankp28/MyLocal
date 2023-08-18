use std::fs::{self,File};
use std::io::{self,ErrorKind, Write, Read};
use std::error::Error;

fn c(num: i32){
    if num==22 {
        panic!("Dont use 22!!");
    }
}

fn b(){
    c(21);
}

fn a(){
    b();
}

fn read_username_from_file() -> Result<String, io::Error> {

    // let f = File::open("hello.txt");
    // let mut f = match f {
    //     Ok(file) => file,
    //     Err(e) => return Err(e),
    // };
    // match f.read_to_string(&mut s) {
    //     Ok(_) => Ok(s),
    //     Err(e) => Err(e)
    // }
    // f.read_to_string(&mut s)?;

    // Similar to above
    // let mut s = String::new();
    // File::open("hello.txt")?.read_to_string(&mut s)?;
    // Ok(s)

    fs::read_to_string("hello.txt")
}

fn main() -> Result<(), Box<dyn Error>> {
    a();

    // let f = File::open("hello.txt");
    // let mut f = match f {
    //     Ok(file) => file,
    //     Err(eo) => match eo.kind() {
    //         ErrorKind::NotFound => match File::create("hello.txt") {
    //             Ok(fc) => fc,
    //             Err(ec) => panic!("Error creating the file: {:?}", ec),
    //         },
    //         _ => panic!("Error opening the file: {:?}", eo),
    //     }
    // };

    let f = File::open("hello.txt").unwrap();
    let f = File::open("hello.txt").expect("Cannot open hello.txt file");
    let f = File::open("hello.txt")?;
    Ok(())
}
