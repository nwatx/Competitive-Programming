package contest.hackerrank.tcea;
import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Task_Turmoil {
	private static final In in = new In();
	private static int N;
	public static void main(String[] args) throws IOException {
		int n = in.ni(), m = in.ni();
		ArrayList<String> al = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			String action = in.nl();
			al.add(action);
		}

		for(int i = 0; i < m; i++) {
			String[] line = in.nl().split("\\s+", 3);
			for(int j = 0; j < line.length; j++) line[j] = line[j].trim();
			int idx = Integer.parseInt(line[0]) - 1;
			switch(line[1]) {
				case "add": al.add(idx, line[2]); break;
				case "change": al.set(idx, line[2]); break;
				case "delete": al.remove(idx); break;
			}
		}

		for(String a : al) {
			out.println(a);
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