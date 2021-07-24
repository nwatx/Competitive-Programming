import java.io.*;

import java.util.*;


public class Main {
	// CodeSnip{Kattio}
	private static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		// standard input

		public Kattio() { this(System.in,System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}

		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName+".out"));
			r = new BufferedReader(new FileReader(problemName+".in"));
		}
		// returns null if no more input

		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) {}
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
	public static void main(String[] args) {
		Kattio io = new Kattio();

		int N = io.nextInt();
		int[] H = new int[N + 1], dp = new int[N + 1];
	
		for(int i = 1; i <= N; ++i) {
			H[i] = io.nextInt();
			dp[i] = Integer.MAX_VALUE;
		}
	
		dp[1] = 0;
 
		for(int i = 1; i <= N; ++i) {
			if(i + 1 <= N)
				dp[i + 1] = Math.min(dp[i + 1], dp[i] + Math.abs(H[i] - H[i + 1]));
			if(i + 2 <= N)
				dp[i + 2] = Math.min(dp[i + 2], dp[i] + Math.abs(H[i] - H[i + 2]));
		}
		
		System.out.println(dp[N]);
	}
}