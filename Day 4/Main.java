import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main{

	public static int processLine(String line){
		int result = 0;
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
				if(result == 0){
					result = 1;
				}
				else{
					result *= 2;
				}
			}
		}

		System.out.println(result);
		lineScanner.close();
		return result;

	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			int result = 0;
			while(sc.hasNextLine()){
				result += processLine(sc.nextLine());
			}
			System.out.println(result);
			sc.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
}