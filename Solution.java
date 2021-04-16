import java.io.*;
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
        int[][] a = new int[6][6];

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) a[i][j] = in.nextInt();
        }

        // out.println(Arrays.deepToString(a));

        int[] dx = new int[]{-1, -1, 0, 0, 0, 1, 1}, dy = new int[]{1, -1, 1, -1, 0, 1, -1};

        int ret = Integer.MIN_VALUE;

        for(int i = 1; i < 5; i++) {
            for(int j = 1; j < 5; j++) {
                int sum = 0;
                for(int k = 0; k < 7; k++) {
                    // if(i == 4 && j == 4) {
                        // out.println(i+dy[k] + " | " + (j +dy[k]) + " | " + a[i+dx[k]][j+dy[k]]);
                    // }
                    sum += a[i+dy[k]][j+dx[k]];
                }
                // if(i == 4 && j == 4) out.println(sum);
                ret = Math.max(ret, sum);
            }
        }

        out.println(ret);
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