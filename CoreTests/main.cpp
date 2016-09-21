/*
 * CoreTests.cpp
 *
 * Created: 8/7/2016 12:22:44 PM
 * Author : Wembly
 */ 

#include <avr/io.h>

#include <stdio.h>
#include <stdlib.h>

class ITest;

void * operator new(size_t size)
{
	return malloc(size);
}

void * operator new[](size_t size)
{
	return malloc(size);
}

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {};

extern "C" void __cxa_pure_virtual(void);
void __cxa_pure_virtual(void) {};

void operator delete(void * ptr)
{
	free(ptr);
}

void operator delete[](void * ptr)
{
	free(ptr);
}

#include "core/collection/FixedArray.h"
#include "core/collection/DynamicArray.h"

using namespace Core::Collection;

class ITestRunner
{
public:

	virtual bool RunTest(ITest* test) = 0;
	virtual bool RunTests(ITest* tests[], int testCount) = 0;
	
	virtual void StartTest(const char* name, int testNo, int testCount) = 0;
	virtual void EndTest(const char* name, int testNo, int testCount, int result) = 0;
	virtual void Log(const char* message, ...) = 0;
};

class ITest
{
public:
	virtual const char* Name() const = 0;
	virtual bool Run(ITestRunner& runner) const = 0;	
};

class TestRunner : public ITestRunner
{
public:
	bool RunTest(ITest* test) override
	{
		StartTest(test->Name(), 1, 1);
		bool r = test->Run(*this);
		EndTest(test->Name(), 1, 1, r);
		
		return r;
	}
	
	bool RunTests(ITest* tests[], int testCount) override
	{
		bool result = true;
		
		for (int i = 0; i < testCount; ++i)
		{
			auto test = tests[i];
			StartTest(test->Name(), i, testCount);
			bool r = test->Run(*this);
			EndTest(test->Name(), i, testCount, r);	
			
			result &= r;
		}
		
		return result;
	}

	void StartTest(const char* name, int testNo, int testCount) override
	{
		Print("%s ", name);
	}
	
	void EndTest(const char* name, int testNo, int testCount, int result) override
	{
		Print("[%s] ", result ? "SUCCESS" : "FAILED");
	}
	
	void Log(const char* message, ...) override
	{
		va_list args;
		va_start (args, message);
		Print("%s\n", message, args);
		va_end (args);
	}
	
private:
	void Print(const char* message, ...)
	{
		char buffer[64];
		va_list args;
		va_start (args, message);
		vsprintf (buffer, message, args);
		printf("%s", buffer);
		va_end (args);
	}
};

class Test : virtual public ITest
{
	const char* mName;
	
public:
	Test(const char* name)
		: mName(name)
	{
		
	}
	
	const char* Name() const
	{
		return mName;
	}
};

template<int T_TestCount>
class TestSuite : public Test
{
	ITest** mTests;
	
public:

	TestSuite(const char* name, ITest* (&tests)[T_TestCount])
		: Test(name)
		, mTests(tests)
	{
	}
	
	bool Run(ITestRunner& runner) const override 
	{
		bool result = true;
		
		for (int i = 0; i < T_TestCount; ++i)
		{
			auto test = mTests[i];
			runner.StartTest(test->Name(), i, T_TestCount);
			bool r = test->Run(runner);
			runner.EndTest(test->Name(), i, T_TestCount, r);
			
			result &= r;
		}
		
		return result; 
	}
};

class TestFixedArray : public Test
{
public:
	TestFixedArray()
	: Test("TestFixedArray")
	{
		
	}
	
	bool Run(ITestRunner& runner) const override
	{
		FixedArray<int, 3> array;
		
		array.Add(1);
		array.Add(2);
		array.Add(4);
		
		int i = 0;
		int results[] { 1, 2, 4 };
		for (auto item : array)
		{
			if(item != results[i++])
				return false;
		}
		
		return true;
	}
};

class TestDynamicArray : public Test
{
	public:
	TestDynamicArray()
	: Test("TestDynamicArray")
	{
	}
	
	bool Run(ITestRunner& runner) const override
	{
		DynamicArray<int, 3, 3> array;
		
		array.Add(1);
		array.Add(2);
		array.Add(4);
		
		if (array.GetCapacity() != 3) return false;
			
		int i = 0;
		int results[] { 1, 2, 4 };
		for (auto item : array)
		{
			if(item != results[i++])
			return false;
		}
		
		array.Add(8);
		
		if (array.GetCapacity() != 6) return false;
		
		array.Add(12);
		
		if (array.GetCapacity() != 6) return false;
		
		array.Add(16);
		
		if (array.GetCapacity() != 6) return false;
		
		i = 0;
		int moreResults[] { 1, 2, 4, 8, 12, 16 };
		for (auto item : array)
		{
			if(item != moreResults[i++])
			return false;
		}
		
		return true;
	}
};

static TestFixedArray sFixedArrayTest;
static TestDynamicArray sDynamicArrayTest;
static ITest* sTests[] = { &sFixedArrayTest, &sDynamicArrayTest };
	
class TestCollections : public TestSuite<sizeof(sTests)/sizeof(ITest*)>
{
public:
		
	TestCollections()
		: TestSuite("TestCollections", sTests)
	{
		
	}
};


int main(void)
{
	auto runner = new TestRunner;
	auto test = new TestCollections;
	
	bool result = runner->RunTest(test);
	
	exit(result);
}
