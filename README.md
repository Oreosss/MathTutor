# MathTutor
*AUTHOR: Oreoluwa Olukotun


*PROJECT NAME: Math Tutor 

* PURPOSE OF FILES:
 - MathOperations.h/MathOperations.cpp: These files serve as a declaration file and implementation file respectively for the MathOperation Object. 
   The main purpose of this class is to create math questions using three different math operators which include addition, 
   subtraction and multiplication. The header file declares member functions and private members of the "MathOperations" class, which 
   include:
	- the constructor
	- set & get methods
	- math operations (addition, subtraction & multiplication)
	- print : prints question in formatted manner
	- checkAnswer: checks user's input
	- operand 1 & operand 2: numbers used for math operations
	- the operator: Math operator in use
	- answer : correct answer to questions

 - MathReport.h/MathReport.cpp: These files serve as a declaration file and implementation file respectively for the MathReport object.    
   The main purpose of this class is to generate a report of the user's performance which includes, number of correct answers & wrong      
   answers and lastly displays all questions answered with the correct answers.


 - PA1.cpp: Source file

 - Executable: CS216PA1

 - Code to compile: g++ PA1.cpp MathOperations.cpp MathReport.cpp -o CS216PA1
                    ./CS216PA1
