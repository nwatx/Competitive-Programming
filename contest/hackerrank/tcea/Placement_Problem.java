package contest.hackerrank.tcea;
import java.io.*;
import java.util.*;
import java.awt.*;

import static java.lang.System.out;

public class Placement_Problem {
  private static final In in = new In();
  private static int N;

  public static void main(String[] args) throws IOException {
    N = Integer.parseInt(in.nl());
    
    while(N-- > 0) {
      String[] line = in.nl().replace("(", " ").replace(")", " ").replace(",", " ").trim().split("\\s+");
    int[] v = new int[line.length];
    //   out.println(Arrays.toString(line));
    for(int i = 0; i < line.length; i++) v[i] = Integer.parseInt(line[i]);
      int tl = Math.min(v[0], v[2]), w1 = Math.abs(v[2]-v[0]), yl = Math.min(v[1], v[3]), l1 = Math.abs(v[1]-v[3]);
      int t2 = Math.min(v[4], v[6]), w2 = Math.abs(v[4]-v[6]), yl2 = Math.min(v[5], v[7]), l2 = Math.abs(v[7]-v[5]);

      Rectangle A = new Rectangle(tl, yl, w1, l1), B = new Rectangle(t2, yl2, w2, l2);
	//   out.println(A);
	//   out.println("B: " + B.toString());
      Rectangle isect = A.intersection(B);
      out.println(Math.max(0, Math.round(isect.getHeight() * isect.getWidth())));
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