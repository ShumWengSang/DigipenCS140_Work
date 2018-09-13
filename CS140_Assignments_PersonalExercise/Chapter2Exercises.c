#include <stdio.h>

/*
#define EXERCISE_ONE

#define EXERCISE_THREE 

#define EXERCISE_FOUR
*//*
#define PROGRAMMING_PROJECT_ONE
*/
#define PROGRAMMING_PROJECT_TWO


#ifdef EXERCISE_ONE
int main(void)
{
  printf("hello, world \n");
}
#endif


#ifdef EXERCISE_THREE
int main(void)
{
  int height = 8;
  int length = 12;
  int width = 10;
  int volume = height * width * length;
  
  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);
  
  return 0;
}
#endif

#ifdef EXERCISE_FOUR
int main(void)
{
  int a,b,c,d,e;
  float f,g,h;
	
  printf("A: %i, B: %i, C: %d, D: %d, E: %e, F: %f, G: %f, H:%f",a,b,c,d,e,f,g,h);
  return 0;
}
#endif

#ifdef PROGRAMMING_PROJECT_ONE
int main(void)
{
  printf("        *\n");
  printf("       *\n");
  printf("      *\n");
  printf("     *\n");
  printf("*   *\n");
  printf(" * *\n");
  printf("  *\n");
}

#endif

#ifdef PROGRAMMING_PROJECT_TWO
int main(void)
{
  const int PI = 3.1415;
  int radius = 10 * 10 * 10;
  printf("Volume: %f", 4.0f/3.0f * PI * radius);
}

#endif

