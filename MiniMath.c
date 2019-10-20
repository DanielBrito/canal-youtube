#include<stdio.h>
#include<string.h> // Biblioteca que cont�m fun��es para manipula��o de strings, como strpcy()
#include<stdlib.h> // Biblioteca que cont�m as fun��o rand() e srand(), utilizadas para criar n�meros (pseudo)aleat�rios
#include<time.h> // Biblioteca que cont�m fun��es para manipula��o de datas e hor�rios, como time()

// Saiba mais sobre as fun��es rand(), srand() e time(): 
// https://www.dcc.fc.up.pt/~nam/aulas/0001/pi/slides/slipi0009/node17.html

int main(){
	
	char nome[20], nomeTop[20] = "------";
	int opcao, operacao, qtdOperacoes;
	int pontos, resposta, gabarito, pontMaxima=0;
	int num1, num2, i;
	
	// Definindo o n�vel de cada uma das opera��es para utilizar na gera��o dos valores aleat�rios:
	
	int maxSomaSubt = 50; // Por exemplo, intervalo m�ximo dos n�meros para SOMA e SUBTRA��O: 1..50
	int maxMult = 10; // Por exemplo, intervalo m�ximo dos n�meros para MULTIPLICA��O: 1..10
	int maxDiv = 100; // Por exemplo, intervalo m�ximo dos n�meros para DIVIS�O: 1..100
	
	srand(time(NULL));
	
	do{
		
		pontos=0; // Ao iniciar uma nova partida, sempre zerar o contador de pontos
		
		//system("clear"); // Limpar tela no Linux
		system("cls"); // Limpar tela no Windows
		
		printf("\t# M47H M1N1 G4M3 #\n\n");
		
		// Menu principal:
		
		do{ // La�o para controlar poss�veis entradas de op��es inv�lidas
			
			printf("    MENU\n");
			printf("1 - Nova partida\n");
			printf("2 - Pontuacao maxima\n");
			printf("0 - Sair\n\n");
			
			printf("Opcao: ");
			scanf("%d", &opcao);
			
			if(opcao!=0 && opcao!=1 && opcao!=2){
				
				printf("\nOpcao invalida!\n\n");
			}
			
		}while(opcao!=0 && opcao!=1 && opcao!=2);
		
		if(opcao==0){ // Se a op��o digitada for 0, termina-se o programa
			
			return 0; // Informa ao compilador que tudo ocorreu bem na fun��o main()
		}
		
		printf("\n");
		
		//system("clear"); // Limpar tela no Linux
		system("cls"); // Limpar tela no Windows
		
		if(opcao==1){ // Nova partida
			
			printf("\t# M47H M1N1 G4M3 #\n\n");
			
			printf("Digite seu nome: ");
			scanf("%s", nome);
			
			printf("\n");
			
			do{ // La�o para controlar poss�veis entradas de opera��es inv�lidas
				
				// Menu para escolha do tipo de opera��o aritm�tica:
				
				printf("    OPERACAO\n");
				printf("1 - Soma (+)\n");
				printf("2 - Subtracao (-)\n");
				printf("3 - Multiplicacao (*)\n");
				printf("4 - Divisao (/)\n\n");
				
				printf("Opcao: ");
				scanf("%d", &operacao);
				
				if(operacao!=1 && operacao!=2 && operacao!= 3 && operacao!=4){
						
					printf("\nOperacao invalida!\n\n");
				}
				
			}while(operacao!=1 && operacao!=2 && operacao!= 3 && operacao!=4);
			
			// Recebe a quantidade de opera��es que o jogador deseja responder:
			
			do{ // La�o para controlar poss�veis entradas de operacoes inv�lidas
						
				printf("\nDigite a quantidade de operacoes: ");
				scanf("%d", &qtdOperacoes);
				
				if(qtdOperacoes<1){
						
					printf("\nQuantidade invalida!\n\n");
				}
				
			}while(qtdOperacoes<1);
			
			printf("\n");
			
			//system("clear"); // Limpar tela no Linux
			system("cls"); // Limpar tela no Windows
			
			printf("\t# M47H M1N1 G4M3 #\n\n");
			
			if(operacao==1){ // Soma
				
				for(i=0; i<qtdOperacoes; i++){
					
					// Gera n�meros aleta�rios entre 1 e maxSomaSubt:
					
					num1 = rand() % maxSomaSubt+1;
					num2 = rand() % maxSomaSubt+1;
					
					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);
					
					printf("%d + %d = ", num1, num2);
					scanf("%d", &resposta);
					
					gabarito = num1+num2; // Calcula a resposta correta
					
					if(resposta==gabarito){ // Compara resposta do gabarito com a resposta digitada pelo jogador
						
						++pontos;
						printf("Correto!\n");
					}
					else{
						
						printf("Errou: %d\n", gabarito);
					}
					
					printf("\n");
				}
			}
			
			if(operacao==2){ // Subtra��o
				
				for(i=0; i<qtdOperacoes; i++){
					
					// Gera n�meros aleta�rios entre 1 e maxSomaSubt:
					
					num1 = rand() % maxSomaSubt+1;
					num2 = rand() % maxSomaSubt+1;
					
					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);
					
					printf("%d - %d = ", num1, num2);
					scanf("%d", &resposta);
					
					gabarito = num1-num2; // Calcula a resposta correta
					
					if(resposta==gabarito){ // Compara resposta do gabarito com a resposta digitada pelo jogador
						
						++pontos;
						printf("Correto!\n");
					}
					else{
						
						printf("Errou: %d\n", gabarito);
					}
					
					printf("\n");
				}
			}
			
			if(operacao==3){ // 3 - Multiplica��o:
				
				for(i=0; i<qtdOperacoes; i++){
					
					// Gera n�meros aleat�rios entre 1 e maxMult:
					
					num1 = rand() % 10+1;
					num2 = rand() % 10+1;
					
					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);
					
					printf("%d * %d = ", num1, num2);
					scanf("%d", &resposta);
					
					gabarito = num1*num2; // Calcula a resposta correta
					
					if(resposta==gabarito){ // Compara resposta do gabarito com a resposta digitada pelo jogador
						
						++pontos;
						printf("Correto!\n");
					}
					else{
						
						printf("Errou: %d\n", gabarito);
					}
					
					printf("\n");
				}
			}
			
			if(operacao==4){ // 4 - Divis�o:
				
				for(i=0; i<qtdOperacoes; i++){
					
					do{ // La�o para controlar a gera��o de divis�es que deixam resto 0:
						
						// Gera n�meros aleat�rios entre 1 e maxDiv:
						
						num1 = rand() % 100+1;
						num2 = rand() % 100+1;
							
					}while(num1%num2!=0);
					
					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);
					
					printf("%d / %d = ", num1, num2);
					scanf("%d", &resposta);
					
					gabarito = num1/num2; // Calcula a resposta correta
					
					if(resposta==gabarito){ // Compara resposta do gabarito com a resposta digitada pelo jogador
						
						++pontos;
						printf("Correto!\n");
					}
					else{
						
						printf("Errou: %d\n", gabarito);
					}
					
					printf("\n");
				}
			}
			
			if(pontos>pontMaxima){
				
				pontMaxima = pontos; // Atualiza pontuacao maxima
				strcpy(nomeTop, nome); // Copia o conte�do de "nome" para "nomeTop"
			}	
			
			printf("PONTUACAO: %d de %d\n", pontos, qtdOperacoes);
			
			printf("\n");
			
			do{ // La�o para controlar poss�veis entradas de op��es inv�lidas
					
				printf("O que deseja fazer?\n");
				printf("1 - Menu\n");
				printf("0 - Sair\n\n");
				
				printf("Opcao: ");
				scanf("%d", &opcao);
				
				if(opcao!=0 && opcao!=1){
					
					printf("\nOpcao invalida!\n\n");
				}
				
			}while(opcao!=0 && opcao!=1);
		}
		else
		if(opcao==2){ // Verificar pontua��o m�xima
			
			//system("clear"); // Limpar tela no Linux
			system("cls"); // Limpar tela no Windows
		
			printf("\t# M47H M1N1 G4M3 #\n\n");
			
			printf("PONTUACAO MAXIMA:\n");
			printf("Jogador: %s\n", nomeTop);
			printf("Pontos: %d\n\n", pontMaxima);
			
			do{ // La�o para controlar poss�veis entradas de op��es inv�lidas
					
				printf("O que deseja fazer?\n");
				printf("1 - Menu\n");
				printf("0 - Sair\n\n");
				
				printf("Opcao: ");
				scanf("%d", &opcao);
				
				if(opcao!=0 && opcao!=1){
					
					printf("\nOpcao invalida!\n\n");
				}
				
			}while(opcao!=0 && opcao!=1);
		}
		
	}while(opcao!=0);
	
	return 0;	
}
