#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_TEXTO 100000
#define MAX_ELEMENTOS 10000

uint32_t numPagina(unsigned char*);
uint32_t numDeslocamento(unsigned char*);

int main(int argc, char *argv[]){

  FILE *arq;
  unsigned char texto[MAX_TEXTO], address[MAX_ELEMENTOS][10];
  unsigned int i, z, j;

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

  printf("%s\n", address[2]);

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
