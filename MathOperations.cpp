/* course: CS216-002
 * Project: Lab 4 (as part of Project 1)
 * Purpose: to define the class named MathOperations
 * Author: Oreoluwa Olukotun
 */
#include <iostream>
#include <iomanip>
#include "MathOperations.h"

// default constructor    
MathOperations::MathOperations()
{
	operand1 = 0;       // initializing operand1
	operand2 = 0;      // initializing operand2
	theoperator = 'E'; // initializing char operator
	answer = 0;      // initalizing answer 
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2)
{
	operand1 = op1; // setting private member operand1 to value of op1
	operand2 = op2; // setting private member operand2 to value of op2
}

// read the current value of the private data member: current operator
char MathOperations::getOperator() const
{
	return theoperator; // returns the current operator 
}

// return the value of the data member: answer
int MathOperations::getAnswer() const
{ 
	return answer; // returns value of answer 
}

// set theoperator to '+'
// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition()
{
	int sum = 0;                 // variable that stores sum of op1 and op2
	theoperator = '+' ;         // setting the operator to '+' (addition sign)
	sum = operand1 + operand2 ;// applying addition operation to the numbers
	answer = sum;             // setting answer equal to op1 + op2
}

// set theoperator to '-'
// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction()
{
	int difference = 0; // variable that stores the difference btwn op1 & op2
	theoperator = '-'; // seeting theoperator to '-' (subtraction sign)
	difference = operand1 - operand2 ; // applying subtraction operation
	answer = difference; // setting answer equal to op1 - op2 
}

// set theoperator to '*'
// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication()
{
	int product = 0; // variable that stores the product of op1 & op2
	theoperator = '*'; // setting theoperator to '*' multiplication sign
	product = operand1 * operand2; // applying the multiplication operation
	answer = product; // setting answer to op1 * op2
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const
{
	if (answer == response)
		return true; // if answer is equal to correct response return 'true' 
	else
		return false; // else return false
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const
{
	
	cout <<"     " << operand1 << endl;
	cout << theoperator; 
	
	 if ((theoperator == '+') || (theoperator == '-'))
	 	cout << right << setw(7)<< operand2 << endl;
	else
		cout << right << setw(6) << operand2 << endl;
	cout <<"_________" << endl;

}
