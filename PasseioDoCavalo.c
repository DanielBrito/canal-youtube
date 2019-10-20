// DESAFIO AUTORAL:

// Dado um cavalo em alguma posi��o X do tabuleiro de xadrez, ap�s N movimentos quaisquer, 
// informar a cor da casa em que o cavalo estar� posicionado.

#include<stdio.h>

int main(){
	
	int linha, l, c, mov;
	char coluna;

    // Entrada dos dados da posi��o atual do cavalo, por exemplo: a6
	
	printf("Digite a posicao atual do cavalo: ");
	scanf("%c%d", &coluna, &linha);
	
	l = linha;
	
	printf("Digite a quantidade de movimentos: ");
	scanf("%d", &mov);

    // Transformando o valores literais das colunas em valores num�ricos para facilitar no descobrimento da cor da casa atual:
	
	switch(coluna){
		
		case 'a': c = 1; break;
		case 'b': c = 2; break;
		case 'c': c = 3; break;
		case 'd': c = 4; break;
		case 'e': c = 5; break;
		case 'f': c = 6; break;
		case 'g': c = 7; break;
		case 'h': c = 8; break;
	}

    // Verificando as propriedades do tabuleiro de xadrez, podemos observar que as casas pretas s� ocorrem em duas situa��es:
    // I - Quando a linha � par e a coluna � par
    // II - Quando a linha � �mpar e a coluna �mpar
	
	if((l%2==1 && c%2==1) || (l%2==0 && c%2==0)){ // Se I e II acontecerem, temos que o cavalo estar� numa casa preta
		
		if(mov%2==0){ // Se a quantidade de movimentos for par, permanecemos na mesma cor:
			
			printf("\nO cavalo estara numa casa preta.\n");
		}
		else{ // Caso contr�rio, se a quantidade de movimentos for �mpar, trocamos de cor:
			
			printf("\nO cavalo estara numa casa branca.\n");
		}	
	}
	else{ // Caso contr�rio, ele estar� posicionado numa casa da cor branca

        if(mov%2==0){ // Se a quantidade de movimentos for par, permanecemos na mesma cor:

            printf("\nO cavalo estara numa casa branca.\n");
        }
        else{ // Caso contr�rio, se a quantidade de movimentos for �mpar, trocamos de cor:

            printf("\nO cavalo estara numa casa preta.\n");
        }
	}
}
