#include <iostream>
#include <string>
#include <ctime>



class Base
{
public:
	virtual ~Base() { };
};

class A : public Base
{
public:
	~A() { };
};

class B : public Base
{
public:
	~B() { };
};

class C : public Base
{
public:
	~C() { };
};

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int	i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Generate A" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "Generate B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Generate C" << std::endl;
		return (new C());
	}
}


void identify(Base* p)
{
	A	*ptrA = dynamic_cast<A *>(p);
	if (ptrA == NULL)
	{
		B	*ptrB = dynamic_cast<B *>(p);
		if (ptrB == NULL)
		{
			std::cout << "C" << std::endl;
			return;
		}
		else
		{
			std::cout << "B" << std::endl;
			return;
		}
	}
	else
		std::cout << "A" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&refA = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)refA;
	}
	catch(std::bad_cast)
	{
		try
		{
			B	&refB = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)refB;
		}
		catch(std::bad_cast)
		{
			std::cout << "C" << std::endl;
		}
	}
}

int main()
{

	Base	*ptr = generate();
	Base	&ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
}