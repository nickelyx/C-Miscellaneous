#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {

  FILE *image_file;
  int i, j;
  int r, g, b;

  image_file = fopen("image-file-17.pnm", "wb");

  fputs("P6\n", image_file);
  fputs("500 500\n", image_file);
  fputs("255\n", image_file);

  for(i = 0; i < 500; i++)
    for (j = 0; j < 500; j++){
      /*r = ((-i*i*-j+j*j*j*j+i*j*i*j)/230000000) % 256;
      g = ((i*i+i+j*j*j+i+i+i*j*j*j+i+i*i)/21000000) % 256;
      b = ((i*i*j*j+i+j)/13000000) % 256;*/

      r = ((-i*i*-j+j*j*j*j+i*j*i*j)/230000000) % 256;
      //r = ((-i*i*-j+j*j*j*j+i*i*(j/47)*(i/13))/230000000) % 256;
      //r = ((-i*i*i-(j*j*i*j)*i)/910000000) % 256;
      g = ((((-i*i*i*2-i*9)*j/2-(j*j*j*2-j*9)*i/2))/870000000) % 256;
      //g = 0;
      //b = 0;
      b = ((i*i*j*j+i+j+j+i)/16500000) % 256;


      fputc(r, image_file);  fputc(g, image_file); fputc(b, image_file);
    }

  fclose(image_file);
  return 0;
}
