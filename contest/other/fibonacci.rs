fn main() {
	let mut ans = [0; 31];
	ans[1] = 1;
	for i in 2..31 {
		ans[i] = ans[i-1]+ans[i-2];
	}
	for i in 0..31 {
		println!("{}", ans[i]);
	}
}