#include "SingletonDemo.h"
#include "SingletonPointerDemo.h"
#include <thread>

int main()
{
	std::thread t1([]() {
		SingletonDemo& d1 = SingletonDemo::GetInstance();
		d1.Print();
		});
	
	std::thread t2([]() {
		SingletonDemo& d2 = SingletonDemo::GetInstance();
		d2.Print();
		});
	
	t1.join();
	t2.join();

	std::cout << "=======================================" << std::endl << std::endl;


	std::thread t3([]() {
		SingletonPointerDemo& d3 = SingletonPointerDemo::GetInstance();
		d3.Print();
		});

	std::thread t4([]() {
		SingletonPointerDemo& d4 = SingletonPointerDemo::GetInstance();
		d4.Print();
		});

	t3.join();
	t4.join();
}