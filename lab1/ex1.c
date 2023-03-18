#include <stdio.h>

int main(int argc, char *argv[]){

   char buff[255];
   int id = 0;
   long int n_reg = 0;
   char name[31] = {0};
   char surname[31] = {0};
   int mark = 0;
   FILE *f1, *f2, *f3;
   char filepath1[100]; char filepath2[100]; char filepath3[100];
   sprintf(filepath1, "storage/%s", argv[1]); sprintf(filepath2, "storage/%s", argv[2]); sprintf(filepath3, "storage/%s", argv[3]);
   f1 = fopen(filepath1, "r"); f2 = fopen(filepath2, "wb"); f3 = fopen(filepath3,"w");

   if (f1 == NULL || f2==NULL || f3==NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

   if (fgets(buff, 255, f1) != NULL) {
	fprintf(f2, "%s", buff);
    	do {
        	while(fscanf(f1, "%d %ld %s %s %d", &id, &n_reg, name, surname, &mark) == 5) { 
	       		fprintf(f2, "%d %ld %s %s %d\n", id, n_reg, name, surname, mark);
		}	
   	} while (fgets(buff, 255, f1) != NULL);
   }

   fclose(f2);	//ho scritto su f2 e il puntatore èrimasto a fine file, io voglio leggere dall'inizio
   f2 = fopen(filepath2, "rb");	//devo chiuderlo e riaprirlo per riportare il puntatore in cima al file

   if (f2==NULL) {
         printf("Error: could not open file.\n");
	 return 1;
    }

   if (fgets(buff, 255, f2) != NULL) {
   	do {
      		fputs(buff, f3);
   	} while (fgets(buff, 255, f2) != NULL);
   }

   fclose(f1);
   fclose(f2);
   fclose(f3);

   return 0;
}
