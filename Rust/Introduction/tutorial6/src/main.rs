fn main() {
    let x: f64 = 4.0; // 0 - 255
    let y: f64 = 3.14; // -128 - 127

    let z = (x%y) as f32;
    println!("{}", z);
}
