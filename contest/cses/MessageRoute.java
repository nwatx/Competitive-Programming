import java.io.*;

import java.util.*;


public class MessageRoute {
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

	private static Map<Integer, LinkedList<Integer>> adj = new HashMap<>();

	public static void main(String[] args) {
		Kattio io = new Kattio();

		int n = io.nextInt(), m = io.nextInt();
		for(int i = 0; i < m; i++) {
			int a = io.nextInt(), b = io.nextInt();
			if(adj.get(a) == null) {
				adj.put(a, new LinkedList<>());
			}

			if(adj.get(b) == null) {
				adj.put(b, new LinkedList<>());
			}

			adj.get(a).add(b);
			adj.get(b).add(a);
		}

		int[] prev = new int[n+1], dist = new int[n+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[1] = 1;

		Queue<Integer> bfs = new LinkedList<>();
		bfs.add(1);

		while(!bfs.isEmpty()) {
			int top = bfs.poll();
			if(dist[top] == Integer.MAX_VALUE) continue;
			if(adj.get(top) != null) {
				for(int e : adj.get(top)) {
					if(dist[e] == Integer.MAX_VALUE) {
						dist[e] = dist[top] + 1;
						prev[e] = top;
						bfs.add(e);
					}
				}
			}
		}

		if(dist[n] == Integer.MAX_VALUE) {
			System.out.println("IMPOSSIBLE");
		} else {
			System.out.println(dist[n]);
			int[] res = new int[dist[n]];
			int i = dist[n]-1;
			for(int x = n; x != 0; x = prev[x]) {
				res[i--] = x;
			}
			for(int a : res) System.out.print(a + " ");
		}
	}
}
