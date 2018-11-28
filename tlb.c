#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LINHA 100000

uint32_t numPagina(unsigned char*);
uint32_t numDeslocamento(unsigned char*);

int main(int argc, char *argv[]){

  FILE *arq;
  unsigned char texto[MAX_LINHA], primeiroEnd[10];
  int i=0;

  arq = fopen(argv[1], "r");
  if (arq == NULL){  // Se houve erro na abertura
  perror("Problemas na abertura do arquivo\n");
  return EXIT_FAILURE;
  }

  fgets((char*)texto, MAX_LINHA, arq);

  while(texto[i] != ' '){
    primeiroEnd[i] = texto[i];
    i++;
  }

  printf("%s\n", texto);

  printf("%x\n", numDeslocamento(primeiroEnd));

  fclose(arq);

  //printf("Ola mundo!\n");
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
