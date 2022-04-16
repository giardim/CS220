/************************
Program to convert any value to 
     an outbase from a file
Written by Michael Giardina
Feb. 9th, 2022
Language: C++ (g++ target)
************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

void convert(int, int);

int main(int argc, char *argv[]) {
     //Check if a file was given
     if(argc != 2) {
          cerr << "Provide a single filename." << endl;
          exit(EXIT_FAILURE);
     }

     //Make sure the file opened correctly
     ifstream f(argv[1]);
     if(!f.is_open()) {
          perror("The file didn't open correctly");
          exit(EXIT_FAILURE);
     }

     unsigned int line_no = 1;
     int outbase = 0;
     int inbase = 0;
     int size = 0;
     long fin;
     string value;
     string line;

     //While there are still lines from the file
     while(getline(f, line)) {
          //Have to convert to a const char for strtol
          const char * cvalue = value.c_str();
          stringstream ss(line);
          size = line.length();
          ss >> inbase >> value >> outbase;
          if(line[0] != '@' && size != 0)
          {    
               //coverts value from inbase to base 10
               fin = strtol(cvalue, nullptr, inbase);
               cout << line_no << ": ";
               convert(fin, outbase);
               cout << endl;
          }
         line_no++;
     }

     f.close();
     exit(EXIT_SUCCESS);
}

void convert (int fin, int outbase)
{
/************************
Function that controls the converting
     and output of the number
Written by Michael Giardina
Feb. 9th, 2022
Language: C++ (g++ target)
************************/
     int i = 0;
     int size = 0;
     int remain = 0;
     char key[36] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                    'A', 'B', 'C', 'D', 'E',
                    'F','G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O',
                    'P', 'Q', 'R', 'S', 'T', 
                    'U', 'V', 'W', 'X', 'Y', 
                    'Z'};
     
     //Finds the remainder which will be used 
     //   to convert the number to the outbase
     remain = key[fin % outbase];

     //Divides to check if there are more
     //   remainders to find
     fin = fin / outbase;

    

     if (fin != 0)
     {
     convert(fin, outbase);
     }

     if(remain > 9)
     {
          //Char is needed or else it would print
          //   the value from the ascii table
          cout << (char) remain;
     }
     else 
     {
          cout << remain;
     }

     return;
}