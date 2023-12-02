import java.io.FileInputStream;
import java.util.Scanner;

public class Main2{

	public static int readGame(Scanner sc){
		int result = 0;
		boolean posible = true;
		int minRed = 0;
		int minBlue = 0;
		int minGreen = 0;
		String linea = sc.nextLine();
		String[] div1 = linea.split(": ");
		String[] div2 = div1[0].split(" ");
		String[] div3 = div1[1].split("; ");

		for(int i = 0; i<div3.length && posible; i++){

			String[] div4 = div3[i].split(", ");

			for(int j = 0; j<div4.length && posible; j++){
				String[] div5 = div4[j].split(" ");

				if(div5[1].contains("red")){
					if(minRed < Integer.parseInt(div5[0])){
						minRed = Integer.parseInt(div5[0]);
					}
				}
				if(div5[1].contains("green")){
					if(minGreen < Integer.parseInt(div5[0])){
						minGreen = Integer.parseInt(div5[0]);
					}
				}
				if(div5[1].contains("blue")){
					if(minBlue < Integer.parseInt(div5[0])){
						minBlue = Integer.parseInt(div5[0]);
					}
				}
			}
		}

	
		result = minBlue*minRed*minGreen;

		return result;
	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			int result = 0;
			while(sc.hasNextLine()){
				result += readGame(sc);
			}
			System.out.println(result);
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
}