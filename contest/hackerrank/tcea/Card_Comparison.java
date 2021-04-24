package contest.hackerrank.tcea;
import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Card_Comparison {
	private static final In in = new In();
	private static int N;
	public static void main(String[] args) throws IOException {
		N = in.ni();

		Map<Character, Integer> mp = new TreeMap<>();
		mp.put('J', 11);
		mp.put('Q', 12);
		mp.put('K', 13);
		mp.put('A', 14);
		mp.put('T', 10);
		for(int i = 0; i < N; i++) {
			String[] line = in.nl().split("\\s+");
			char a = line[0].charAt(0), b = line[1].charAt(0);
			// out.println(b);

			int aa, bb;
			if(a > 58) aa = mp.get(a);
			else aa = a - '0';

			if(b > 58) bb = mp.get(b);
			else bb = b - '0';

			if(aa > bb) out.println("first");
			else if(bb > aa) out.println("second");
			else out.println("tie");
		}
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