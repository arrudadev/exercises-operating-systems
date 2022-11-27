#include <stdio.h>
#include <stdlib.h>

struct partition {
  int boot_flag;
  int chs_begin[3];
  char sys_type;
  int chs_end[3];
  int start_sector[4];
  int nr_sector[4];
};

void readFile(char *fileContent, FILE *fileMBR) {
  if (fread(fileContent, 1, 512, fileMBR) <= 0) {
    printf("Erro ao ler o arquivo!");
  }
}

void printPartitionInfo(struct partition *P1) {
  printf("\nINICIO: %d", *P1-> chs_begin);
  printf("\nFINAL: %d", (*P1->nr_sector + *P1-> chs_begin)-1);

  if (*P1->nr_sector >= 1000000) {
    printf("\nTAMANHO: %d Giga Bytes", *P1->nr_sector /2097152);
  }

  if (*P1->nr_sector <= 1000) {
    printf("\nTAMANHO: %d Kilo Bytes", *P1->nr_sector / 2);
  }

  if (*P1->nr_sector >= 1000) {
    printf("\nTAMANHO: %d Mega bytes ", *P1->nr_sector / 2048);
  }
}

void readPartitions(char *fileContent) {
  int address[4] = {0x01BE, 0x01CE, 0x01DE, 0x01FE};

  for (int i = 0; i < 4; i++) {
    printf("PARTIÇÃO %d", i + 1);

    struct partition *currentPartition = (struct partition *) &fileContent[address[i]];

    printPartitionInfo(currentPartition);

    printf("\n\n");
  }
}

int main() {
  FILE *fileMBR = fopen("mbr.bin", "r");

  char *fileContent = malloc(512);

  readFile(fileContent, fileMBR);

  readPartitions(fileContent);

  free(fileContent);

  fclose(fileMBR);

  return 0;
}

