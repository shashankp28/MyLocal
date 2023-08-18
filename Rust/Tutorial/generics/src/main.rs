#[derive(Debug)]
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {

    fn x(&self) -> &T {
        &self.x
    }

    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point { x: self.x, y: other.y }
    }

}

impl Point<f64, f64> {
    fn y(&self) -> f64 {
        self.y
    }
}

fn get_largest<T: PartialOrd+Copy>(arr: Vec<T>) -> T {
    let mut largest = arr[0];
    for num in arr {
        if num > largest {
            largest = num;
        }
    }
    largest
}

fn main() {
    let num_list = vec![141, 201, 385, 40, 55];
    println!("Largest Number 1 is: {}", get_largest(num_list));
    let num_list = vec![141, 1, 385, 76452, 55, 987, 11, 3847];
    println!("Largest Number 2 is: {}", get_largest(num_list));
    let char_list = vec!['a', 'b', 'z', 'b', 'n', 'x'];
    println!("Largest Number 3 is: {}", get_largest(char_list));

    let p1 = Point { x: 3, y:5 };
    let p2 = Point {x: 10.98, y: 89.76};

    println!("{}, {}", p1.x(), p2.y());

    let p3 = Point {x: 3, y: 'a'};
    let p4 = Point {x:'b', y:12.45};
    println!("{:?}", p3.mixup(p4));
}
