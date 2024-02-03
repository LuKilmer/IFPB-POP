use std::io;

fn main() {
    let mut hora_comeco = 0;
    let mut minuto_comeco = 0;
    let mut hora_final = 0;
    let mut minuto_final = 0;

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Falha ao ler");
    let words: Vec<&str> = input.split_whitespace().collect();
    
    if let Ok(n1) = words[0].parse::<i32>() {
        hora_comeco = n1;
    }
    if let Ok(n2) = words[1].parse::<i32>() {
        minuto_comeco = n2;
    }
    if let Ok(n3) = words[2].parse::<i32>() {
        hora_final = n3;
    }
    if let Ok(n4) = words[3].parse::<i32>() {
        minuto_final = n4;
    }
    let total_final = hora_final * 60 + minuto_final;
    let total_comeco = hora_comeco * 60 + minuto_comeco;
    if total_final == total_comeco {
        println!("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)");
    } else if total_final < total_comeco {
        println!("O JOGO DUROU {} HORA(S) E {} MINUTO(S)", (total_final + 60 * 24 - total_comeco) / 60, (total_final + 60 * 24 - total_comeco) % 60);
    } else {
        println!("O JOGO DUROU {} HORA(S) E {} MINUTO(S)", (total_final - total_comeco) / 60, (total_final - total_comeco) % 60);
    }
}
