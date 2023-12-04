import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main2{

	public static int processLine(String line, int[] nOfCopies, int i){
		int result = 0;
		nOfCopies[i] += 1;
		Integer buff;
		ArrayList<Integer> winNumbers = new ArrayList<Integer>();
		Scanner lineScanner = new Scanner(line);
		Pattern pattern1 = Pattern.compile("\\b\\d{1,3}:");
		Pattern pattern2 = Pattern.compile("\\|");
		while (!lineScanner.hasNext(pattern1)) {
        	lineScanner.next();
        }
		lineScanner.next();
		while(!lineScanner.hasNext(pattern2)){
			winNumbers.add(lineScanner.nextInt());
		}
		lineScanner.next();
		while(lineScanner.hasNextInt()){
			buff = lineScanner.nextInt();
			if(winNumbers.contains(buff)){
				result++;
			}
		}
		for(int j = 1; j<=result;j++){
			nOfCopies[i+j] += nOfCopies[i];
		}
		lineScanner.close();
		return nOfCopies[i];

	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			int result = 0;
			int i = 0;
			int buff;
			int nOfCopies[] = new int[1024];
			while(sc.hasNextLine()){
				buff = processLine(sc.nextLine(), nOfCopies, i);
				result += buff;
				i++;
			}
			System.out.println(result);
			sc.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
}