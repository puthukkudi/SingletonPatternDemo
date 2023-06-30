#include "SingletonDemo.h"

int SingletonDemo::counter;
SingletonDemo SingletonDemo::mInstance;

SingletonDemo::SingletonDemo()
{
	counter++;
	std::cout << "Total instance created : " << counter << std::endl;
}


SingletonDemo& SingletonDemo::GetInstance()
{
	return mInstance;
}

SingletonDemo::~SingletonDemo()
{
	counter--;
	std::cout << "SingletonDemo destroyed :  refCount" << counter << std::endl;
}

void SingletonDemo::Print()
{
	std::cout << "Hi object : " << this<<std::endl;
}