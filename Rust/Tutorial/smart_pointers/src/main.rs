use std::ops::Deref;
use std::rc::Rc;

#[derive(Debug)]
enum List {
    Cons(i32, Rc<List>),
    Nil,
}

struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {

    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

fn hello(name: &str) {
    println!("Hello, {}!", name);
}

struct CustomSmartPointer {
    data: String,
}

impl Drop for CustomSmartPointer {
    fn drop(&mut self) {
        println!("Dropping custom smart-pointer {}", self.data);
    }
}

use List::{Cons,Nil};

fn main() {
    let list = Rc::new(Cons(1, Rc::new(Cons(2, Rc::new(Cons(3, Rc::new(Nil)))))));
    println!("{:?}", list);

    let x = 5;
    let y = MyBox::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);

    let m = MyBox::new(String::from("Shashank P"));
    hello(&m);
    // &MyBox<String> -> &String -> &str
    hello(&(*m)[..]);

    // Deref Coercion (Forced Automatic Deref) ->
    // 1. &T to &U
    // 2. &mut T to &U
    // 3. &mut T to &mut U
    // Rust cannot perform deref coercion for &T to &mut U
    
    let c = CustomSmartPointer{
        data: String::from("Hello"),
    };
    let d = CustomSmartPointer{
        data: String::from("World"),
    };

    println!("Smart Pointers: {}, {}", c.data, d.data);

    println!("Custom Smart Pointer Created");
    drop(c);
    println!("Dropped c before main end");

    println!("Count after adding list = {}", Rc::strong_count(&list));
    let b = Cons(3, Rc::clone(&list));
    println!("Count after adding b{:?} -> list  = {}", b, Rc::strong_count(&list));
    {
        let c = Cons(4, Rc::clone(&list));
        println!("Count after adding c{:?} -> list  = {}", c, Rc::strong_count(&list));
    }
    println!("Count after c goes out = {}", Rc::strong_count(&list));
    
    let v1 = 10;
    let v2 = &mut v1;

    let mut v3 = 11;
    let v4 = &v3;
    *v4 = 20;

}
