/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 3 - Implementation of Hash Table (Closed Hashing)
 * Description:  Operator Class will either run the Interactive program for a Hash Table (Closed Hashing)
 * Date: 2/15/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
using namespace std;

Operator::Operator(){}

void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";
  srand (time(NULL));   //Initialize random seed: This means every time you run the program it will change the numbers generated

  int m = 1000003;
  int R = 773;
  int random_number;
  int size = 10;

  int hashValue;
  int hashIndex;
  int RValue = 0;

  int hashTable [m];
  int randomArray [m];
  int searchArray [(int) floor (0.01 * m)];

  int inputSize [size];
  clock_t start, end;
  double buildTime [size];
  int itemsFound [size];
  int itemsLost [size];

  for(int i = 0; i < size; i++) {
    inputSize[i] = 0;
    buildTime[i] = 0.000000;
    itemsFound[i] = 0;
    itemsLost[i] = 0;
  }

  for(int j = 0; j < size; j++) {
    for(int i = 0; i < m; i++) {
      hashTable[i] = -1;
      random_number = rand() % 5000000 + 1;
      randomArray[i] = random_number;
    }

    start = clock();
    if (j < 5) {
      inputSize[j] = floor (0.1 * m * (j + 1));
      for(int i = 0; i < floor (0.1 * m * (j + 1)); i++) {
        int k = 0;
        while( k < 25) {
          hashValue = randomArray[i] % m;
          hashIndex = ( hashValue + int (pow(k, 2)) ) % m;

          if(hashTable[hashIndex] == -1) {
            hashTable[hashIndex] = randomArray[i];
            k = 25;
          }
          k++;
        }
      }
    } else {
      inputSize[j] = floor (0.1 * m * (j - 4));
      for(int i = 0; i < floor (0.1 * m * (j - 4)); i++) {
        int k = 0;
        while( k < 25) {
          hashValue = randomArray[i] % m;
          RValue = R - (randomArray[i] - R);
          hashIndex = ( hashValue + (k * RValue) ) % m;

          if(hashTable[hashIndex] == -1) {
            hashTable[hashIndex] = randomArray[i];
            k = 25;
          }
          k++;
        }
      }
    }
    end = clock();
    buildTime[j] = double(end - start) / double(CLOCKS_PER_SEC);

    for(int i = 0; i < floor (0.01 * m); i++) {
      random_number = rand() % 5000000 + 1;
      searchArray[i] = random_number;
    }

    for(int i = 0; i < floor (0.01 * m); i++) {
      bool isFound = false;
      int k = 0;
      if (j < 5) {
        while( k < 25) {
          hashValue = searchArray[i] % m;
          hashIndex = ( hashValue + int (pow(k, 2)) ) % m;

          if(hashTable[hashIndex] == searchArray[i]) {
            itemsFound[j]++;
            isFound = true;
            k = 25;
          }

          if(!isFound && k == 24)
            itemsLost[j]++;

          k++;
        }
      } else {
        while( k < 25) {
          hashValue = searchArray[i] % m;
          RValue = R - (searchArray[i] - R);
          hashIndex = ( hashValue + (k * RValue) ) % m;

          if(hashTable[hashIndex] == searchArray[i]) {
            itemsFound[j]++;
            isFound = true;
            k = 25;
          }

          if(!isFound && k == 24)
            itemsLost[j]++;
          k++;
        }
      }
    }
  }

  cout << "_______________________________Performance (Quadratic Probing)___________________________________\n";
  cout << "Input size:";
  for (int i = 0; i < size/2; i++)
    cout << "\t|\t" << inputSize[i];
  cout << "\nBuild (s):\t";
  for (int i = 0; i < size/2; i++)
    cout << "|\t" << setprecision(5) << buildTime[i];
  cout << "\nNumber of items |";
  for (int i = 0; i < size/2 - 1; i++)
    cout << "\t\t|";
  cout << "\nsuccessfully\t|";
  for (int i = 0; i < size/2 - 1; i++)
    cout << "\t\t|";
  cout << "\nfound:\t\t";
  for (int i = 0; i < size/2; i++)
    cout <<  "|\t" << itemsFound[i] << "\t" ;
  cout << "\nNumber of items |";
  for (int i = 0; i < size/2 - 1; i++)
    cout << "\t\t|";
  cout << "\nnot found:\t";
  for (int i = 0; i < size/2; i++)
    cout << "|\t" << itemsLost[i] << "\t";
  cout << endl;

  cout << "\n\n\n_________________________________Performance (Double Hashing)_____________________________________\n";
  cout << "Input size:";
  for (int i = size/2; i < size; i++)
    cout << "\t|\t" << inputSize[i];
  cout << "\nBuild (s):\t";
  for (int i = size/2; i < size; i++)
    cout << "|\t" << setprecision(5) << buildTime[i];
  cout << "\nNumber of items |";
  for (int i = size/2; i < size - 1; i++)
    cout << "\t\t|";
  cout << "\nsuccessfully\t|";
  for (int i = size/2; i < size - 1; i++)
    cout << "\t\t|";
  cout << "\nfound:\t\t";
  for (int i = size/2; i < size; i++)
    cout <<  "|\t" << itemsFound[i] << "\t" ;
  cout << "\nNumber of items |";
  for (int i = size/2; i < size - 1; i++)
    cout << "\t\t|";
  cout << "\nnot found:\t";
  for (int i = size/2; i < size; i++)
    cout << "|\t" << itemsLost[i] << "\t";
  cout << endl;

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
