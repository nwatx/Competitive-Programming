import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Solution {
	private static final In in = new In();
	private static int N;
	public static void main(String[] args) throws IOException {
		N = in.ni();
		while(N-- > 0) {
			String s = in.nl();
			int x = 0, y = 0;
			int[] xPoints = new int[s.length()], yPoints = new int[s.length()];

			// computes all the points traveled
			for(int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if(c == 'N') y++;
				else if(c == 'S') y--;
				else if(c == 'E') x++;
				else x--;

				xPoints[i] = x;
				yPoints[i] = y;
			}

			int result = 0;
			// shoelace formula
			for(int i = 0; i < s.length() - 1; i++) {
				result += xPoints[i] * yPoints[i + 1] - xPoints[i + 1] * yPoints[i];
			}

			// check the sign of the area
			if(result < 0) out.println("CW");
			else out.println("CCW");
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