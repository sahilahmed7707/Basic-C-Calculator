#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <matheval.h>
#include <assert.h>

//Input must be something like 3*x^2-4*x, this can be translated as x²-4x
//gcc -o derivative derivative.c  -lm -lmatheval

int main ()
{
    char input[400];
    void *func;
    scanf("%s",input);

    func = evaluator_create(input);
    assert(func);
  

  void *f_prim;
  f_prim = evaluator_derivative (func, "x");
  printf("f'(x) = %s\n", evaluator_get_string (f_prim));
  
  return 0;
}




