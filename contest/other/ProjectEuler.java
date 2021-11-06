import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class ProjectEuler {
	private static final In in = new In();
	private static int N;
	public static void main(String[] args) throws IOException {
		String[] S = new String[100];
		for(int i = 0; i < n; i++) {
			S[i] = in.nl();
		}


	}

	private static class In {
		private BufferedReader r;private StringTokenizer tk;
		public In(){r=new BufferedReader(new InputStreamReader(System.in),32768);}
		public String n(){while(tk == null||!tk.hasMoreTokens()) {try{tk=new StringTokenizer(r.readLine());}catch(IOException e){throw new RuntimeException(e);}}return tk.nextToken();}
		public int ni(){return Integer.parseInt(n());}
		public double nd(){return Double.parseDouble(n());}
		public long nL(){return Long.parseLong(n());}
		public String nl(){String str;try{str=r.readLine();tk=null;}catch(IOException e){throw new RuntimeException(e);}return str;}
	}
}
