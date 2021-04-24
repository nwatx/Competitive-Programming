package contest.hackerrank.tcea;
import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Crossword_Crisis {
	private static final In in = new In();
	private static int N;
	public static void main(String[] args) throws IOException {
		int r = in.ni(), c = in.ni(), q = in.ni();

		char[][] mat = new char[r][c];
		for(int i = 0; i < r; i++) {
			String line = in.nl();
			for(int j = 0; j < line.length(); j++) {
				mat[i][j] = line.charAt(j);
			}
		}

		List<Pair<Integer, Integer>> loc = new ArrayList<>();

		// int[] dx = new int[]{1,-1,0,0}, dy = new int[]{0,0,1,-1};

		// out.println(Arrays.deepToString(mat));

		int[][] vis = new int[r][c]; // 0 - nv 1 - r 2 - c 3 - b

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(mat[i][j] == '*') continue;
				if(vis[i][j] != 3) {
					int t = j;

					boolean validRun = false;

					int cnt = 0;

					while(t <= c-1 && mat[i][t] != '*') { // horz 
						if(vis[i][t] == 0) vis[i][t] = 1;
						else if(vis[i][t] == 2) vis[i][t] = 3;
						t++;
						cnt++;
					}

					if(cnt >= 2) validRun = true;
					cnt = 1;
					t = i;
					while(t <= r-1 && mat[t][j] != '*') { // vertical
						if(vis[t][j] == 0) vis[t][j] = 2;
						else if(vis[t][j] == 1) vis[t][j] = 3;
						cnt++;
						t++;
					}

					if(cnt >= 2 || validRun) loc.add(new Pair<>(i, j));

					// int cnt = 0;
					// if(mat[i][j] == '*') continue;
					// for(int k = 0; k < 4; k++) {
					// 	int nx = i + dx[k], ny = j + dy[k];
					// 	if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					// 	if(mat[nx][ny] != '*') cnt++;
					// }

					// if(cnt < 4) loc.add(new Pair<>(i, j));
				}
			}
		}
		
		// for(int i = 0; i < r; i++) {
		// 	for(int j = 0; j < c; j++) {
		// 		int cnt = 0;
		// 		if(mat[i][j] == '*') continue;
		// 		for(int k = 0; k < 4; k++) {
		// 			int nx = i + dx[k], ny = j + dy[k];
		// 			if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		// 			if(mat[nx][ny] != '*') cnt++;
		// 		}

		// 		if(cnt < 4) loc.add(new Pair<>(i, j));
		// 	}
		// }

		int[][] dbg = new int[r][c];
		for(int i = 0; i < loc.size(); i++) dbg[loc.get(i).l][loc.get(i).r] = i + 1;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) out.print(dbg[i][j] + " ");
			out.println();
		}


		for(int i = 0; i < q; i++) {
			String[] line = in.nl().split("\\s+");
			int id = Integer.parseInt(line[0]) - 1;
			String qType = line[1];
			String ret = "";
			Pair<Integer, Integer> lc = loc.get(id);
			if(qType.equals("Across")) {
				for(int j = lc.r; j < c; j++) {
					if(mat[lc.l][j] == '*') break;
					ret += mat[lc.l][j] + "";
					// out.println(lc.l + " " + j);
					// out.println(mat[lc.l][j]);
				}
			} else {
				for(int j = lc.l; j < r; j++) {
					if(mat[j][lc.r] == '*') break;
					ret += mat[j][lc.r] + "";
					// out.println(j + " " + lc.r);
				}
			}
			out.println(ret);
		}
	}

	private static class Pair<T, V> { T l; V r; Pair() {} Pair(T l, V r) { this.l = l; this.r = r; } }
	private static class In {
		private BufferedReader r; private StringTokenizer tk;
		public In() {r=new BufferedReader(new InputStreamReader(System.in),32768);}
		public String n(){ while (tk == null||!tk.hasMoreTokens()) {try{tk=new StringTokenizer(r.readLine()); }catch(IOException e){ throw new RuntimeException(e);}} return tk.nextToken();}
		public int ni(){return Integer.parseInt(n());}
		public double nd() {return Double.parseDouble(n());}
		public long nL(){return Long.parseLong(n());}
		public String nl(){String str;try{str=r.readLine();tk=null;}catch(IOException e){throw new RuntimeException(e);}return str;}
	}
}