use std::collections::HashMap;

fn two_sum(nums: Vec<i32>, target: i32) -> Option<(usize, usize)> {
    let mut nums_calc = HashMap::new();

    for (i, &num) in nums.iter().enumerate() {
        let compliment = target - num;
        if let Some(&index) = nums_calc.get(&compliment) {
            return Some((index, i));
        }
        nums_calc.insert(num, i);
    }
    None
}
fn main() {
    println!("Hello, world!");
    //let nums = vec![2,7,11,15];
    //let target = 9;
    //let nums = vec![1,3,7,9,2];
    //let target = 11 ;
    let nums = vec![3, 3];
    let target = 6;

    match two_sum(nums, target) {
        Some((i, j)) => println!("Indices: {}, {}", i, j),
        None => println!("No solution found"),
    }
}
