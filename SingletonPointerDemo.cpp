#include "SingletonPointerDemo.h"

int SingletonPointerDemo::counter;
std::mutex SingletonPointerDemo::mtx;
SingletonPointerDemo* SingletonPointerDemo::mInstance = nullptr;

SingletonPointerDemo::SingletonPointerDemo()
{
	counter++;
	std::cout << "Total instance created : " << counter << std::endl;
}


SingletonPointerDemo& SingletonPointerDemo::GetInstance()
{
	/* 
	* double check lock ; to make sure that lock is made only once
	* As once instance is make lock is not needed
	*/
	if (mInstance == nullptr) // double check
	{
		// lock using mutext is set to ensure thread safety
		std::lock_guard<std::mutex> _lock(mtx);
		//mtx.lock();
		if (mInstance == nullptr)
		{
			mInstance = new SingletonPointerDemo();
		}
		//mtx.unlock();
	}	
	return *mInstance;
}

SingletonPointerDemo::~SingletonPointerDemo()
{
	delete mInstance;
	counter--;
	std::cout << "SingletonPointerDemo destroyed :  refCount" << counter << std::endl;
}

void SingletonPointerDemo::Print()
{
	std::cout << "Hi object : " << this << std::endl;
}