import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main2{
	public static long[] readData(Scanner sc){
		String time = "";
		String distance = "";
		long[] result = new long[2];
		while (!sc.hasNextInt()) {
        	sc.next();
        }
		while (sc.hasNextInt()){
			time = time + sc.nextInt();
		}
		while (!sc.hasNextInt()) {
        	sc.next();
        }
		while (sc.hasNextInt()){
			distance = distance + sc.nextInt();
		}
		result[0] = Long.parseLong(time);
		result[1] = Long.parseLong(distance);
		return result;
	}

	
	public static long distance(long t, long tp){
		return (t - tp) * tp;
	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			long[] data;
			long result = 0;

			data = readData(sc);

			for(int j = 0; j < data[0]; j++){
				if(distance(data[0], j) > data[1]){
					result++;
				}
			}

			System.out.println(result);
			sc.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
}