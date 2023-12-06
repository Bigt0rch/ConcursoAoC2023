import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main{
	public static void readData(Scanner sc, int[] times, int[] distances){
		int i = 0;
		
		while (!sc.hasNextInt()) {
        	sc.next();
        }
		while (sc.hasNextInt()){
			times[i] = sc.nextInt();
			i++;
		}
		i=0;
		while (!sc.hasNextInt()) {
        	sc.next();
        }
		while (sc.hasNextInt()){
			distances[i] = sc.nextInt();
			i++;
		}
	}

	
	public static int distance(int t, int tp){
		return (t - tp) * tp;
	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			int[] times = new int[4];
			int[] distances = new int[4];
			int i = 0;
			int buff;
			int result = 1;

			readData(sc, times, distances);

			while(i<4){
				buff = 0;
				for(int j = 0; j < times[i]; j++){
					if(distance(times[i], j) > distances[i]){
						buff++;
					}
				}
				result *= buff;
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