#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char line[140][140];

int power(int base, int exponente) {
    int resultado = 1;

    if (exponente == 0) {
        return 1;
    } else if (exponente < 0) {
        base = 1 / base;
        exponente = -exponente;
    }

    for (int i = 0; i < exponente; ++i) {
        resultado *= base;
    }

    return resultado;
}

int getNumberBeggining(int i, int j){
	while('0' <= line[i][j] && line[i][j] <= '9' && j >= 0){
		j--;
	}
	j++;
	return j;
}


int seeNumberLength(int i, int j){
	int result = 0;
	while('0' <= line[i][j] && line[i][j] <= '9' && j < 140){
		result++;
		j++;
	}
	return result;
}

int getNumber(int i, int j, int length){
	int result = 0;
	int k = 0;
	while(k < length){
		result = result + (line[i][j+k] - '0') * power(10,length-k-1);
		k++;
	}
	return result;
}

int isGear(int i,int j, int *suround){
	int adjacentNums =0;
	suround[0] = (i != 0 && j != 0 && 			'0' <= line[i-1][j-1] && 	line[i-1][j-1] <= '9');
	suround[1] = (i != 0 && 					'0' <= line[i-1][j] && 		line[i-1][j] <= '9');
	suround[2] = (i != 0 && (j + 1) != 139 && 	'0' <= line[i-1][j+1] && 	line[i-1][j+1] <= '9');
	suround[3] = (j != 0 && 					'0' <= line[i][j-1] && 		line[i][j-1] <= '9');
	suround[4] = (j != 139 && 					'0' <= line[i][j+1] && 		line[i][j+1] <= '9');
	suround[5] = (i != 139 && j != 0 && 		'0' <= line[i+1][j-1] && 	line[i+1][j-1] <= '9');
	suround[6] = (i != 139 && 					'0' <= line[i+1][j] && 		line[i+1][j] <= '9');
	suround[7] = (i != 139 && (j + 1) != 139 && '0' <= line[i+1][j+1] && 	line[i+1][j+1] <= '9');

	if(suround[0] && suround[1] && suround[2]){
		suround[1] = 0;
		suround[2] = 0;
		adjacentNums++;
	}
	else if(suround[0] && suround[1]){
		suround[1] = 0;
		adjacentNums++;
	}
	else if(suround[1] && suround[2]){
		suround[2] = 0;
		adjacentNums++;
	}
	else if(suround[0] && suround[2]){
		adjacentNums += 2;
	}
	else if(suround[0]){
		adjacentNums++;
	}
	else if(suround[1]){
		adjacentNums++;
	}
	else if(suround[2]){
		adjacentNums++;
	}

	if(suround[3]){
		adjacentNums++;
	}

	if(suround[4]){
		adjacentNums++;
	}

	if(suround[5] && suround[6] && suround[7]){
		suround[6] = 0;
		suround[7] = 0;
		adjacentNums++;
	}
	else if(suround[5] && suround[6]){
		suround[6] = 0;
		adjacentNums++;
	}
	else if(suround[6] && suround[7]){
		suround[6] = 0;
		adjacentNums++;
	}
	else if(suround[5] && suround[7]){
		adjacentNums += 2;
	}
	else if(suround[5]){
		adjacentNums++;
	}
	else if(suround[6]){
		adjacentNums++;
	}
	else if(suround[7]){
		adjacentNums++;
	}

	return adjacentNums == 2;
}

long int getGearRatio(int i, int j, int *suround){
	int k, numBeginning, length, result;
	int num1 = -1;
	int num2 = -1;
	if(suround[0]){
		numBeginning = getNumberBeggining(i-1,j-1);
		length = seeNumberLength(i-1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i-1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i-1, numBeginning, length);
		}
	}
	if(suround[1]){
		numBeginning = getNumberBeggining(i-1,j);
		length = seeNumberLength(i-1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i-1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i-1, numBeginning, length);
		}
	}
	if(suround[2]){
		numBeginning = getNumberBeggining(i-1,j+1);
		length = seeNumberLength(i-1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i-1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i-1, numBeginning, length);
		}
	}
	if(suround[3]){
		numBeginning = getNumberBeggining(i,j-1);
		length = seeNumberLength(i,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i, numBeginning, length);	
		}
		else{
			num2 = getNumber(i, numBeginning, length);
		}
	}
	if(suround[4]){
		numBeginning = getNumberBeggining(i,j+1);
		length = seeNumberLength(i,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i, numBeginning, length);	
		}
		else{
			num2 = getNumber(i, numBeginning, length);
		}
	}
	if(suround[5]){
		numBeginning = getNumberBeggining(i+1,j-1);
		length = seeNumberLength(i+1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i+1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i+1, numBeginning, length);
		}
	}
	if(suround[6]){
		
		numBeginning = getNumberBeggining(i+1,j);
		length = seeNumberLength(i+1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i+1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i+1, numBeginning, length);
		}
	}
	if(suround[7]){
		
		numBeginning = getNumberBeggining(i+1,j+1);
		length = seeNumberLength(i+1,numBeginning);
		if(num1 == -1){
			num1 = getNumber(i+1, numBeginning, length);	
		}
		else{
			num2 = getNumber(i+1, numBeginning, length);
		}
	}
	result = num1*num2;

	return result;
}

int main(){

	int n, tamano, i, j, longitud;
	int suround[8];
	char buff;
	long int result = 0;
	FILE* file = fopen("Entrada.txt","r");

	i=0;
	j=0;
	while(fscanf(file,"%c",&buff) != EOF){
		if(buff == '\n'){
			i++;
			j=0;
		}
		else{
			line[i][j] = buff;
			j++;
		}
	}

	for(i=0; i<140; i++){
		for(j=0; j<140;j++){
			if('*' == line[i][j] ){
				if(isGear(i, j, suround)){
					result += getGearRatio(i,j,suround);
				}
			}
		}
	}

	printf("%ld\n", result);

	fclose(file);
	return 0;
}