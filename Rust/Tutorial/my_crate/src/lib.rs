//! # My Crate
//! 
//! `my_crate` is a collection of utilities to makeperforming
//! operations more convinient

/// Adds one to a given numer
/// 
/// # Examples
/// 
/// ```
/// let arg = 5;
/// let answer = my_crate::add_one(arg);
/// 
/// assert_eq!(6, answer);
/// ```
pub fn add_one(x: i32) -> i32 {
    x+1
}