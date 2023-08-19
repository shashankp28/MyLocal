// Generic Lifetime Annotation (GLA) -> Lifetimes
// Just explains the compilers how lifetimes are related
// Does not change the lifetimes
// & i32, &'a i32, &'a mut i32

use std::fmt::Display;


// The lifetime of returned reference is min(lifetime(x), lifetime(y))
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    }
    else {
        y
    }
}

struct Line<'a> {
    part: &'a str
}

impl<'a> Line<'a> {
    fn return_part(&self, announce: &str) -> &str {
        println!("Important announcement: {}", announce);
        self.part
    }
}

/*
    --> Lifetime Ellisions
    1. Each parameter that is a reference gets a lifetime parameter

    2. If there is exactly one input lifetime parameter it is assigned to all
        output lifetime parameters
    
    3. If there are multiple input parameters but there is &self or &mut self 
        then the lifetime of self is assigned to all output lifetimes parameters


    -- If these 3 rules fail, We have to manually assign lifetimes
*/


fn longest_with_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str
    where T: Display
{
    println!("Announcement: {}", ann);
    if x.len()>y.len() {
        x
    }
    else {
        y
    }
}

fn main() {
    let x = String::from("xyz");
    let result: &str;
    
    {
        let y = String::from("abcdefg");
        result = longest(x.as_str(), y.as_str());
        println!("Longest string: {}", result);
    }
    let z = String::from("abcdesdffg");
    let para = String::from("This is so cool. The monster is big.");
    let first_sentance = para.split('.').next().expect("Could not find sentance");
    let line = Line {
        part: first_sentance,
    };
    println!("{}", line.part);
    println!("{}", line.return_part("Hello World!"));
    println!("{}", longest_with_announcement(x.as_str(), z.as_str(), "This is an announcement"));
}
