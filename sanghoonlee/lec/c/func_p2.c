#include <stdio.h>

// int (*)[2] aaa(void)
// return: int(*)[2]
// name: aaa
// parameter: void
int (* aaa(void))[2]
{
	static int a[2][2] = {{10, 20}, {30, 40}};
	printf("aaa called\n");
	return a;
}

// int (*(* bbb(void))(void))[2]

// case 1: criteria: function name
// int (*(*)(void))[2] bbb(void)
// int (*)[2](*)(void) bbb(void)

// case 2: first '(*' last ')~~'
// int (*)[2](* bbb(void))(void)
// int (*)[2](*)(void) bbb(void)

// return: int(*)[2](*)(void)
// name: bbb
// parameter: void

// int (*)[2] aaa(void)
// int (*)[2] (*)(void) bbb(void)
int (*(* bbb(void))(void))[2]
{
	printf("bbb called\n");
	return aaa;
}

int (*(* ccc(void))(void))[2]
{
	printf("ccc called\n");
	return aaa;
}

int (*(* ddd(void))(void))[2]
{
	printf("ddd called\n");
	return aaa;
}

int (*(* eee(void))(void))[2]
{
	printf("eee called\n");
	return aaa;
}

int main(void)
{
	// int (*)[2] ret;
	int (*ret)[2];
	// int (*)[2] (*)(void) bbb(void)
	// int (*)[2] (*)(void) (*)(void) p[][2]
	int (*(*(*p[][2])(void))(void))[2] = {{bbb, ccc}, {ddd, eee}};
	// int (*)[2] (*)(void) (*)(void) [ ][2] p
	// int (*)[2] (*)(void) (*)(void) (*)[2] p1
	int (*(*(*(*p1)[2])(void))(void))[2] = p;
	// int (*)[2] (*)(void) (*)(void) (*)[2] p1
	// ((*(*(*(*p1)[3])))()())
	// (*(*(*(*p1)[3])))()()
	// (*)(*)(*)(*) p1[3] ()() = eee()()
	// eee()() = aaa()
	// ret = address of array a
	ret = ((*(*(*(*p1)[3])))()());
	printf("*ret[0] = %d\n", *ret[0]);		// 10
	printf("ret[0][0] = %d\n", ret[0][0]);	// 10
	printf("*ret[1] = %d\n", *ret[1]);		// 30
	printf("ret[1][1] = %d\n", ret[1][1]);	// 40
	return 0;
}
