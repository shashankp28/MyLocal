use std::fmt::Display;

pub struct NewsArticle {
    pub author: String,
    pub headline: String,
    pub content: String,
}

impl Summary for NewsArticle {

    fn summarize_author(&self) -> String {
        format!("{}", self.author)
    }

}


pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {

    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }

    fn summarize(&self) -> String {
        format!("Tweet: @{}: {}", self.username, self.content)
    }
}

pub fn notify(item: &impl Summary) {
    println!("Breaking News: {}", item.summarize());
}

// pub fn notify(item: &(impl Summary+Display)) {
//     println!("Breaking News: {}", item.summarize());
// }


// pub fn some_function<T: Display+Clone, U: Clone+Debug>(t: &T, u: &U) -> i32 {
//     
// }
// pub fn some_function<T, U>(t: &T, u: &U) -> i32
//     where T: Display+Clone,
//             U: Clone+Debug
// {
//     
// }


pub fn notify_trait_bound<T: Summary>(item: &T) {
    println!("Breaking News: {}", item.summarize());
}

pub fn notify_same<T: Summary>(item1: &T, item2: &T){
    println!("Double Notification: {}, {}", item1.summarize(), item2.summarize())
}

pub trait Summary  {

    fn summarize_author(&self) -> String;

    fn summarize(&self) -> String {
        format!("(Read more from {}...)", self.summarize_author())
    }
}

fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("shashankp"),
        content: String::from("Hello everyone"),
        reply: true,
        retweet: true
    }
}

struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn new(x: T, y: T) -> Self {
        Self {x, y}
    }
}


impl<T: PartialOrd+Display> Point<T> {
    fn comp_display(&self) {
        if self.x>=self.y {
            println!("x is greater than y! x={}", self.x);
        }
        else {
            println!("y is greater than x! y={}", self.y);
        }
    }
}


fn main() {
    let tweet = Tweet {
        username: String::from("elonmusk"),
        content: String::from("Bitcoin!   Bitcoin!     Bitcoin!"),
        reply: false,
        retweet: false
    };

    let article = NewsArticle {
        author: String::from("Virat Kohli"),
        headline: String::from("Introduction to Cricket"),
        content: String::from("Cricket is an awesome sport to play!!"),
    };

    println!("Tweet Summary: {}", tweet.summarize());
    println!("Article Summary: {}", article.summarize());

    notify(&tweet);
    notify_trait_bound(&article);
    notify_same(&tweet, &tweet);
    // notify_same(&article, &tweet); -> Error

    println!("{}", returns_summarizable().summarize());

    let point = Point::new(112.25, 63.25);
    point.comp_display();
}
