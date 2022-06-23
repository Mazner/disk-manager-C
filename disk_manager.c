#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIR "./arquivos"

typedef struct nosetor{
    unsigned long inicio;
    unsigned long fim;
    struct nosetor* prox;
    struct nosetor* ant;
}NoSetor;

typedef struct noarquivo{
    char nome[40];
    long int tam;
    NoSetor* setores;
    struct noarquivo* prox;
    struct noarquivo* ant;
}NoArquivo;

typedef struct{
    char nome[40];
    void* disco;
    NoSetor* livres;
    NoArquivo* arquivos;
    long int tamDisco;
    long int espacoLivre;
    long int qtdeArquivos;    
}Disco;

NoSetor* criaNoSetor(long int inicio, long int fim){
    NoSetor* novo = (NoSetor*) malloc(sizeof(NoSetor));

    if(!novo) return NULL;

    novo->inicio = inicio;
    novo->fim = fim;
    novo->ant = novo->prox = novo;

    return novo;
}

Disco* disco_cria(char* nome, long int tamanho){
    Disco* d = (Disco*) malloc(sizeof(Disco));

    if(!d) return 0;

    strcpy(d->nome, nome);
    d->tamDisco = tamanho;
    d->espacoLivre = tamanho;
    d->qtdeArquivos = 0;

    d->disco = malloc(tamanho); 

    d->livres = criaNoSetor(-99, -99);

    NoSetor* aux = criaNoSetor(0, tamanho - 1);

    inserirEsquerdaSetor(d->livres, aux); //Pegar da lista;

    d->arquivos = criaNoArquivo("Sentinela", -1); //nome e 
    d->arquivos->ant = d->arquivos->prox = d->arquivos;

    return d;
}

bool disco_grava(Disco* d, char* arquivo); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_remove(Disco* d, char* nome); // somente o nome do arquivo sem o caminho
bool disco_recupera(Disco* d, char* nome, char* arquivoDestino); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
void disco_lista(Disco* d);