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

int isSimbol(char c){
	return !(c == '.' || ('0' <= c && c <= '9'));
}

int isPartNumber(int i, int j, int length){
	int k;
	//Upper left diagonal
	if(i != 0 && j != 0 && isSimbol(line[i-1][j-1])){
		return 1;
	}
	//Upper right diagonal
	if(i != 0 && (j + length - 1) != 139 && isSimbol(line[i-1][j + length])){
		return 1;
	}
	//Lower left diagonal
	if(i != 139 && j != 0 && isSimbol(line[i+1][j-1])){
		return 1;
	}
	//Lower rigth diagonal
	if(i != 139 && (j + length - 1) != 139 && isSimbol(line[i+1][j + length])){
		return 1;
	}
	//Left
	if(j != 0 && isSimbol(line[i][j-1])){
		return 1;
	}
	//Right
	if((j + length - 1) != 139 && isSimbol(line[i][(j + length)])){
		return 1;
	}
	//Up
	if(i != 0){
		for(k=0;k<length;k++){
			if(isSimbol(line[i-1][j+k])){
				return 1;
			}
		}
	}
	//Down
	if(i != 139){
		for(k=0;k<length;k++){
			if(isSimbol(line[i+1][j+k])){
				return 1;
			}
		}
	}
	return 0;
}

int main(){

	int n, tamano, i, j, longitud;
	char buff;
	long int result = 0;
	FILE* file = fopen("Entrada.txt","r");

	setbuf(stdout, NULL);			/* Unbuffered */
	setbuf(stdin, NULL);			/* Unbuffered */

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
			if('0' <= line[i][j] && line[i][j] <= '9'){
				longitud = seeNumberLength(i, j);
				if(isPartNumber(i,j,longitud)){
					result += getNumber(i,j,longitud);
				}
				j = j + longitud - 1;
			}
		}
	}

	printf("%ld\n", result);

	fclose(file);
	return 0;
}