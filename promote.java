import java.io.*;
import java.util.*;
public class promote {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("promote.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("promote.out")));
		
		// read in counts for bronze
		StringTokenizer st = new StringTokenizer(br.readLine());
		int bronzeBefore = Integer.parseInt(st.nextToken());
		int bronzeAfter = Integer.parseInt(st.nextToken());
		
		// read in counts for silver
		st = new StringTokenizer(br.readLine());
		int silverBefore = Integer.parseInt(st.nextToken());
		int silverAfter = Integer.parseInt(st.nextToken());
		
		// read in counts for gold
		st = new StringTokenizer(br.readLine());
		int goldBefore = Integer.parseInt(st.nextToken());
		int goldAfter = Integer.parseInt(st.nextToken());
		
		// read in counts for platinum
		st = new StringTokenizer(br.readLine());
		int platinumBefore = Integer.parseInt(st.nextToken());
		int platinumAfter = Integer.parseInt(st.nextToken());
		
		// do the computations
		int goldToPlatinum = platinumAfter - platinumBefore;
		int silverToGold = goldAfter - goldBefore + platinumAfter - platinumBefore;
		int bronzeToSilver = silverAfter - silverBefore + goldAfter - goldBefore + platinumAfter - platinumBefore;
		
		// print the answers
		pw.println(bronzeToSilver);
		pw.println(silverToGold);
		pw.println(goldToPlatinum);
		
		// close output stream
		pw.close();
	}
}