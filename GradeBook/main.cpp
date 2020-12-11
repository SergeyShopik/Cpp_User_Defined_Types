#include "GradeBook.h"

const size_t cols = 3;
void initDDArray(int arr[][cols], size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[rows][cols] = 60 + rand() % 40;
		}
	}
}
void printDDArray(int arr[][cols], size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << arr[rows][cols] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	srand(time(0));
	int gradesArray[GradeBook::students][GradeBook::tests] =
	{
		{88, 90, 70},
		{68, 80, 71},
		{78, 100, 70},
		{83, 66, 71},
		{98, 91, 74},
		{60, 70, 77},
		{88, 91, 89},
		{90, 68, 85},
		{100, 62, 79},
		{61, 98, 76},
	};
	GradeBook myGradeBook("Introduction to C++", gradesArray);
	myGradeBook.displayMessage();
	myGradeBook.processGrades();

	std::cout << "\n\n";

	std::cout << Employee::getCount() << std::endl;

	Employee* e1Ptr = new Employee("Bernadett", "Rostankowski");
	Employee* e2Ptr = new Employee("Howard", "Wolowits");
	std::cout << e1Ptr->getCount() << std::endl;

	std::cout << e1Ptr->getFirstName() << " " << e1Ptr->getLastName() << std::endl;
	std::cout << e2Ptr->getFirstName() << " " << e2Ptr->getLastName() << std::endl;

	delete e1Ptr;
	e1Ptr = nullptr;
	delete e2Ptr;
	e2Ptr = nullptr;

	std::cout << Employee::getCount() << std::endl;

	std::cout << "\n\n";

	//test class Array
	/*Array integers1(7);
	Array integers2;

	std::cout << "Size of Array integers1 is "
		<< integers1.getSize()
		<< "\nArray afer initialization:\n" << integers1;
	std::cout << "Size of Array integers1 is "
		<< integers2.getSize()
		<< "\nArray afer initialization:\n" << integers2;

	std::cout << "\nEnter 17 integers:" << std::endl;
	std::cin >> integers1 >> integers2;

	std::cout << "\nAfter input, the Arrays contain:\n"
		<< "integers1:\n" << integers1
		<< "integers2:\n" << integers2;

	std::cout << "\nEvaluating: integers1 != integers2" << std::endl;
	if (integers1 != integers2)
		std::cout << "integers1 and integers2 are not equal" << std::endl;

	Array integers3(integers1);
	std::cout << "\nSize of Array integers3 is "
		<< integers3.getSize()
		<< "\nArray after initialization:\n" << integers3;

	std::cout << "\nAssigning integers2 to integers1:" << std::endl;
	integers1 = integers2;
	std::cout << "integers1:\n" << integers1
		<< "integers2:\n" << integers2;

	std::cout << "\nEvalutating: integers1 == integers2" << std::endl;
	if (integers1 == integers2)
		std::cout << "integers1 and integers2 are equal" << std::endl;

	std::cout << "\nintegers1[5] is " << integers1[5];
	std::cout << "\n\nAssigning 1000 to integers1[5]" << std::endl;
	integers1[5] = 1000;
	std::cout << "integers1:\n" << integers1;

	std::cout << "\nAttempt to assign 1000 to integers1[15]" << std::endl;
	integers1[15] = 1000;

	std::cout << "\n\n";*/

	//test class String
	String s1("happy");
	String s2(" birthday ");
	String s3;

	std::cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
		<< "\"; s3 is \"" << s3 << '\"'
		<< std::boolalpha << "\n\nThe results of comparing s2 and s1:"
		<< "\ns2 == s1 yields " << (s2 == s1)
		<< "\ns2 != s1 yields " << (s2 != s1)
		<< "\ns2 > s1 yields " << (s2 > s1)
		<< "\ns2 < s1 yields " << (s2 < s1)
		<< "\ns2 >= s1 yields " << (s2 >= s1)
		<< "\ns2 <= s1 yields " << (s2 <= s1);

	std::cout << "\n\nTesting !s3:" << std::endl;
	if (!s3)
	{
		std::cout << "s3 is empty; assigning s1 to s3;" << std::endl;
		s3 = s1;
		std::cout << "s3 is \"" << s3 << "\"";
	}
	std::cout << "\n\ns1 += s2 yields s1 = ";
	s1 += s2;
	std::cout << s1;

	std::cout << "\n\ns1 += \" to you\" yields" << std::endl;
	s1 += " to you";
	std::cout << "s1 = " << s1 << "\n\n";

	std::cout << "The substring of s1 starting at\n"
		<< "location 0 for 14 characters, s1(0, 14), is:\n"
		<< s1(0, 14) << "\n\n";

	std::cout << "The substring of s1 starting at\n"
		<< "location 15, s1(15), is: "
		<< s1(15) << "\n\n";

	String* s4Ptr = new String(s1);
	std::cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";

	std::cout << "assigning *s4Ptr to *s4Ptr" << std::endl;
	*s4Ptr = *s4Ptr;
	std::cout << "*s4Ptr = " << *s4Ptr << std::endl;

	delete s4Ptr;

	s1[0] = 'H';
	s1[6] = 'B';
	std::cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
		<< s1 << "\n\n";

	std::cout << "Attempt to assign 'd' to s1[30] yields: " << std::endl;
	s1[30] = 'd';

	system("pause");
	return 0;
}