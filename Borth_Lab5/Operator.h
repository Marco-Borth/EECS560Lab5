/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 3 - Implementation of Hash Table (Closed Hashing)
 * Description:  Operator Class is defined.
 * Date: 2/11/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "LinkedList.h"
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

class Operator {
public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

  //void insertRecord(string table);

  //void removeRecord(string table);

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator();
};
#endif
