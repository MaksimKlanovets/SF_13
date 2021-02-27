#include "Id.h"

int Id::_id = 0;

int Id::getId()
{
	return _id;
}

void Id::increaseId()
{
	_id++;
}

void Id::decreaseId()
{
	_id--;
}
