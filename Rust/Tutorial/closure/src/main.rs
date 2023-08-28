
use std::thread;
use std::time::Duration;

// fn simulated_expensive_calculation(intensity: u32) -> u32 {
//     println!("Calculating Slowly...");
//     thread::sleep(Duration::from_secs(2));
//     intensity
// }

struct Cacher<T>
where 
    T: Fn(u32) -> u32
{
    calculation: T,
    value: Option<u32>,
}


// Note: This will be a one time cache for one arg
// For more, use Hasmap instead of one value
impl<T> Cacher<T> 
where
    T: Fn(u32) -> u32
{
    fn new(calculation: T) -> Cacher<T> {
        Cacher { calculation, value: None }
    }

    fn value(&mut self, arg: u32) -> u32 {
        match self.value {
            Some(x) => x,
            None => {
                let res = (self.calculation)(arg);
                self.value = Some(res);
                res
            }
        }
    }
}

fn generate_workout(intensity: u32, random_number: u32) {
    let expensive_closure = | num: u32 | -> u32 {
        println!("Calculating Slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    };

    let mut cacher = Cacher::new(expensive_closure);

    if intensity < 25 {
        println!(
            "Today do {} number of pushups.",
            cacher.value(intensity)
        );
        println!(
            "Next do {} number of situps.",
            cacher.value(intensity)
        );
    }
    else {
        if random_number==3 {
            println!("Take a break! Stay hydrated");
        }
        else {
            println!(
                "Today you run for {} minutes",
                cacher.value(intensity)
            );
        }
    }
}

fn main() {
    let simulated_intensity = 72;
    let simulated_random_number = 10;

    generate_workout(simulated_intensity, simulated_random_number);
}
