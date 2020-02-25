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
/*
void Operator::insertRecord(string table) {
  hashValue = hashKey(pword);
  int index = hashValue % hashTableLength;
  int position = 0;

  if (table == "LinearTable") {
    placedLinear = false;

    for (int i = 1; i <= LinearTable.getLength(); i++) {
      if (LinearTable.getEntry(i)->getUsername() == uname) {
        throw(runtime_error("ERROR! Username Already Exists.\n"));
      }
    }

    while(!placedLinear && position < LinearTable.getLength()) {
      if(LinearTable.getEntry(index + 1)->getUsername() == "\0" && LinearTable.getEntry(index + 1)->getPassword() == "\0") {
        placedLinear = true;
        LinearTable.getEntry(index + 1)->setUsername(uname);
        LinearTable.getEntry(index + 1)->setPassword(pword);
        //tempLinear.getEntry(index + 1)->setUsername(uname);
        //tempLinear.getEntry(index + 1)->setPassword(pword);
        //replace(index + 1, User(uname, pword));
      } else {
        index++;
        position++;
        index = index % hashTableLength;
      }
    }
  } else if (table == "QuadraticTable") {
    placedQuadratic = false;
    int exponent = position;

    for (int i = 1; i <= QuadraticTable.getLength(); i++) {
      if (QuadraticTable.getEntry(i)->getUsername() == uname) {
        throw(runtime_error("ERROR! Username Already Exists.\n"));
      }
    }

    while(!placedQuadratic && position < QuadraticTable.getLength()) {
      if(QuadraticTable.getEntry(index + 1)->getUsername() == "\0" && QuadraticTable.getEntry(index + 1)->getPassword() == "\0") {
        placedQuadratic = true;
        QuadraticTable.getEntry(index + 1)->setUsername(uname);
        QuadraticTable.getEntry(index + 1)->setPassword(pword);
        //tempQuadratic.getEntry(index + 1)->setUsername(uname);
        //tempQuadratic.getEntry(index + 1)->setPassword(pword);
        //replace(index + 1, User(uname, pword));
      } else {
        position++;
        exponent = position^2;
        index = ( (index % hashTableLength) + exponent ) % hashTableLength;
      }
    }
  }

  // insertRecord is over.
}
*/
/*
void Operator::removeRecord(string table) {
  hashValue = hashKey(pword);
  int index = hashValue % hashTableLength;
  int position = 0;

  if (table == "LinearTable") {
    placedLinear = false;

    while(!placedLinear && position < LinearTable.getLength()) {
      if(LinearTable.getEntry(index + 1)->getUsername() == uname && LinearTable.getEntry(index + 1)->getPassword() == pword) {
        placedLinear = true;
        LinearTable.getEntry(index + 1)->setUsername("\0");
        LinearTable.getEntry(index + 1)->setPassword("\0");
        //newUser = new User();
        //LinearTable.replace(index + 1, newUser);
      } else {
        index++;
        position++;
        index = index % hashTableLength;
      }
    }
  } else if (table == "QuadraticTable") {
    placedQuadratic = false;
    int exponent = position;

    while(!placedQuadratic && position < QuadraticTable.getLength()) {
      if(QuadraticTable.getEntry(index + 1)->getUsername() == uname && QuadraticTable.getEntry(index + 1)->getPassword() == pword) {
        placedQuadratic = true;
        QuadraticTable.getEntry(index + 1)->setUsername("\0");
        QuadraticTable.getEntry(index + 1)->setPassword("\0");
        //newUser = new User();
        //QuadraticTable.replace(index + 1, newUser);
      } else {
        position++;
        exponent = position^2;
        index = ( (index % hashTableLength) + exponent ) % hashTableLength;
      }
    }
  }

  // removeRecord is over.
}
*/
void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";

  int m = 1000003;
  int R = 773;

  int hashValue;
  int hashIndex;

  int QuadraticTable [m];
  int DoubleHashTable [m];

  int inputSize = 0;
  clock_t start, end;
  double buildTime = 0.00000;
  int itemsFound = 0;
  int itemsLost = 0;

  for(int i = 0; i < m; i++) {
    QuadraticTable[i] = -1;
    DoubleHashTable[i] = -1;
  }

  int random_number;

  srand (time(NULL));   //Initialize random seed: This means every time you run the program it will change the numbers generated

  inputSize = floor (0.1 * m);

  start = clock();
  for(int i = 0; i < floor (0.1 * m); i++) {
    random_number = rand() % 5000000 + 1;
    int k = 0;
    while( k < 25) {
      hashValue = random_number % m;
      hashIndex = ( hashValue + int (pow(k, 2)) ) % m;

      if(QuadraticTable[hashValue] == -1) {
        QuadraticTable[hashIndex] = random_number;
        k = 25;
        itemsFound++;
      }

      if(k == 24)
        itemsLost++;

      k++;
    }
  }
  end = clock();
  buildTime = double(end - start) / double(CLOCKS_PER_SEC);

  cout << "______________________Performance (Quadratic Probing) _________________________" << endl;
  cout << "Input size: " << inputSize << endl;
  cout << "Build (s): " << setprecision(5) << buildTime << endl;
  cout << "Number of items | successfully found: " << itemsFound << endl;
  cout << "Number of items | not found: " << itemsLost << endl;

  /*
  itemsFound = 0;
  itemsLost = 0;
  int RValue = 0;

  start = clock();
  for(int i = 0; i < inputSize; i++) {
    int k = 0;
    while( k < 25) {
      hashValue = randomInts[i] % m;
      RValue = R - (randomInts[i] - R);
      hashIndex = ( hashValue + (k * RValue) ) % m;

      if(DoubleHashTable[hashValue] == -1) {
        DoubleHashTable[hashIndex] = randomInts[i];
        k = 25;
        itemsFound++;
      }

      if(k == 24)
        itemsLost++;

      k++;
    }
  }
  end = clock();
  buildTime = double(end - start) / double(CLOCKS_PER_SEC);;

  cout << "______________________Performance (Double Hashing) _________________________" << endl;
  cout << "Input size: " << inputSize << endl;
  cout << "Build (s): " << setprecision(5) << buildTime << endl;
  cout << "Number of items | successfully found: " << itemsFound << endl;
  cout << "Number of items | not found: " << itemsLost << endl;
  */


  /*random_number
  set2[floor(0.2 * m)];
  for(int i = 0; i < sizeof(set2); i++) {
    random_number = rand() % 5000000 + 1;
    set2[i] = random_number;
  }

  set3[floor(0.3 * m)];
  for(int i = 0; i < sizeof(set3)); i++) {
    random_number = rand() % 5000000 + 1;
    set3[i] = random_number;
  }

  set4[floor(0.4 * m)];
  for(int i = 0; i < sizeof(set4); i++) {
    random_number = rand() % 5000000 + 1;

void
    set4[i] = random_number;
  }

  set5 = double[floor(0.5 * m)];
  for(int i = 0; i < sizeof(set5); i++) {
    random_number = rand() % 5000000 + 1;
    set5[i] = random_number;
  }
  */

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
