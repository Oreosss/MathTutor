/*
 *Course: CS216-002
 *Project: Project 1
 *Purpose: This program is the main function 
 which allows the user to repeatedly enter a practice question of their choice, 
 until user puts in option 4(which ends the program)
 and generates a report for the user.
 *Author: Oreoluwa Olukotun
*/


#include <iostream>
#include <cstdlib>//for random number generator
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int displayMenu(); //prototype
int collectAnswer(const MathOperations& question);//prototype
//to automatically indent type "gg=G" in escape mode
int main()
{
	int studentAnswer;//students response to math Question
	int option;// users choice 
	MathOperations mQuestion; // declaring variable  of mathOperation type 
	MathReport userReport; // declaring data type MathReport
	int num1 = 0;// declaring and initializing  operand 1
	int num2 = 0;// declaring and initializing operand 2


	option = displayMenu(); // displays Menu & returns user option
        
 

	while (option != 4) // while user does not quit program (choose option 4)
	{

	         // check range of option
		// if not within range print out invalid choice and specify correct range
		while (( option < 1) || (option > 4)) //while choice is less than 1 or greater than 4 (if at least on is met, execute)
		{
			cout << "Invalid choice! The valid choices are 1,2,3, and 4. ";
			cin.clear(); //clears buffer of error messages
			cin.ignore (100, '\n');
			option = displayMenu();//displays menu and gets user's choice
		}//end of input validation loop	


		if (option == 1) //Addition Math Operation
		{
			int answer;
			num1 = 1 + rand() % 500; //the remainder of anything divided by 500 is between 0-499 , hence why '1' is added.
		        num2 = 1+ rand() % 500; // getting num 2, just like num1

	                //conditional statement to check which number is bigger

		        if (num1 < num2)
		        { 		
				int temp = num1; // storing value of smaller number in tempVar
				num1 = num2;// assigning bigger number to num1
				num2 = temp; //assigning smaller number to num2
			}		

			mQuestion.setOperands(num1, num2);//setting Operands for question.
			mQuestion.Addition();// addition problem
			mQuestion.print (); //prints problem
			studentAnswer = collectAnswer(mQuestion);//collects answer to question
         		userReport.insert(mQuestion, studentAnswer);
			option = displayMenu();	//displays menu and gets users choice
		}//end of option 1
	
			
		if (option == 2)// subtraction Math Operation
		{
			num1 = 1 + rand() % 500; 
		        num2 = 1+ rand() % 500; 

	                //conditional statement to check which number is bigger
		        if (num1 < num2)
		        { 		
				int temp = num1; // storing value of smaller number in tempVar
				num1 = num2;// assigning bigger number to num1
				num2 = temp; //assigning smaller number to num2
			}		

	 		

			mQuestion.setOperands(num1, num2);//setting Operands for question.
			mQuestion.Subtraction();// subtraction problem
			mQuestion.print (); //prints problem
		        studentAnswer = collectAnswer(mQuestion);//collects and checks answer
		        userReport.insert(mQuestion, studentAnswer);
			option = displayMenu();
		}//end of option 2

		if (option == 3)//multiplication math operation
		{
			num1 = 1 + rand() % 100; // numbers in range [1,100]
		        num2 = 1+ rand() % 9; // numbers in range [1,9]

	                //conditional statement to check which number is bigger

		        if (num1 < num2)
		        { 		
				int temp = num1; // storing value of smaller number in tempVar
				num1 = num2;// assigning bigger number to num1
				num2 = temp; //assigning smaller number to num2
			}		


			mQuestion.setOperands(num1, num2);//setting Operands for question.
			mQuestion.Multiplication();//multiplication  problem
			mQuestion.print (); //prints problem
		      	studentAnswer = collectAnswer(mQuestion); //collects and checks answer
			userReport.insert(mQuestion, studentAnswer);// adds question to vector
			option = displayMenu();//displays menu option for user 
		}//end of option 3
	


	}//end of main while loop	

	//if user clicks quit program (option 4), 
	//exits while loop
	//then proceeds to generate user's reports
	 cout << endl;
         userReport.generateReport();
         cout << "Thank you for using Math Tutor." << endl;


	return 0;

}

//this function collects user's response to question
//checks if its right or wrong by invoking checkAnswer method
//then gives feedback based on the correctness of answer
//and returns student answer back to mathReport vector
//so question and answer can be stored to generate report

int collectAnswer(const MathOperations& question)
{
    int studentAnswer; // The student's answer
    cout << "Please type your answer: ";
    cin  >> studentAnswer;
    cin.ignore(100, '\n');

    //conditional statement for input validation

    while (cin.fail()) // if user puts in an invalid entry
    {
            cout << "Invalid number. Try Again !" << endl; // prints out error message
            cin.clear(); // clears pipe of invalid entry
            cin.ignore(100, '\n');
            cout << "Please type your answer: "; // prompts user again
	    cin  >> studentAnswer; // extracts answer and stores in studentAnswer
            cin.ignore(100, '\n');
    }
	if (question.checkAnswer(studentAnswer))
            cout << "Congratulations! " << question.getAnswer() << " is the right answer." << endl;
        else
            cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
    
	return studentAnswer;	    
}

//This function displays the menu for the user
//collects the users's choice and returns it to main
//which then uses to option to choose which mathOperation to display
int displayMenu()
{
	int choice;// user's mathOperation choice input
	cout << "\n";
	cout << "    Math Is Fun! Take a challenge..." << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. Addition Problem" << endl;
	cout << "2. Subtraction Probem"<<endl;
	cout << "3. Multiplication Problem" << endl;
	cout << "4. Quit this program "   << endl; 
	cout << "----------------------------------------" << endl;
	cout << " Enter your choice (1-4): ";        
	cin >> choice;
	cin.ignore(100, '\n');

	return choice;//returns bavk to main
}



  
