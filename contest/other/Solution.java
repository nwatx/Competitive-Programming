import java.io.*;
import java.util.*;

import static java.lang.System.out;

public class Solution {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("whereami.in"));
		PrintWriter out = new PrintWriter(new File("whereami.out"));
		int n = Integer.parseInt(in.nextLine());
		String s = in.nextLine();
		// loop through the sizes
		for(int i = 0; i < n; i++) {
			Set<String> ck = new TreeSet<>();
			for(int j = 0; j < n - i; j++) {
				ck.add(s.substring(j, j + i + 1));
			}
			if(ck.size() == n - i) {
				out.println(i + 1);
				break;
			}
		}
		out.close();
	}
}
