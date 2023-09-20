#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->capacity = 0;
	ps->top = 0;
	ps->a = NULL;
}

void StackDistory(ST* ps)
{
	assert(ps);

	ps->capacity = 0;
	ps->top = 0;
	free(ps->a);
	ps->a = NULL;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		assert(tmp);

		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top++] = x;

}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top-1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
