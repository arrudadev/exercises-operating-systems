#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void cleanHitsFolder(DIR *directory) {
  struct dirent *entries;

  while ((entries = readdir(directory)) != NULL) {
    char *pt = malloc(strlen("hits/") + strlen("entries->d_name"));

    strcpy(pt, "hits/");

    strcat(pt, entries->d_name);

    remove(pt);

    free(pt);
  }
}

void writeHitsFolderFiles(int x, int y, int r) {
    if (x*x + y*y <= r * r) {
        char str[110];

        sprintf(str, "hits/%d%d%d", (int) clock(), x, y);
        
        FILE *f = fopen(str, "w+");
        
        fclose(f);
    }
}

void removeChildProcess(pid_t pid) {
    if(pid != getpid()) {
        exit(0);
    }
}

void waitOneSecond() {
    clock_t time = clock();

    while((clock() - time) < 1000000) {
        continue;
    }
}

int getCountHits(DIR *directory) {
    struct dirent *entries;

    int count = 0;

    while ((entries = readdir(directory)) != NULL) {
        count++;
    }

    return count;
}

int main() {
    mkdir("hits", S_IRWXU | S_IRWXG);

    DIR *directory = opendir("hits");

    cleanHitsFolder(directory);

    int pid = getpid();

    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();

    srand(getpid());

    int r = 100;
    int d = r * 2;

    int x = (rand() % d) - r;
    int y = (rand() % d) - r;

    writeHitsFolderFiles(x, y, r);

    closedir(directory);

    removeChildProcess(pid);

    waitOneSecond();

    directory = opendir("hits");

    int hits = getCountHits(directory);

    closedir(directory);

    rmdir("hits");

    printf("Pontos no circulo: %d\n", hits);
    printf("PI = %f\n", (hits*4)/1024.f);
}