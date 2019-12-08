#include"modulo.h"

char labirinto[DIMENSAO][DIMENSAO];

Elemento harry, voldemort, comensal, nagini, buraco, chavePortal;
bool magiaNegraVoldemort, magiaNegraNagini, magiaNegraComensal, calor, brisa, impacto, gameOverSucesso, gameOverFracasso;
int qtdFeiticos;

void iniciarJogo(){

    inicializarLabirinto();

    calor = brisa = impacto = gameOverSucesso = gameOverFracasso = false;
    magiaNegraComensal = magiaNegraNagini = magiaNegraVoldemort = false;

    qtdFeiticos = 3;

    posicionarElemento();

    verificarPosicao();

    menuPrincipal();
}

void telaInicial(){

	system("cls");

	printf("\n      LABIRINTO  TRIBRUXO\n\n");

	printf("         @@@@@@@@@@@@@\n");
	printf("      @@@@@@@@@@@@@@@@@@@\n");
	printf("    @@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("   @@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf(" @@@@@@@@@ \\    @@@@@@@  @@@@@\n");
	printf(" @@@@@@@@  _\\     @@@@@   @@@@\n");
	printf(" @@@  @@   \\        @@   @@@@\n");
	printf(" @@@        \\              @@\n");
	printf("  @@  .#####.      .#####. @\n");
	printf("   @ #       #    #       #\n");
	printf("    #         #__#         #\n");
	printf("    #         #  #         #\n");
	printf("     #       #    #       #\n");
	printf("      .#####.      .#####.\n\n\n");

	pausarTela();
}

void pausarTela(){

    printf(" Tecle ENTER para continuar...");

    char pausar;
    scanf("%c", &pausar);
}

void gameOver(){

	system("cls");

	if(gameOverFracasso==true){

		if(harry.linha==buraco.linha && harry.coluna==buraco.coluna){

			estacas();
		}

		if((harry.linha==voldemort.linha && harry.coluna==voldemort.coluna) ||
		   (harry.linha==nagini.linha && harry.coluna==nagini.coluna) ||
		   (harry.linha==comensal.linha && harry.coluna==comensal.coluna)){

			   morte();
		   }
	}
	else
	if(gameOverSucesso==true){

		hogwarts();
	}

	exit(0);
}

void morte(){

	printf("\n\t  # GAME OVER #\n\n");

	printf("                    ,____\n");
	printf("                    |---.\\\n");
	printf("                    |---. \\\n");
	printf("            ___     ||    `\n");
	printf("           / .-\\  ./=)\n");
	printf("          |  |\"|_/\\/||\n");
	printf("          ;  |-;|  /||\n");
	printf("         / \\_| |/ / ||\n");
	printf("        /      \\_/  ||\n");
	printf("        |   /  |    ||\n");
	printf("        /   \\ _/    ||\n");
	printf("       /--._/  \\    ||\n");
	printf("       `/|)    |    ||\n");
	printf("       .'      |    ||\n");
	printf("      /         \\   ||\n");
	printf("     (_.-.__.__./   ||\n\n");

	printf(" Voce foi capturado pelo inimigo!\n\n"); 

    getch();
}

void estacas(){

	printf("\n\t # GAME OVER #\n\n");

	printf("                      /\\\n");
	printf("                     /  \\\n");
	printf("                     |' |\n");
	printf("       /\\            |  |\n");
	printf("      / '\\           |' |\n");
	printf("      |  |       /\\  |  |\n");
	printf("  /\\  |' |      /  \\ |' |\n");
	printf(" /  \\ |  |      | '| |  |\n");
	printf(" |' | | '|      |  | | '|  /\\\n");
	printf(" |  | |  |      |  | | '| /' \\\n");
	printf(" | '| | '|      |' | | '| |  |\n");
	printf(" |' | | '|  /\\  |  | |  | | '|\n");
	printf(" |  | | '| /  \\ |  | | '| |  |\n");
	printf(" | '| |  | | '| | '| |  | | '|\n");
	printf(" |' | |' | |  | | '| |' | | '|\n");
	printf(" | '| |  | |' | |  | |  | | '|\n\n");

	printf("     Voce caiu no buraco!\n\n");

    getch();
}

void hogwarts(){

	printf("\n\t\t # GAME OVER #\n\n");

	printf("\t                 TT~~\n");
	printf("\t                 ||\n");
	printf("\t                /''\\\n");
	printf("\t        T~~     | '|\n");
	printf("\t   T~~  |    T~ |  |   \n");
	printf("\t   |   /\"\\   |  |  |/\\\n");
	printf("\t   |   /\"\\   |  |  |/\\\n");
	printf("\t  /\"\\  ###  /\"\\ |' |##|~\n");
	printf("\t  #####/\\  /   \\|'/\\|/\"\\\n");
	printf("\t  |   /__\\/]###[\\/__\\####\n");
	printf("\t  |\"  ####'|I_I|'####   |\n");
	printf("\t  |   |' |/  -  \\|' |'  |\n");
	printf("\t  |'  |  |@@=H=@@|' |   |\n");
	printf("\t  |   |' | |[_]| |  |'  |\n");
	printf("\t  |   |  |_|###|_|  |   |\n");
	printf("\t  '---'--'-/___\\-'--'---'\n\n");

	printf(" Parabens! Voce encontrou o chave do portal!\n\n");	

    getch();
}

void menuPrincipal(){

    int opcao;

    do{

        system("cls");

        printf("\n    # MENU PRINCIPAL #\n\n");

        raio();

        printf(" 1 - Nova partida\n");
        printf(" 2 - Historia\n");
        printf(" 3 - Regras\n");
        printf(" 0 - Sair\n\n");

        printf(" - > ");
        scanf("%d", &opcao);

    }while(opcao<0 || opcao>3);

    if(opcao==1){

        system("cls");

        novaPartida();
    }
    else
    if(opcao==2){

        historia();

        subMenu();
    }
    else
    if(opcao==3){

        regras();

        subMenu();
    }
    else{

        system("cls");

        exit(0);
    }
}

void raio(){

	printf("           //////\n");
	printf("          //////\n");
	printf("         //////\n");
	printf("        //////\n");
	printf("       /////////\n");
	printf("      /////////\n");
	printf("          ////\n");
	printf("         ///\n");
	printf("        //\n");
	printf("       //\n");
	printf("      /\n\n");
}

void subMenu(){

    int opcao;
    bool opInvalida = false;

    printf("\n\n O que deseja fazer?\n\n");

    printf(" 1 - Menu principal\n");
    printf(" 0 - Sair\n\n");

    do{

        printf(" - > ");
        scanf("%d", &opcao);

        if(opcao<0 || opcao>1){

            printf("\n Opcao invalida!\n\n");

            opInvalida = true;
        }
        else{

            opInvalida = false;
        }

    }while(opInvalida==true);

    if(opcao==1){

        menuPrincipal();
    }
    else{

        system("cls");

        exit(0);
    }
}

void novaPartida(){

	system("cls");

	char movimento;

	do{

		system("cls");

		imprimirLabirinto();

		mostrarLegenda();

		printf("\n\n Digite o movimento: ");
		movimento = getch();

		movimentar(movimento);

	}while(movimento!='x' && gameOverSucesso==false && gameOverFracasso==false);

	if(gameOverSucesso==true || gameOverFracasso==true){

		gameOver();
	}
	else{

		system("cls");

		exit(0);
	}
}

void historia(){

	system("cls");

	printf("\n\t\t\t    # HISTORIA #\n\n");

	printf(" Durante o Torneio Tribruxo, de alguma forma, Harry Potter foi\n");
	printf(" transportado para um labirinto encantado por magia negra, onde ele\n");
	printf(" nao e capaz de enxergar seus inimigos, no entanto, o contrario nao\n");
	printf(" acontece. Felizmente, Harry carregava consigo sua capa de\n");
	printf(" invisibilidade, fazendo com que seus inimigos tambem nao consigam\n");
	printf(" enxerga-lo.\n\n");
	printf(" Nesta situacao, Harry tem que evitar contato com os inimigos\n");
	printf(" presentes no cenario, que sao Lord Voldemort com sua cobra Nagini, e\n");
	printf(" um comensal da morte. Alem disso, existe um buraco cujo fundo e\n");
	printf(" repleto de estacas mortais.\n\n");
	printf(" Todos os inimigos de Harry emanam magia negra ao seu redor, assim,\n");
	printf(" Harry consegue ter nocao do perigo em que se encontra. Ao se\n");
	printf(" aproximar do buraco, ele tambem consegue sentir uma brisa, lhe\n");
	printf(" indicando para tomar cuidado onde pisa.\n\n");
	printf(" Por uma questao desconhecida, Harry tambem percebeu que pode lancar\n");
	printf(" apenas tres feiticos. Portanto, caso ele esteja sob perigo, pode\n");
	printf(" tentar derrotar o seu inimigo atirando em alguma direcao, torcendo\n");
	printf(" para atingi-lo.\n\n");
	printf(" A unica maneira de Harry escapar deste labirinto e encontrando a chave\n");
	printf(" do portal que o levara de volta para Hogwarts. Assim, ao se\n");
	printf(" aproximar desta chave, Harry consegue sentir uma especie de calor,\n");
	printf(" indicando que ela esta bem proxima.\n\n");
	printf(" Desta forma, e seu trabalho guiar Harry por este local ate que ele\n");
	printf(" encontre a chave do portal que o leve de volta para seus amigos.\n");
}

void regras(){

	system("cls");

	printf("\n\t\t# INSTRUCOES #\n\n");

	printf(" Teclas de movimentacao:\n\n");
	printf("\t     [w]\n\t [a] [s] [d]\n\n");

	printf(" [w] = andar/atirar para cima\n");
	printf(" [a] = andar/atirar para esquerda\n");
	printf(" [s] = andar/atirar para baixo\n");
	printf(" [d] = andar/atirar para direita\n\n\n");

	printf(" Ao sentir a presenca de um inimigo:\n\n");

	printf(" [c] = continuar busca (ignorar inimigo)\n");
	printf(" [f] = atirar feitico (escolhendo a direcao)\n\n\n");

	printf(" [x] = sair durante o jogo\n");
}

void inicializarLabirinto(){

	int i, j;

	for(i=0; i<DIMENSAO; i++){

		for(j=0; j<DIMENSAO; j++){

			if(i==0 || j==0 || i==DIMENSAO-1 || j==DIMENSAO-1){

				labirinto[i][j] = '#';
			}
			else{

				labirinto[i][j] = ' ';
			}
		}
	}
}

void imprimirLabirinto(){

	int i, j;

	printf("\n");

	for(i=0; i<DIMENSAO; i++){

		printf("\t");

		for(j=0; j<DIMENSAO; j++){

			printf("%c ", labirinto[i][j]);
		}

		printf("\n");
	}
}

int gerarCoordenada(){

    int num;

	do{

		num = rand()%DIMENSAO;

	}while(num<1 || num>DIMENSAO-2);

	return num;
}

void posicionarElemento(){

	int posLinha, posColuna;

	srand(time(NULL));

	harry.linha = gerarCoordenada();
	harry.coluna = gerarCoordenada();

	//labirinto[harry.linha][harry.coluna] = 'H';

	do{

		posLinha = gerarCoordenada();
		posColuna = gerarCoordenada();

	}while(posLinha==harry.linha && posColuna==harry.coluna);

	chavePortal.linha = posLinha;
	chavePortal.coluna = posColuna;

	//labirinto[chavePortal.linha][chavePortal.coluna] = 'P';

	do{

		posLinha = gerarCoordenada();
		posColuna = gerarCoordenada();

	}while((posLinha==harry.linha && posColuna==harry.coluna)||
	       (posLinha==chavePortal.linha && posColuna==chavePortal.coluna));

	voldemort.linha = posLinha;
	voldemort.coluna = posColuna;

	//labirinto[voldemort.linha][voldemort.coluna] = 'V';

	do{

		posLinha = gerarCoordenada();
		posColuna = gerarCoordenada();

	}while((posLinha==harry.linha && posColuna==harry.coluna) ||
	       (posLinha==chavePortal.linha && posColuna==chavePortal.coluna) ||
		   (posLinha==voldemort.linha && posColuna==voldemort.coluna));

	nagini.linha = posLinha;
	nagini.coluna = posColuna;

	//labirinto[nagini.linha][nagini.coluna] = 'N';

	do{

		posLinha = gerarCoordenada();
		posColuna = gerarCoordenada();

	}while((posLinha==harry.linha && posColuna==harry.coluna) ||
	       (posLinha==chavePortal.linha && posColuna==chavePortal.coluna) ||
		   (posLinha==voldemort.linha && posColuna==voldemort.coluna) ||
		   (posLinha==nagini.linha && posColuna==nagini.coluna));

	comensal.linha = posLinha;
	comensal.coluna = posColuna;

	//labirinto[comensal.linha][comensal.coluna] = 'C';

	do{

		posLinha = gerarCoordenada();
		posColuna = gerarCoordenada();

	}while((posLinha==harry.linha && posColuna==harry.coluna) ||
	       (posLinha==chavePortal.linha && posColuna==chavePortal.coluna) ||
		   (posLinha==voldemort.linha && posColuna==voldemort.coluna) ||
		   (posLinha==nagini.linha && posColuna==nagini.coluna) ||
		   (posLinha==comensal.linha && posColuna==comensal.coluna));

	buraco.linha = posLinha;
	buraco.coluna = posColuna;

	//labirinto[buraco.linha][buraco.coluna] = 'B';
}

void mostrarLegenda(){

	printf("\n\tSensacao: ");

	if(magiaNegraVoldemort==false && magiaNegraNagini==false && magiaNegraComensal==false && brisa==false && calor==false && impacto==false){

		printf("...");
	}

	if(magiaNegraVoldemort==true || magiaNegraNagini==true || magiaNegraComensal==true){

		printf("Magia negra! ");
	}

	if(brisa==true){

		printf("Brisa! ");
	}

	if(calor==true){

		printf("Calor! ");
	}

	if(impacto==true){

		printf("Impacto!");
	}

	printf("\n");
}

void movimentar(char movimento){

	if(movimento==SUBIR){

		if(harry.linha!=1){

			//labirinto[harry.linha][harry.coluna] = ' ';
			//labirinto[--harry.linha][harry.coluna] = 'H';
			--harry.linha;

			impacto = false;
		}
		else{

			impacto = true;
		}
	}

	if(movimento==DESCER){

		if(harry.linha!=DIMENSAO-2){

			//labirinto[harry.linha][harry.coluna] = ' ';
			//labirinto[++harry.linha][harry.coluna] = 'H';

			++harry.linha;

			impacto = false;
		}
		else{

			impacto = true;
		}
	}

	if(movimento==ESQUERDA){

		if(harry.coluna!=1){

			//labirinto[harry.linha][harry.coluna] = ' ';
			//labirinto[harry.linha][--harry.coluna] = 'H';

			--harry.coluna;

			impacto = false;
		}
		else{

			impacto = true;
		}
	}

	if(movimento==DIREITA){

		if(harry.coluna!=DIMENSAO-2){

			//labirinto[harry.linha][harry.coluna] = ' ';
			//labirinto[harry.linha][++harry.coluna] = 'H';

			++harry.coluna;

			impacto = false;
		}
		else{

			impacto = true;
		}
	}

	verificarPosicao();

	if((harry.linha==voldemort.linha && harry.coluna==voldemort.coluna) ||
	   (harry.linha==comensal.linha && harry.coluna==comensal.coluna) ||
	   (harry.linha==nagini.linha && harry.coluna==nagini.coluna) ||
	   (harry.linha==buraco.linha && harry.coluna==buraco.coluna)){

		   gameOverFracasso = true;
	}

	if(harry.linha==chavePortal.linha && harry.coluna==chavePortal.coluna){

		gameOverSucesso = true;
	}

	if(gameOverSucesso==true || gameOverFracasso==true){

		gameOver();
	}
}

void atirar(){

	char acao, direcao;

	do{

		system("cls");

		imprimirLabirinto();

		mostrarLegenda();

		printf("\n\n Digite a acao: ");
		acao = getch();

		if(acao=='f'){

			if(qtdFeiticos==0){

				printf("\n Voce nao pode mais atirar feiticos!\n\n");

				getch();
			}
			else{

				printf("\n Direcao para atirar o feitico: ");
				direcao = getch();

				if(direcao==SUBIR){

					if(harry.linha>voldemort.linha && harry.coluna==voldemort.coluna && magiaNegraVoldemort==true){

						labirinto[voldemort.linha][voldemort.coluna] = ' ';

						voldemort.linha = -1;
						voldemort.coluna = -1;

						printf("\n Voce atingiu o Lord Voldemort!\n\n");

						magiaNegraVoldemort = false;

						getch();
					}
					else
					if(harry.linha>comensal.linha && harry.coluna==comensal.coluna && magiaNegraComensal==true){

						labirinto[comensal.linha][comensal.coluna] = ' ';

						comensal.linha = -1;
						comensal.coluna = -1;

						printf("\n Voce atingiu o comensal!\n\n");

						magiaNegraComensal = false;

						getch();
					}
					else
					if(harry.linha>nagini.linha && harry.coluna==nagini.coluna && magiaNegraNagini==true){

						labirinto[nagini.linha][nagini.coluna] = ' ';

						nagini.linha = -1;
						nagini.coluna = -1;

						printf("\n Voce atingiu a Nagini!\n\n");

						magiaNegraNagini = false;

						getch();
					}
					else{

						printf("\n Voce nao acertou o feitico!\n\n");

						getch();
					}
				}
				else
				if(direcao==DESCER){

					if(harry.linha<voldemort.linha && harry.coluna==voldemort.coluna && magiaNegraVoldemort==true){

						labirinto[voldemort.linha][voldemort.coluna] = ' ';

						voldemort.linha = -1;
						voldemort.coluna = -1;

						printf("\n Voce atingiu o Lord Voldemort!\n\n");

						magiaNegraVoldemort = false;

						getch();
					}
					else
					if(harry.linha<comensal.linha && harry.coluna==comensal.coluna && magiaNegraComensal==true){

						labirinto[comensal.linha][comensal.coluna] = ' ';

						comensal.linha = -1;
						comensal.coluna = -1;

						printf("\n Voce atingiu o comensal!\n\n");

						magiaNegraComensal = false;

						getch();
					}
					else
					if(harry.linha<nagini.linha && harry.coluna==nagini.coluna && magiaNegraNagini==true){

						labirinto[nagini.linha][nagini.coluna] = ' ';

						nagini.linha = -1;
						nagini.coluna = -1;

						printf("\n Voce atingiu a Nagini!\n\n");

						magiaNegraNagini = false;

						getch();
					}
					else{

						printf("\n Voce nao acertou o feitico!\n\n");

						getch();
					}
				}
				else
				if(direcao==ESQUERDA){

					if(harry.linha==voldemort.linha && harry.coluna>voldemort.coluna && magiaNegraVoldemort==true){

						labirinto[voldemort.linha][voldemort.coluna] = ' ';

						voldemort.linha = -1;
						voldemort.coluna = -1;

						printf("\n Voce atingiu o Lord Voldemort!\n\n");

						magiaNegraVoldemort = false;

						getch();
					}
					else
					if(harry.linha==comensal.linha && harry.coluna>comensal.coluna && magiaNegraComensal==true){

						labirinto[comensal.linha][comensal.coluna] = ' ';

						comensal.linha = -1;
						comensal.coluna = -1;

						printf("\n Voce atingiu o comensal!\n\n");

						magiaNegraComensal = false;

						getch();
					}
					else
					if(harry.linha==nagini.linha && harry.coluna>nagini.coluna && magiaNegraNagini==true){

						labirinto[nagini.linha][nagini.coluna] = ' ';

						nagini.linha = -1;
						nagini.coluna = -1;

						printf("\n Voce atingiu a Nagini!\n\n");

						magiaNegraNagini = false;

						getch();
					}
					else{

						printf("\n Voce nao acertou o feitico!\n\n");

						getch();
					}
				}
				else
				if(direcao==DIREITA){

					if(harry.linha==voldemort.linha && harry.coluna<voldemort.coluna && magiaNegraVoldemort==true){

						labirinto[voldemort.linha][voldemort.coluna] = ' ';

						voldemort.linha = -1;
						voldemort.coluna = -1;

						printf("\n Voce atingiu o Lord Voldemort!\n\n");

						magiaNegraVoldemort = false;

						getch();
					}
					else
					if(harry.linha==comensal.linha && harry.coluna<comensal.coluna && magiaNegraComensal==true){

						labirinto[comensal.linha][comensal.coluna] = ' ';

						comensal.linha = -1;
						comensal.coluna = -1;

						printf("\n Voce atingiu o comensal!\n\n");

						magiaNegraComensal = false;

						getch();
					}
					else
					if(harry.linha==nagini.linha && harry.coluna<nagini.coluna && magiaNegraNagini==true){

						labirinto[nagini.linha][nagini.coluna] = ' ';

						nagini.linha = -1;
						nagini.coluna = -1;

						printf("\n Voce atingiu a Nagini!\n\n");

						magiaNegraNagini = false;

						getch();
					}
					else{

						printf("\n Voce nao acertou o feitico!\n\n");

						getch();
					}
				}
				else{

					printf("\n Voce nao acertou o feitico!\n\n");

					getch();
				}

				--qtdFeiticos;
			}
		}

	}while(acao!='c' && acao!='x');

	if(acao=='c'){

		return;
	}
	else{

		system("cls");
		exit(0);
	}
}

void verificarPosicao(){

	if((harry.linha==voldemort.linha-1 && harry.coluna==voldemort.coluna) ||
	   (harry.linha==voldemort.linha+1 && harry.coluna==voldemort.coluna) ||
	   (harry.linha==voldemort.linha && harry.coluna+1==voldemort.coluna) ||
	   (harry.linha==voldemort.linha && harry.coluna-1==voldemort.coluna)){

		   magiaNegraVoldemort = true;
	   }
	   else{

		   magiaNegraVoldemort = false;
	   }

	if((harry.linha==comensal.linha-1 && harry.coluna==comensal.coluna) ||
	   (harry.linha==comensal.linha+1 && harry.coluna==comensal.coluna) ||
	   (harry.linha==comensal.linha && harry.coluna+1==comensal.coluna) ||
	   (harry.linha==comensal.linha && harry.coluna-1==comensal.coluna)){

		   magiaNegraComensal = true;
	   }
	   else{

		   magiaNegraComensal = false;
	   }

	if((harry.linha==nagini.linha-1 && harry.coluna==nagini.coluna) ||
	   (harry.linha==nagini.linha+1 && harry.coluna==nagini.coluna) ||
	   (harry.linha==nagini.linha && harry.coluna+1==nagini.coluna) ||
	   (harry.linha==nagini.linha && harry.coluna-1==nagini.coluna)){

		   magiaNegraNagini = true;
	   }
	   else{

		   magiaNegraNagini = false;
	   }

	if((harry.linha==chavePortal.linha-1 && harry.coluna==chavePortal.coluna) ||
	   (harry.linha==chavePortal.linha+1 && harry.coluna==chavePortal.coluna) ||
	   (harry.linha==chavePortal.linha && harry.coluna+1==chavePortal.coluna) ||
	   (harry.linha==chavePortal.linha && harry.coluna-1==chavePortal.coluna)){

		   calor = true;
	   }
	   else{

		   calor = false;
	   }

	if((harry.linha==buraco.linha-1 && harry.coluna==buraco.coluna) ||
	   (harry.linha==buraco.linha+1 && harry.coluna==buraco.coluna) ||
	   (harry.linha==buraco.linha && harry.coluna+1==buraco.coluna) ||
	   (harry.linha==buraco.linha && harry.coluna-1==buraco.coluna)){

		   brisa = true;
	   }
	   else{

		   brisa = false;
	   }

	if(harry.linha==buraco.linha && harry.coluna==buraco.coluna){

		gameOverFracasso = true;
	}

	if(harry.linha==chavePortal.linha && harry.coluna==chavePortal.coluna){

		gameOverSucesso = true;
	}

	if((magiaNegraVoldemort==true || magiaNegraNagini==true || magiaNegraComensal==true) && gameOverSucesso==false && gameOverFracasso==false){

		atirar();
	}
}