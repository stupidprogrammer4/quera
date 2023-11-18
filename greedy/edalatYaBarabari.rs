use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin()
        .read_line(&mut buf)
        .unwrap();

    let data: Vec<i64> = buf.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
    let (_, d) = (data[0], data[1]);
    let mut buf = String::new();
    io::stdin()
        .read_line(&mut buf)
        .unwrap();
    let a: Vec<i64> = buf.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();

    let mx = a.iter().max().unwrap() - d;
    let mut ans: i64 = 0;

    for i in a {
        if mx - i <= 0 {
            continue;
        }
        ans = ans + (mx - i);
    }
    println!("{ans}")

}
