/* course: CS216-002
 * Project: Lab5 (as part of Project 1)
 * Purpose: Provide the implementation of member functions for  the class named MathReport
 * Author: Oreoluwa Olukotun
 */

#include <iostream>
#include <iomanip>
#include "MathReport.h"

using namespace std;

// default constructor
MathReport::MathReport()
{
     numCorrectAnswers = 0; //initializing numCorrectAnswers
     numWrongAnswers = 0; //initializing numWrongAnswers
     //cant initialize vector except ready to add objects in it
  
}

// add a Question object into the vector of mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestion, int response)
{
	mathQuestions.push_back(newQuestion);// adding question object into vector

        if (newQuestion.checkAnswer(response))
        {
	       //correctQuestions.push_back(response);// 
               numCorrectAnswers++; // increasing number of correct answers
        }
        
        else
        {
		numWrongAnswers++; //increasing number of wrong answers
        }

 
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{

	return numCorrectAnswers;
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
	return numWrongAnswers;
}

// generate a brief report:
//   the total number of math problems has been solved;
//   the list of math problems solved with correct answers
//   the total number of correctly answered questions
//   the toal number of questions with wrong answers
//   if numCorrectAnswers > numWrongAnswers, display message of "Great job!"
//   otherwise display message of "You will do better next time..."
void MathReport::generateReport()
{
	cout << "You have solved the following " << mathQuestions.size()<<" math problems: " << endl;

	for (int i = 0 ;i < mathQuestions.size() ; i++)
        {
	       cout << "Question " << i+1  << ": " << endl;
	       mathQuestions[i].print(); //prints the questions in the vector
	       cout <<"    "<< mathQuestions[i].getAnswer() << endl; // print correct answer for question
	       cout << endl;
        } 

        cout <<"You answered "<< getNumOfCorrectAnswers() << " questions correctly"<< endl;
	cout << "You made " << getNumOfWrongAnswers() << " mistakes." << endl;

	if (numCorrectAnswers > numWrongAnswers)
	{
		cout << "Great job !" << endl;
	}
        else
	{
		cout <<"You will do better next time..." << endl;
	}
}
