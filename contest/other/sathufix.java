import java.util.*;
import java.io.*;
    
public class sathufix {
	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
	
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName + ".out"));
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
	
		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
	
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
    public static void main(String[] args) {
        Kattio io = new Kattio();

        int n = io.nextInt();
        int[][] problems = new int[n][3];
		
        for (int i = 0; i < n; i++) {
            problems[i][0] = io.nextInt();
            problems[i][1] = io.nextInt();
            problems[i][2] = io.nextInt();
        }

		int num = 0;

        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = 0; j < 3; j++) {
                if(problems[i][j]==1){
                    temp++;
                }
            }
            if(temp >= 2){
                num++;
            }
        }
        System.out.println(num);
        io.close();                  
    }
}