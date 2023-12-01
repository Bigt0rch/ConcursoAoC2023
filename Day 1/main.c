#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void emptyLine(char * arr){
	int i;
	for(i=0;i<1024;i++){
		arr[i] = '\0';
	}
}

int busqueda(char* str1, char* str2, int tamano){
	int i;
	for(i=0;i<tamano;i++){
		if(str1[i]!=str2[i]){
			return 0;
		}

	}
	return 1;
}

int buscarNumero(char *str, int *desp){
	if(busqueda(str,"zero",4)){
		*desp=4;
		return 0;
	}
	if(busqueda(str,"one",3)){
		*desp=3;
		return 1;
	}
	if(busqueda(str,"two",3)){
		*desp=3;
		return 2;
	}
	if(busqueda(str,"three",5)){
		*desp=5;
		return 3;
	}
	if(busqueda(str,"four",4)){
		*desp=4;
		return 4;
	}
	if(busqueda(str,"five",4)){
		*desp=4;
		return 5;
	}
	if(busqueda(str,"six",3)){
		*desp=3;
		return 6;
	}
	if(busqueda(str,"seven",5)){
		*desp=5;
		return 7;
	}
	if(busqueda(str,"eight",5)){
		*desp=5;
		return 8;
	}
	if(busqueda(str,"nine",4)){
		*desp=4;
		return 9;
	}
	return -1;
}

int main(){

	int n1, n2, n, i, searched, desp, tamano;
	char *line;
	long int result = 0;
	FILE* file = fopen("Entrada.txt","r");


	while((tamano = getline(&line, &n, file)) != -1){

		n1 = -1;

		for(i = 0; i < tamano ; i++){


			if(line[i]<='9' && line[i]>='0'){
				if(n1==-1){
					n1 = line[i] - '0';
					n2 = n1;
				}
				else{
					n2 = line[i] - '0';
				}
			}
			else if((searched = buscarNumero(&line[i], &desp)) != -1){
				if(n1==-1){
					n1 = searched;
					n2 = n1;
				}
				else{
					n2 = searched;
				}
			}
			
		}
		result = result + n1*10 + n2;
		emptyLine(line);
	}
	printf("%ld\n", result);

	fclose(file);
	return 0;
}