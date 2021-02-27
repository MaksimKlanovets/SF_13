#pragma once
class Id
{
public:
	static int  getId();
	static void increaseId();
	static void decreaseId();

private:
	static int _id;
};

