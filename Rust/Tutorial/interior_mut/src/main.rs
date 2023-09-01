use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug)]
enum List {
    Cons(RefCell<i32>, Rc<List>),
    Nil,
}

use crate::List::*;

fn main() {
    let a = Rc::new(Cons(RefCell::new(5), Rc::new(Nil)));


    let b = a.clone();
    let c = a.clone();

    if let List::Cons(i32_refcell, _) = &*a {
        let mut i32_value = i32_refcell.borrow_mut();
        *i32_value += 10; // Modify the value, for example
        println!("i32 value inside Cons: {}", *i32_value);
    }

    println!("{:?}, {:?}, {:?}, {}", a, b, c, Rc::strong_count(&a));

}
