#include <unistd.h>
#include <stdio.h>

int x;

main() {
  int i;
  x = 456;

  puts("teste de variavel global com fork");

  i = fork();

  if (i == 0) {
    // filho
    x = 567;
  } else {
    // pai
    wait();
  }

  if (i == 0) {
    printf("filho x: %i\n", x);
  } else {
    printf("pai x: %i\n", x);
  }

  exit(0);
}
