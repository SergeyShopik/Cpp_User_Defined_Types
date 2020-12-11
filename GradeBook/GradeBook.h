#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class GradeBook
{
public:
	const static int students = 10;
	const static int tests = 3;

	GradeBook(std::string, const int[][tests]);

	void setCourseName(std::string);
	void setTeacherName(std::string);

	std::string getCourseName();
	std::string getTeacherName();

	void displayMessage();
	void determineClassAverage();
	void inputGrades();
	void displayGradeReport();
	int maximum(int, int, int);

	void processGrades();
	int getMinimum();
	int getMaximum();
	double getAverage(const int [], const int);
	void outputBarChart();
	void outputGrades();

private:
	std::string courseName, teacherName;
	int maximumGrade;
	int grades[students][tests];
};
class Time
{
public:
	Time(int = 0, int = 0, int = 0);

	Time &setTime(int, int, int);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void printUniversal() const;
	void printStandart() const;

private:
	int hour;
	int minute;
	int second;
};
class SalesPerson
{
public:
	SalesPerson();
	void getSalesFromUser();
	void setSales(int, double);
	void printAnnualSales();
private:
	double totalAnnualSales();
	double sales[12];
};
class Date
{
public:
	Date(int = 1, int = 1, int = 1900);
	void print() const;
	~Date();
private:
	int month;
	int day;
	int year;
	int checkDay(int) const;
};
class Employee
{
public:
	Employee(const char* const, const char* const);
	const char* getFirstName() const;
	const char* getLastName() const;
	static int getCount();
	void print() const;
	~Employee();
private:
	char* firstName;
	char* lastName;
	static int count;
	const Date birthDate;
	const Date hireDate;
};
class Array
{
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
public:
	Array(int = 10);
	Array(const Array&);
	~Array();
	int getSize() const;

	const Array& operator=(const Array&);
	bool operator == (const Array&) const;

	bool operator!=(const Array& right) const
	{
		return !(*this == right);
	}
	int& operator[](int);
	int operator[](int) const;
private:
	int size;
	int* ptr;
};
class String
{
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
public:
	String(const char* = "");
	String(const String&);
	~String();

	const String& operator=(const String&);
	const String& operator+=(const String&);

	bool operator!() const;
	bool operator==(const String&) const;
	bool operator<(const String&) const;

	bool operator!=(const String& right) const
	{
		return !(*this == right);
	}
	bool operator>(const String& right) const
	{
		return !(right < *this);
	}
	bool operator<=(const String& right) const
	{
		return !(right < *this);
	}
	bool operator>=(const String& right) const
	{
		return !(*this < right);
	}

	char& operator[](int);
	char operator[](int) const;
	String operator()(int, int = 0) const;
	int getLength() const;
private:
	int length;
	char* sPtr;
	void setString(const char*);
};

#endif