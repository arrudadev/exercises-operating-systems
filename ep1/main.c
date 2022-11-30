#include <stdio.h>

int main() {
 int *p = (int) MyMalloc(100);

 int *r = (int) MyMalloc(1000);

 MyFree(p);

 MyFree(r);

 printf("done");
}