#include "GradeBook.h"

	GradeBook::GradeBook(std::string name, const int gradesArray[][tests])
	{
		setCourseName(name);

		for (int student = 0; student < students; student++)
			for (int test = 0; test < tests; test++)
				grades[student][test] = gradesArray[student][test];
	}

	void GradeBook::setCourseName(std::string name)
	{
		if (name.length() <= 25)
			courseName = name;
		else
		{
			courseName = name.substr(0, 25);
			std::cout << "Name \"" << name << "\" exceeds maximum length.\n"
				<< "Limiting course name to first 25 characters.\n" << std::endl;
		}
	}
	void GradeBook::setTeacherName(std::string name)
	{
		if (name.length() <= 25)
			teacherName = name;
		else
		{
			teacherName = name.substr(0, 25);
			std::cout << "Name \"" << name << "\" exceeds maximum length.\n"
				<< "Limiting teacher name to first 25 characters.\n" << std::endl;
		}
	}

	std::string GradeBook::getCourseName()
	{
		return courseName;
	}
	std::string GradeBook::getTeacherName()
	{
		return teacherName;
	}

	void GradeBook::displayMessage()
	{
		std::cout << "Welcome to the grade book for\n" << getCourseName() << "!"
			<< "\nThis course is presented by: " << getTeacherName() << ".\n";
	}
	void GradeBook::determineClassAverage()
	{
		int sum = 0, count = 0, grade;
		double average;
		std::cout << "Enter grade or -1 to quit: ";
		std::cin >> grade;
		
		while (grade != -1)
		{
			sum += grade;
			count++;
			std::cout << "Enter grade or -1 to quit: ";
			std::cin >> grade;
		}

		if (count != 0)
		{
			average = static_cast<double> (sum) / count;

			std::cout << "\nTotal of " << count << " grades is: " << sum
				<< "\nClass average is: " << std::setprecision(2) <<
				std::fixed << average << std::endl;
		}
		else std::cout << "No grades were entered.\n";
	}
	void GradeBook::inputGrades()
	{
		int grade1;
		int grade2;
		int grade3;

		std::cout << "Enter three integer grades: ";
		std::cin >> grade1 >> grade2 >> grade3;
		maximumGrade = maximum(grade1, grade2, grade3);
	}
	void GradeBook::displayGradeReport()
	{
		std::cout << "Maximum of grades entered: " << maximumGrade << std::endl;
	}
	int GradeBook::maximum(int x, int y, int z)
	{
		int maxVal = x;
		if (y > maxVal) maxVal = y;
		if (z > maxVal) maxVal = z;
		return maxVal;
	}

	void GradeBook::processGrades()
	{
		outputGrades();

		std::cout << "Lowest grade is " << getMinimum()
			<< "\nHighest grade is " << getMaximum() << std::endl;

		outputBarChart();
	}
	int GradeBook::getMinimum()
	{
		int lowGrade = 100;

		for (int student = 0; student < students; student++)
			for (int test = 0; test < tests; test++)
			{
				if (grades[student][test] < lowGrade)
					lowGrade = grades[student][test];
			}
		return lowGrade;
	}
	int GradeBook::getMaximum()
	{
		int highGrade = 0;

		for (int student = 0; student < students; student++)
			for (int test = 0; test < tests; test++)
			{
				if (grades[student][test] > highGrade)
					highGrade = grades[student][test];
			}
		return highGrade;
	}
	double GradeBook::getAverage(const int setOfGrades[], const int grades)
	{
		int total = 0;

		for (size_t grade = 0; grade < grades; grade++)
			total += setOfGrades[grade];

		return static_cast<double> (total) / grades;
	}
	void GradeBook::outputBarChart()
	{
		std::cout << "\nOverall grade distribution:\n";

		const int frequencySize = 11;
		int frequency[frequencySize] = { 0 };

		for (size_t student = 0; student < students; student++)
			for (size_t test = 0; test < tests; test++)
				++frequency[grades[student][test] / 10];


		for (size_t count = 0; count < frequencySize; count++)
		{
			if (count == 0) std::cout << " 0-9: ";
			else if (count == 10) std::cout << " 100: ";
			else
				std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";

			for (size_t stars = 0; stars < frequency[count]; stars++)
				std::cout << '*';

			std::cout << std::endl;
		}
	}
	void GradeBook::outputGrades()
	{
		std::cout << "\nThe grades are:\n\n";
		std::cout << "             ";
		for (size_t test = 0; test < tests; test++)
			std::cout << "Test " << test + 1 << " ";

		std::cout << "Average" << std::endl;

		for (int student = 0; student < students; student++)
		{
			std::cout << "Student " << std::setw(2) << student + 1;

			for (int test = 0; test < tests; test++)
				std::cout << std::setw(8) << grades[student][test];

			double average = getAverage(grades[student], tests);
			std::cout << std::setw(9) << std::setprecision(2) << std::fixed << average << std::endl;
		}
	}

	//Time
	Time::Time(int hr, int min, int sec)
	{
		setTime(hr, min, sec);
	}

	Time& Time::setTime(int h, int m, int s)
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
		return *this;
	}
	Time& Time::setHour(int h)
	{
		hour = (h >= 0 && h < 24) ? h : 0;
		return *this;
	}
	Time& Time::setMinute(int m)
	{
		minute = (m >= 0 && m < 60) ? m : 0;
		return *this;
	}
	Time& Time::setSecond(int s)
	{
		second = (s >= 0 && s < 60) ? s : 0;
		return *this;
	}

	int Time::getHour() const
	{
		return hour;
	}
	int Time::getMinute() const
	{
		return minute;
	}
	int Time::getSecond() const
	{
		return second;
	}
	
	void Time::printUniversal() const
	{
		std::cout << std::setfill('0') << std::setw(2) << hour << ":"
			<< std::setw(2) << minute << ":" << std::setw(2) << second << std::endl;
	}
	void Time::printStandart() const
	{
		std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
			<< std::setfill('0') << std::setw(2) << minute << ":" << std::setw(2)
			<< second << (hour < 12 ? " AM" : " PM");
	}

	//SalesPerson
	SalesPerson::SalesPerson()
	{
		for (size_t i = 0; i < 12; i++)
		{
			sales[i] = 0.0;
		}
	}
	void SalesPerson::getSalesFromUser()
	{
		double salesFigure;
		for (size_t i = 1; i <= 12; i++)
		{
			std::cout << "Enter sales amount for month " << i << ": ";
			std::cin >> salesFigure;
			setSales(i, salesFigure);
		}
	}
	void SalesPerson::setSales(int month, double amount)
	{
		if (month >= 1 && month <= 12 && amount > 0)
			sales[month - 1] = amount;
		else
			std::cout << "Invalid month or sales figure" << std::endl;
	}
	void SalesPerson::printAnnualSales()
	{
		std::cout << std::setprecision(2) << std::fixed
			<< "\nThe total annual sales are: $"
			<< totalAnnualSales() << std::endl;
	}
	double SalesPerson::totalAnnualSales()
	{
		double total = 0.0;
		for (size_t i = 0; i < 12; i++)
			total += sales[i];

		return total;
	}
	
	//Date
	Date::Date(int mn, int dy, int yr)
	{
		if (mn > 0 && mn <= 12)
			month = mn;
		else
		{
			month = 1;
			std::cout << "Invalid month (" << mn << ") set to 1.\n";
		}

		year = yr;
		day = checkDay(dy);

		std::cout << "Date object constructor for date ";
		print();
		std::cout << std::endl;
	}
	void Date::print() const
	{
		std::cout << month << '/' << day << '/' << year;
	}
	Date::~Date()
	{
		std::cout << "Date object destructor for date ";
		print();
		std::cout << std::endl;
	}
	int Date::checkDay(int testDay) const
	{
		static const int daysPerMonth[] =
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (testDay > 0 && testDay <= daysPerMonth[month])
			return testDay;
		if (month == 2 && testDay == 29 && 
			(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
			return testDay;
		std::cout << "Invalid day (" << testDay << ") set to 1.\n";
		return 1;
	}
	
	//Employee
	int Employee::count = 0;
	int Employee::getCount()
	{
		return count;
	}

	Employee::Employee(const char* const first, const char* const last)
	{
		firstName = new char[strlen(first) + 1];
		strcpy(firstName, first);

		lastName = new char[strlen(last) + 1];
		strcpy(lastName, last);

		count++;

		std::cout << "Employee object constructor: " << firstName << ' ' << lastName << " called." << std::endl;
	}
	void Employee::print() const
	{
		std::cout << lastName << ", " << firstName << " Hired: ";
		hireDate.print();
		std::cout << " Birthday: ";
		birthDate.print();
		std::cout << std::endl;
	}
	Employee::~Employee()
	{
		std::cout << "~Employee() called for "
			<< lastName << ", " << firstName << std::endl;
		delete[] firstName;
		delete[] lastName;
		count--;
	}
	const char* Employee::getFirstName() const
	{
		return firstName;
	}
	const char* Employee::getLastName() const
	{
		return lastName;
	}

	//Array
	Array::Array(int arraySize)
	{
		size = (arraySize > 0 ? arraySize : 10);
		ptr = new int[size];
		for (size_t i = 0; i < size; i++)
			ptr[i] = 0;
	}
	Array::Array(const Array& arrayToCopy)
		:size(arrayToCopy.size)
	{
		ptr = new int[size];
		for (size_t i = 0; i < size; i++)
			ptr[i] = arrayToCopy.ptr[i];
	}
	Array::~Array()
	{
		delete[]ptr;
	}
	int Array::getSize() const
	{
		return size;
	}
	const Array& Array::operator=(const Array& right)
	{
		if (&right != this)
		{
			if (size != right.size)
			{
				delete[]ptr;
				size = right.size;
				ptr = new int[size];
			}
			for (size_t i = 0; i < size; i++)
				ptr[i] = right.ptr[i];
		}
		return *this;
	}
	bool Array::operator==(const Array& right) const
	{
		if (size != right.size)
			return false;

		for (size_t i = 0; i < size; i++)
			if (ptr[i] != right.ptr[i])
				return false;

		return true;
	}
	int& Array::operator[](int subscript)
	{
		if (subscript < 0 || subscript >= size)
		{
			std::cerr << "\nError: Subscript " << subscript
				<< " out of range" << std::endl;
			exit(1);
		}
		return ptr[subscript];
	}
	int Array::operator[](int subscript) const
	{
		if (subscript < 0 || subscript >= size)
		{
			std::cerr << "\nError: Subscript " << subscript
				<< " out of range" << std::endl;
			exit(1);
		}
		return ptr[subscript];
	}
	std::istream& operator>>(std::istream& input, Array& a)
	{
		for (size_t i = 0; i < a.size; i++)
			input >> a.ptr[i];
		
		return input;
	}
	std::ostream& operator<<(std::ostream& output, const Array& a)
	{
		size_t i;
		for (i = 0; i < a.size; i++)
		{
			output << std::setw(12) << a.ptr[i];
			if ((i + 1) % 4 == 0)
				output << std::endl;
		}
		if (i % 4 != 0)
			output << std::endl;

		return output;
	}
	
	//Srting
	String::String(const char* s)
		: length((s!= 0) ? strlen(s) : 0)
	{
		std::cout << "Conversion (and default) constructor: " << s << std::endl;
		setString(s);
	}
	String::String(const String& copy)
		: length(copy.length)
	{
		std::cout << "Copy constructor: " << copy.sPtr << std::endl;
		setString(copy.sPtr);
	}
	String::~String()
	{
		std::cout << "Destructor: " << sPtr << std::endl;
		delete[]sPtr;
	}
	const String& String::operator=(const String& right)
	{
		std::cout << "operator= called" << std::endl;
		if (&right != this)
		{
			delete[] sPtr;
			length = right.length;
			setString(right.sPtr);
		}
		else
			std::cout << "Attempted assignment of a String to itself" << std::endl;

		return *this;
	}
	const String& String::operator+=(const String& right)
	{
		size_t newLength = length + right.length;
		char* tempPtr = new char[newLength + 1];

		strcpy(tempPtr, sPtr);
		strcpy(tempPtr + length, right.sPtr);

		delete[] sPtr;
		sPtr = tempPtr;
		length = newLength;
		return *this;
	}
	bool String::operator!() const
	{
		return length == 0;
	}
	bool String::operator==(const String& right) const
	{
		return strcmp(sPtr, right.sPtr) == 0;
	}
	bool String::operator<(const String& right) const
	{
		return strcmp(sPtr, right.sPtr) < 0;
	}
	char& String::operator[](int subscript)
	{
		if (subscript < 0 || subscript >= length)
		{
			std::cerr << "Error: Subscript " << subscript
				<< " out of range" << std::endl;
			exit(1);
		}
		return sPtr[subscript];
	}
	char String::operator[](int subscript) const
	{
		if (subscript < 0 || subscript >= length)
		{
			std::cerr << "Error: Subscript " << subscript
				<< " out of range" << std::endl;
			exit(1);
		}
		return sPtr[subscript];
	}
	String String::operator()(int index, int subLength) const
	{
		if (index < 0 || index >= length || subLength < 0)
			return "";

		int len;

		if ((subLength == 0) || (index + subLength > length))
			len = length - index;
		else
			len = subLength;

		char* tempPtr = new char[len + 1];
		strncpy(tempPtr, &sPtr[index], len);
		tempPtr[len] = '\0';

		String tempString(tempPtr);
		delete[] tempPtr;
		return tempString;
	}
	void String::setString(const char* string2)
	{
		sPtr = new char[length + 1];
		if (string2 != 0)
			strcpy(sPtr, string2);
		else
			sPtr[0] = '\0';
	}
	std::ostream& operator<<(std::ostream& output, const String& s)
	{
		output << s.sPtr;
		return output;
	}
	std::istream& operator>>(std::istream& input, String& s)
	{
		char temp[100];
		input >> std::setw(100) >> temp;
		s = temp;
		return input;
	}
