use std::io;

fn check(a: i32, b: i32, c: i32, d: i32, n: i32) -> bool {
    n % a == 0 && n % b != 0 && c % n == 0 && d % n != 0
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Falha ao ler");

    let numbers: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap_or(0))
        .collect();

    let a = numbers.get(0).cloned().unwrap_or(0);
    let b = numbers.get(1).cloned().unwrap_or(0);
    let c = numbers.get(2).cloned().unwrap_or(0);
    let d = numbers.get(3).cloned().unwrap_or(0);

    let raiz = (c as f64).sqrt().ceil() as i32;
    let mut answer = c + 1;

    for count in 1..=raiz {
        if c % count == 0 {
            let flag1 = check(a, b, c, d, count);
            let flag2 = check(a, b, c, d, c / count);

            if flag1 && flag2 {
                let aux = count.min(c / count);
                answer = aux.min(answer);
            } else if flag1 {
                answer = count.min(answer);
            } else if flag2 {
                answer = (c / count).min(answer);
            }
        }
    }

    if answer == c + 1 {
        println!("-1");
    } else {
        println!("{}", answer);
    }
}