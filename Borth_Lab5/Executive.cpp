/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 5- Experimental Profiling on Hash Tables
 * Description:  Executive Class creates and runs the Operator class.
 * Date: 2/28/20
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "Operator.h"
#include <string>
using namespace std;

// Create Executive Object.
Executive::Executive(){}

void Executive::run() {
	Operator List;
	List.run();
}
