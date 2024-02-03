
use std::io;

fn call_fibonacci1(n: i32) -> i32{
    if n == 1 || n == 0 {
        return 1;
    }else{
        return 1 + call_fibonacci1(n-1) + call_fibonacci1(n -2);
    }
}

fn call_fibonacci2(n: i32) -> i32{
    if n==1 {
        return 1;
    }
    if n==0 {
        return 0;
    }
    return call_fibonacci2(n-1) + call_fibonacci2(n-2);
}

fn main() {
    let mut n_str = String::new();
    
    io::stdin().read_line(&mut n_str).expect("");
    let n: i32 = n_str.trim().parse().expect("");
    let mut count = n;
  
    while count != 0 {
        let mut n_tst = String::new();
        io::stdin().read_line(&mut n_tst).expect("");
        let x: i32 = n_tst.trim().parse().expect("");
        println!("fib({}) = {} calls = {}",x, call_fibonacci1(x) -1, call_fibonacci2(x));
        count -= 1;
    }
}