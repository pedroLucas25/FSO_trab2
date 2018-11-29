#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define MAX_TEXTO 100000
#define MAX_ELEMENTOS 10000

uint32_t numPagina(unsigned char*);
uint32_t numDeslocamento(unsigned char*);
uint32_t geraTabela();
time_t t;

int main(int argc, char *argv[]){

  FILE *arq;
  unsigned char texto[MAX_TEXTO], address[MAX_ELEMENTOS][10];
  unsigned int i, z, j;
  uint32_t tabelaDePaginas[256];
  srand((unsigned) time(&t));

  arq = fopen(argv[1], "r");
  if (arq == NULL){  // Se houve erro na abertura
  perror("Problemas na abertura do arquivo\n");
  return EXIT_FAILURE;
  }

  fgets((char*)texto, MAX_TEXTO, arq);

/////////////////////////////Função que separa os números do arquivo////////////////////////////////////////
  i = 0;
  for(j=0;j<strlen((const char*)texto);j++){
    z=0;
    while (texto[i] != ' ') {
      address[j][z] = texto[i];
      z++;
      i++;
    }
    i++;
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////

  for(i=0;i<256;i++){
    tabelaDePaginas[i] = geraTabela();
  }

  for(i=0;i<5;i++){
    printf("O enderço logico que esta sendo traduzido e o: %s\n", address[i]);
    printf("Quadro: %d\nPagina: %d\n", tabelaDePaginas[numPagina(address[i])], numPagina(address[i]));
    printf("Offsset: %d\n", numDeslocamento(address[i]));
    printf("Endereco traduzido: %d\n", (tabelaDePaginas[numPagina(address[i])]*256)+numDeslocamento(address[i]));
  }

  fclose(arq);
  return 0;
}

uint32_t numPagina(unsigned char* numChar){
  uint32_t num = atoi((const char*)numChar);
  num &= 0x0000FF00;
  num >>= 8;

  return num;
}

uint32_t numDeslocamento(unsigned char* numChar){
  uint32_t num = atoi((const char*) numChar);
  num &= 0x000000FF;

  return num;
}

uint32_t geraTabela(){
  uint32_t resultado;
  resultado = (rand() % (256));
  return resultado;
}
