/*****************************
Program that reads a file, presents the line number,
     finds the sum of the line, the smallest number
     on the line, and the biggest most frequent number
     on the line
Author: Michael Giardina
Date: 1/31/2022
Language: C++ (g++ target)
*****************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
     if(argc != 2) {
          cerr << "Provide a single filename." << endl;
          exit(EXIT_FAILURE);
     }

     ifstream f(argv[1]);
     if(!f.is_open()) {
          perror("The file didn't open correctly");
          exit(EXIT_FAILURE);
     }

     unsigned int line_no = 1;
     int i = 0;
     int num;
     int sum = 0;
     int maxnum = 0;
     int minnum = 100;
     int lst[21] = {0};
     int freq = 0;
     string line;
     while(getline(f, line)) {
          stringstream ss(line);
          unsigned int cnt = 0;
          while(ss >> num) {
               cnt++;
               sum = num + sum;    
               if (num < minnum)
               {
                   minnum = num;
               }
               lst[num + 10] = lst[num + 10] +1;
         }
          freq = -1;
          for (i = 20; i >= 0; i--)
          {      
              if (lst[i] > freq)
              {
                maxnum = i - 10;
                freq = lst[i];
              }
          }
          cout << line_no << " " << sum << " " << minnum << " " << maxnum << endl;
          line_no++;
          sum = 0;
          minnum = 100;
          maxnum = 0;
          freq = -1;
          for (i = 0; i <=21; i++)
          {
              lst[i] = 0;
          }
     } 

     f.close();
     exit(EXIT_SUCCESS);
}