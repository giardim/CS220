/*
Zoila Loja

*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void print_to_base(int val, int outbase);

int main(int argc, char *argv[]) {
   if(argc != 2) {
      fprintf(stderr, "Provide a single filename.\n");
      exit(EXIT_FAILURE);
   }

  //Open file
   FILE *f = fopen(argv[1], "r");
   if(f == NULL) {
      perror("The file didn't open correctly");
      exit(EXIT_FAILURE);
   }

  //Variables
   unsigned int line_no = 1;
   char c;
   char inval[50];
   int inbase;
   int outbase;

   //Process the input file
   // new data type for start of line
   fpos_t start;
   //local variable that will record file position
   fgetpos(f, &start);

   //file position, single character
   fscanf(f, "%c", &c);
   while(fscanf(f, "%c", &c) == 1){

   //Type 1: Comments and line counter
   if(c == '@'){
      do{
           fscanf(f, "%c", &c);
         }while (c != '\n');
     //line_no++;

   }

   //Type 2:Blank line and line counter
   else if(c == '\n'){
      line_no++;
   }

   //Type 3: Data line and line counter
   else{
      //file postion
      fsetpos(f, &start);

      //get three numbers and do the meat of program
      //int str int and do the meat in other function
      fscanf(f, "%d %s %d", &inbase, &inval, &outbase);

      //take string and base that string is written in and returns long
      int val = (int)strtol(inval, NULL, inbase);
      printf("%d: ", line_no);
      print_to_base(val, outbase);
      puts("");
      line_no++;
   }
   fgetpos(f, &start);

   }

	fclose(f);
	exit(EXIT_SUCCESS);
}


//pcf definition
void print_to_base(int val, int outbase){

   //table lookup
   char key[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   int outcome = val / outbase;

   if (outcome == 0)
   {
      printf("%d", val);
   }
   //mod division 51 & 54
   //find the last digit first
   else if (outcome > 0){

      //print left side of input
      print_to_base(outcome, outbase);

      //print the right side of input
      printf("%c", key[val%outbase]);

   }
   
   return;
}

