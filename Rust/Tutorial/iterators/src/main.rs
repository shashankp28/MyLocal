#[derive(PartialEq, Debug)]
struct Shoe {
    size: u32,
    style: String
}

fn shoes_that_fit(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|x: &Shoe| x.size==shoe_size).collect()
}

#[test]
fn iterator_test() {
    let v1 = vec![1, 2, 3];
    let mut v1_iter = v1.iter();

    assert_eq!(v1_iter.next(), Some(&1));
    assert_eq!(v1_iter.next(), Some(&2));
    assert_eq!(v1_iter.next(), Some(&3));
    assert_eq!(v1_iter.next(), None);
}

#[test]
fn sum_test() {
    let v1 = vec![1, 2, 3];
    let v1_iter = v1.iter();
    let total: i32 = v1_iter.sum();
    assert_eq!(total, 6);
}

#[test]
fn map_test() {
    let v1 = vec![1, 2, 3, 4, 5];
    let v2: Vec<i32> = v1.iter().map(|x| x+1).collect();
    assert_eq!(vec![2, 3, 4, 5, 6], v2);
}

#[test]
fn shoe_test() {
    let shoes = vec![
        Shoe{size: 10, style: String::from("boots")},
        Shoe{size: 13, style: String::from("sandal")},
        Shoe{size: 12, style: String::from("chappal")},
        Shoe{size: 10, style: String::from("crocs")},
    ];
    let shoes_in_my_size = shoes_that_fit(shoes, 10);
    assert_eq!(shoes_in_my_size.len(), 2);
    assert_eq!(shoes_in_my_size, vec![
        Shoe{size: 10, style: String::from("boots")},
        Shoe{size: 10, style: String::from("crocs")},
    ])

}

struct Fib {
    term_1: u32,
    term_2: u32,
    count: u32,
    n: u32,
}

impl Fib {
    fn new(n: u32) -> Fib {
        Fib {
            term_1: 1,
            term_2: 0,
            count: 0,
            n
        }
    }
}

impl Iterator for Fib {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count < self.n {
            self.count += 1;
            if self.count==1 {
                Some(self.term_2)
            }
            else if self.count==2 {
                Some(self.term_1)
            }
            else {
                let temp = self.term_1;
                self.term_1 += self.term_2;
                self.term_2 = temp;
                Some(self.term_1)
            }
        }
        else {
            None
        }
    }
}

#[test]
fn fib_test() {
    let mut fib_nums = Fib::new(7);
    let actual: Vec<u32>= vec![0, 1, 1, 2, 3, 5, 8];
    for i in 0..7 {
        assert_eq!(fib_nums.next(), Some(actual[i]));
    }
    assert_eq!(fib_nums.next(), None);
}

#[test]
fn fib_product_test() {
    let sum: u32 = Fib::new(7)
        .zip(Fib::new(7).skip(1))
        .map(|(a, b)| a*b)
        .filter(|a| a%3==0)
        .sum();

    assert_eq!(sum, 21)
}


fn main() {
    let v1 = vec![1, 2, 3];
    let v1_iter = v1.iter();


    let shoes = vec![
        Shoe{size: 10, style: String::from("boots")},
        Shoe{size: 13, style: String::from("sandal")},
        Shoe{size: 12, style: String::from("chappal")},
        Shoe{size: 10, style: String::from("crocs")},
    ];
    let shoes_in_my_size = shoes_that_fit(shoes, 10);
    assert_eq!(shoes_in_my_size.len(), 2);
    assert_eq!(shoes_in_my_size, vec![
        Shoe{size: 10, style: String::from("boots")},
        Shoe{size: 10, style: String::from("crocs")},
    ]);

    for value in v1_iter {
        println!("{}", value);
    }

    for value in Fib::new(7) {
        println!("{}", value);
    }
}
