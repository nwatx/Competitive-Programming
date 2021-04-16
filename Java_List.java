import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.System.out;

public class Solution {
    private static final int MOD = (int)(1e9+7), INF = Integer.MAX_VALUE, MAX_N = 100001;
    private static int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    private static final In in = new In();

    private static int N;

    static void solve(int t) {
        
    }

    public static void main(String[] args) throws IOException {
        int n = in.nextInt();
        ArrayList<Integer> al = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            al.add(in.nextInt());
        }

        int t = in.nextInt();
        while(t-- > 0) {
            String type = in.nextLine();
            if(type.equals("Insert")) {
                int a = in.nextInt(), b = in.nextInt();
                al.add(a, b);
            } else {
                int a = in.nextInt();
                al.remove(a);
            }
        }

        for(int i = 0; i < al.size(); i++) {
            out.print(al.get(i));
            if(i != al.size()-1) out.print(" ");
        }
    }

    private static class Pair<T, V> { T l; V r; Pair() {} Pair(T l, V r) { this.l = l; this.r = r; } }
    private static class In {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public In() { reader = new BufferedReader(new InputStreamReader(System.in), 32768); }
        public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) { try { tokenizer = new StringTokenizer(reader.readLine()); } catch (IOException e) { throw new RuntimeException(e); } } return tokenizer.nextToken(); }
        public int nextInt() { return Integer.parseInt(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public char nextChar() { return next().charAt(0); }
        public String nextLine() { String str; try {  str = reader.readLine(); tokenizer = null;  } catch (IOException e) { throw new RuntimeException(e);  } return str; }
    }
}