package contest.hackerrank.tcea;
import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Curve_Calculation {
	private static final In in = new In();
	private static int N;

	static void solve() {
		String[] line = in.nl().split("\\s+");
		int idx = in.ni();
		int[] arr = new int[line.length];
		for(int i = 0; i < line.length; i++) {
			arr[i] = Integer.parseInt(line[i]);
		}

		int og = arr[idx-1];

		Arrays.sort(arr);

		for(int i = 10; i >= 1; i--) {
			if(arr[i-1] == og) {
				if(i > 9) out.println("A");
				else if(i > 7) out.println("B");
				else if(i > 3) out.println("C");
				else if(i > 1) out.println("D");
				else {
					out.println("F");
				}
				break;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		N = in.ni();

		while(N-- > 0) solve();
	}

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