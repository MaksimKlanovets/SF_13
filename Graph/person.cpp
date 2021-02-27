#include "person.h"

Person::Person()
{
	_name = {};
}

Person::Person(string name) :_name(name), _id(Id::getId())
{
	Id::increaseId();
}


string Person::getName()
{
	return _name;
}

int Person::getId()
{
	return _id;
}

void Person::setName(string name)
{
	
	_name = name;
}


