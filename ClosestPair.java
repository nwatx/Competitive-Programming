import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Solution {
	private static class Pair<T, V> { T l; V r; Pair() {} Pair(T l, V r) { this.l = l; this.r = r; } }

	Pair<double,double> solve(List<Pair<double, double>> v) {
		Pair<double,Pair<Pair<double, double>,Pair<double, double>>> bes; bes.l = Integer.MAX_VALUE;
		Set<Pair<double, double>> S; int ind = 0;
		Collections.sort(v);
		for(int i = 0; i < v.size(); i++) {
			if (i && v[i] == v[i-1]) return new Pair(v[i],v[i]);
			for (; v[i].f-v[ind].f >= bes.f; ++ind) 
				S.remove(new Pair(v[ind].s,v[ind].f));
			for (var it = S.ub({v[i].s-bes.f,INF});
				it != end(S) && it->f < v[i].s+bes.f; ++it) {
				P t = {it->s,it->f};
				ckmin(bes,{abs(t-v[i]),{t,v[i]}});
			}
			S.insert({v[i].s,v[i].f});
		}
		return bes.s;
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