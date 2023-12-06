import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Range implements Comparable<Range>{
	long sourceStart;
	long destinationStart;
	long length;

	public Range(long sourceStart, long destinationStart, long length){
		this.destinationStart = destinationStart;
		this.sourceStart = sourceStart;
		this.length = length;
	}

	public boolean withinRange(long number){
		return sourceStart <= number && number<(sourceStart+length);
	}

	public String toString(){
		return destinationStart + " " + sourceStart + " " + length;
	}

	@Override
	public int compareTo(Range o) {
		return Long.compare(this.sourceStart,o.sourceStart);
	}
}
public class Main{
	public static void readData(Scanner sc, ArrayList<Long> seeds ,ArrayList<Range>[] listas){
		int i = 0;
		long buffSourceStart;
		long buffDestinationStart;
		long buffLength;

		while (!sc.hasNextBigInteger()) {
        	sc.next();
        }
		while (sc.hasNextBigInteger()){
			seeds.add(sc.nextBigInteger().longValue());
		}
		while(sc.hasNext()){
			while (!sc.hasNextBigInteger()) {
				sc.next();
			}
			while (sc.hasNextBigInteger()){
				buffDestinationStart = sc.nextBigInteger().longValue();
				buffSourceStart = sc.nextBigInteger().longValue();
				buffLength = sc.nextBigInteger().longValue();
				listas[i].add(new Range(buffSourceStart, buffDestinationStart, buffLength));
			}
			Collections.sort(listas[i]);
			i++;
		}
	}

	public static void printData(ArrayList<Long> seeds ,ArrayList<Range>[] listas){
		for(int i = 0; i < seeds.size(); i++){
			System.out.print(seeds.get(i) + " ");
		}
		System.out.println();
		for(int i = 0; i < listas.length; i++){
			System.out.println("Lista " + i + ":");
			for(int j = 0; j < listas[i].size(); j++){
				System.out.println(listas[i].get(j));
			}
		}
	}

	public static long seedToLocation(long seed, ArrayList<Range>[] listas){
		long buffer = seed;
		for(int i = 0; i<listas.length && listas[i] != null; i++){
			int j=0;
			System.out.print(buffer + " -> ");
			while(j < listas[i].size() && !listas[i].get(j).withinRange(buffer)){
				j++;
			}
			if(j < listas[i].size()){
				buffer = (buffer - listas[i].get(j).sourceStart) + listas[i].get(j).destinationStart;
				System.out.println(buffer + " Within Range: "  + listas[i].get(j));
			}
			else
				System.out.println(buffer + " Within Range: NONE");
		}
		System.out.println("============================================================================");
		return buffer; 
	}


	public static void main(String args[]){
		try(Scanner sc = new Scanner(new FileInputStream("Entrada.txt"))){
			int i = 0;
			long buffer;
			long result = Long.MAX_VALUE;

			ArrayList<Range>[] listas = new ArrayList[7];
			ArrayList<Long> seeds = new ArrayList<Long>();
			ArrayList<Range> seedToSoil = new ArrayList<Range>();
			listas[0] = seedToSoil;
			ArrayList<Range> soilToFertilicer = new ArrayList<Range>();
			listas[1] = soilToFertilicer;
			ArrayList<Range> fertilicerToWater = new ArrayList<Range>();
			listas[2] = fertilicerToWater;
			ArrayList<Range> waterToLight = new ArrayList<Range>();
			listas[3] = waterToLight;
			ArrayList<Range> ligthToTemperature = new ArrayList<Range>();
			listas[4] = ligthToTemperature;
			ArrayList<Range> temperatureToHumidity = new ArrayList<Range>();
			listas[5] = temperatureToHumidity;
			ArrayList<Range> humidityToLocation = new ArrayList<Range>();
			listas[6] = humidityToLocation;


			readData(sc, seeds, listas);

			while(i<seeds.size()){
				buffer = seedToLocation(seeds.get(i), listas);
				//System.out.println(seeds.get(i) + " -> " + buffer);
				if(buffer < result){
					result = buffer;
				}
				i++;
			}
			//printData(seeds, listas);

			System.out.println(result);
			sc.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}
}