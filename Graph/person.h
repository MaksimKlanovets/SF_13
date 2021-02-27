#pragma once
#include <string>
#include "Id.h"
using namespace std;
class Person
{
public:

	Person();

	Person(
		string name
		);

	string getName();

	int getId();

	void setName(
		string name
		);

private:
	string _name;
	int _id;
};

