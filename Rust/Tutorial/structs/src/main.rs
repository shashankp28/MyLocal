struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {

    fn area(&self) -> u32 {
        self.height * self.width
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

impl Rectangle {
    fn square(size: u32) -> Rectangle {
        Rectangle { 
            width: size, 
            height: size 
        }
    }
}

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1
    }
}

fn main() {
    let mut user1 = User {
        username: String::from("shashankp28"),
        email: String::from("shashankp2832@gmail.com"),
        sign_in_count: 1,
        active: true
    };

    let name = user1.username;
    user1.username = String::from("newUserName");
    println!("{}", name);

    let user2 = build_user(String::from("megamewtube150@gmail.com"), 
                        String::from("mystic_mickey"));
    println!("{}, {}", user2.username, user2.email);

    let user3: User = User {
        username: String::from("hello world"),
        email: String::from("myemail"),
        ..user1
    };
    println!("{}, {}", user3.sign_in_count, user3.active);


    let rect = Rectangle {
        width: 5,
        height: 6,
    };

    println!("Area of rectangle is {}", rect.area());
    println!("{:#?}", rect);

    let rect2 = Rectangle {
        width: 1,
        height: 2,
    };
    println!("{}", rect.can_hold(&rect2));

    let rect3 = Rectangle::square(5);
    println!("{:?}", rect3);
}
