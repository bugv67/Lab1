#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ./part1
int addr5;
int addr6;

int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();
char g = 'g';
void foo2();

int secondary(int x)
{
    int addr2;
    int addr3;
    char *yos = "ree";
    int *addr4 = (int *)(malloc(50));
    int iarray[3]; // size 2 or 3 ???
    float farray[3];
    double darray[3];
    char carray[3];
    int iarray2[] = {1, 2, 3};
    char carray2[] = {'a', 'b', 'c'};
    int *iarray2Ptr;
    char *carray2Ptr;
    // long x=2345335345;

    printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
    printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);

    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long)(&foo2 - &foo1));

    printf("Arrays Mem Layout (T1b):\n");

    //////////////////* task 1 b here *//////////////////////////////
    // arrrays size 2 or 3 ??? doesnt matter
    // whats hexadecimal - address
    // %p or %ld for addresses?
    // 0x7ffcc8c9e5b0 + 4 = bits or byts??
    printf("\n int  \n");                         // 4 byts
    printf("Print iarray: %p\n", iarray);         // 0xff82e814
    printf("Print iarray+1: %p\n", iarray + 1);   // 0xff82e818
    printf("Print &iarray: %p\n", &iarray);       // 0xff82e814
    printf("Print &iarray+1: %p\n", &iarray + 1); // 0xff82e818
    printf("Print &iarray[0]: %p\n", &iarray[0]);
    printf("Print &iarray[1]: %p\n", &iarray[1]);

    printf("\n float \n");                      // 4 byts
    printf("Print farray: %p\n", farray);       // 0xff82e820
    printf("Print farray+1: %p\n", farray + 1); // 0xff82e824
    printf("Print &farray[0]: %p\n", &farray[0]);
    printf("Print &farray[1]: %p\n", &farray[1]);

    printf("\n double \n ");                    // 8 byts
    printf("Print darray: %p\n", darray);       // 0xff82e838
    printf("Print darray+1: %p\n", darray + 1); // 0xff82e840
    printf("Print &darray[0]: %p\n", &darray[0]);
    printf("Print &darray[1]: %p\n", &darray[1]);

    printf("\n char \n");                       // 1 byts
    printf("Print carray: %p\n", carray);       // 0xff82e856
    printf("Print carray+1: %p\n", carray + 1); // 0xff82e857
    printf("Print &carray[0]: %p\n", &carray[0]);
    printf("Print &carray[1]: %p\n", &carray[1]);

    printf("\n Pointers and arrays (T1d): ");

    ///////////////////// task 1 d here ///////////////////////////////
    iarray2Ptr = iarray2;
    carray2Ptr = carray2;
    for (; iarray2Ptr < &iarray2 + 1; iarray2Ptr++)
    {
        printf("- iarray2Ptr: %d\n", *iarray2Ptr);
    }
    for (; carray2Ptr < &carray2 + 1; carray2Ptr++)
    {
        printf("- carray2Ptr: %d\n", *carray2Ptr);
    }
}

int main(int argc, char **argv)
{
    /////////////////////// part of task 1 a here- zu big size/////////////////////

    printf("Print long type size:  %ld\n", sizeof(long)); // 4 byts
    printf("Size of adress:  %ld\n", sizeof(long *));     // 4 byts
    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);

    secondary(0);

    printf("Command line arg addresses (T1e):\n");
    ///////////////////task 1 e here/////////////////////////////

    return 0;
}

/////////////////////////// T1c //////////////////////////////
void point_at(void *p) // p is the address of addr5
{
    int local;
    static int addr0 = 2;
    static int addr1;

    long dist1 = (size_t)&addr6 - (size_t)p; // global=stack , small distance
    long dist2 = (size_t)&local - (size_t)p; // local= stack, very bigg distance - overflow so it is negative
    long dist3 = (size_t)&foo - (size_t)p;   // txt= stack, BSS, negetive small

    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);

    printf("Check long type mem size (T1a):\n");
    ////////////////////////// part of task 1 a here ////////////////////////////////////
    printf("Print long type size:  %ld\n", sizeof(long)); // 4 byts
    printf("Size of adress:  %ld\n", sizeof(long *));     // 4 byts

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}