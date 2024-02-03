use std::io::{self, BufRead};
fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    while let Some(Ok(line)) = lines.next() {
        let mut flag = 0;

        for c in line.chars() {
            match c {
                '(' => flag += 1,
                ')' => {
                    flag -= 1;
                    if flag < 0 {
                        break;
                    }
                }
                _ => {}
            }
        }

        if flag == 0 {
            println!("correct");
        } else {
            println!("incorrect");
        }
    }
}


// 382.9109
// 388.0938