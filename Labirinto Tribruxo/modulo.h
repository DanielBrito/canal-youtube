#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<locale.h>

#define DIMENSAO 10

#define SUBIR 'w'
#define DESCER 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

struct elemento{

	int linha;
	int coluna;
};

typedef struct elemento Elemento;

void iniciarJogo();
void telaInicial();
void pausarTela();
void gameOver();
void raio();

void morte();
void estacas();
void hogwarts();

void menuPrincipal();
void subMenu();

void novaPartida();
void historia();
void regras();

void inicializarLabirinto();
void imprimirLabirinto();

int gerarCoordenada();
void posicionarElemento();

void mostrarLegenda();
void movimentar(char movimento);
void atirar();
void verificarPosicao();