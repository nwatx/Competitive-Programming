import java.io.*;
import java.util.*;
public class circularbarn {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("cbarn.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cbarn.out")));

		int n = Integer.parseInt(br.readLine());

		int[] R = new int[n];

		for(int i = 0; i < n; i++) {
			R[i] = Integer.parseInt(br.readLine());
		}

		int ans = Integer.MAX_VALUE;

		for(int i = 0; i < n; i++) {
			// [0, 1, 2, 3]
			// -> 0
			// [1, 2, 3, 0];

			int copyOf = R[0];
			for(int j = 0; j < n - 1; j++) {
				R[j] = R[j + 1];
			}
			R[n - 1] = copyOf;

			int sum = 0;
			for(int j = 0; j < n; j++) {
				sum += j * R[j];
			}

			ans = Math.min(ans, sum);
			
		}

		pw.println(ans);
		
		pw.close();
	}
}