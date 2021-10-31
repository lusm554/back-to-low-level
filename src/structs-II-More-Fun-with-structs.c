#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Initializers of Nested structs and Arrays */
void InitializersOfNestedStructsAndArrays(void) {
  struct cabin_information {
    int window_count;
    int o2level;
  };

  struct spaceship {
    char *manufacturer;
    struct cabin_information ci; 
  };

  struct spaceship s = {
    .manufacturer = "General Products",
    .ci.window_count = 8, // <-- NESTED INITIALIZER!
    .ci.o2level = 21,
  };

  struct spaceship ss = {
    .manufacturer = "General Products",
    .ci = {
      .window_count = 8,
      .o2level = 21,
    }
  };

  printf("%s: %d seats, %d%% oxygen\n",
    s.manufacturer, s.ci.window_count, s.ci.o2level);

  printf("%s: %d seats, %d%% oxygen\n",
    ss.manufacturer, ss.ci.window_count, ss.ci.o2level);
  
  // With array
  struct passenger {
    char *name;
    int covid_vaccinated; // Bool
  };
  
  #define MAX_PASSENGERS 8

  struct spaceship2 {
    char *manufacturer;
    struct passenger passenger[MAX_PASSENGERS];   
  };

  struct spaceship2 s2 = {
    .manufacturer = "General Products",
    .passenger = {
      // Initialize a filed at a time
      [0].name = "Gridley, Lewis",       
      [0].covid_vaccinated = 0,

      // Or all at once
      [7] = {.name = "Brown, Teela", .covid_vaccinated = 1},
    } 
  };

  printf("Passangers for %s ship:\n", s2.manufacturer);

  for (int i = 0; i < MAX_PASSENGERS; i++)
    if (s2.passenger[i].name != NULL)
      printf("    %s (%svaccinated)\n",
        s2.passenger[i].name,
        s2.passenger[i].covid_vaccinated ? "" : "not ");
}

void AnonymousStructs(void) {
  struct {
    char *name;
    int leg_count, speed;
  } a, b, c;

  a.name = "antelope";
  c.leg_count = 4;
  b.speed = 50;

  // But that’s still not that useful.
  
  typedef struct {
    char *name;
    int leg_count, speed;
  } animal;

  animal d, e;
  d.name = "antelope";
  e.leg_count = 4;
}

void SelfReferentialStructs(void) {
  struct node {
    int data;
    struct node *next;
  };

  struct node *head;
  
  // set up a linked list (11)->(22)->(33)
  head =  malloc(sizeof(struct node));
  head->data = 11;
  head->next = malloc(sizeof(struct node));
  head->next->data = 22;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 33;
  head->next->next->next = NULL;

  // traverse it
  for (struct node *cur = head; cur != NULL; cur = cur->next)
    printf("%d\n", cur->data);
}

void FlexibleArrayMembers(void) {
  // Again, this only works if the flexible array member is the last field in the struct.
  struct len_string {
    int length;
    char data[];
  };

	/* ?????
	struct len_string *len_string_from_c_string(char *s)
	{
    int len = strlen(s);

    // Allocate "len" more bytes than we'd normally need
    struct len_string *ls = malloc(sizeof *ls + len);

    ls->length = len;

    // Copy the string into those extra bytes
    memcpy(ls->data, s, len);

    return ls;
	}
	*/
}

void PaddingBytes(void) {
  struct foo {
    int a;
    char b;
    int c;
    char d;
  };
  
  printf("\nSizeof sum of types and struct foo:\n");
  printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char)); // 10 on my system
  printf("%zu\n", sizeof(struct foo)); // 16 on my system
}

void FunWithOffsetof(void) {
   struct foo {
    int a;
    char b;
    int c;
    char d;
  };  

  printf("\nOffsets of the individual fields in the struct:\n");
  printf("%zu\n", offsetof(struct foo, a)); // 0
  printf("%zu\n", offsetof(struct foo, b)); // 4
  printf("%zu\n", offsetof(struct foo, c)); // 8
  printf("%zu\n", offsetof(struct foo, d)); // 12 

  // Indicating that we’re using 4 bytes for each of the fields.
  // The compiler is putting 3 padding bytes after each char so that all the fields are 4 bytes long.
  // Presumably this will run faster on my CPU.
}

struct parent {
  int a, b;
};

struct child {
  struct parent super; // MUST be first
  int c, d;
};

void print_child(struct child *self);
void print_parent(void *p);

void FakeOOP(void) {
  struct child c = {.super.a = 1, .super.b = 2, .c = 3, .d = 4};
  
  print_child(&c);
  print_parent(&c);
}

void BitFields(void) {
  struct foo {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
  }; 
  
  printf("%zu\n", sizeof(struct foo)); // 16 on my system

  // Speficy the maximum number of bits that values cat take
  struct foo2 {
    unsigned int a:5;
    unsigned int b:5;
    unsigned int c:3;
    unsigned int d:3;
  };

  printf("%zu\n", sizeof(struct foo)); // 16 on my system
  // Put all your bitfields together to get the compiler to combine them.

  // Unnamed Bit-Fields
	struct foo3 {
		unsigned char a:2;
		unsigned char :5;   // <-- unnamed bit-field!
		unsigned char b:1;
	};
}

void Unions(void) {
  // It’s a way to reuse the same memory space for different types of data.
  union foo {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
  };

  union foo x;

  printf("\nUnion:\n");

  x.a = 12;
  printf("%d\n", x.a); // ok -- x.a was the last thing we stored inoto

  x.g = 3.14;
  printf("%f\n", x.g); // ok -- x.g was the last thing we stored into

  printf("%d\n", x.a); // Unspecified behavior!

  // Pointers to unions
  union foo y;
  
  int *foo_int_p = (int *)&y;
  int *foo_float_p = (float *)&y;

  y.a = 12;
  printf("%d\n", y.a); // 12
  printf("%d\n", *foo_int_p); // 12, again

  x.g = 3.14;
  printf("%f\n", x.g); // 3.14
  printf("%f\n", *foo_float_p); // 3.15, again
}

int main(void) {
  InitializersOfNestedStructsAndArrays();
  AnonymousStructs();
  SelfReferentialStructs();
  FlexibleArrayMembers();
	PaddingBytes();
  FunWithOffsetof();
  FakeOOP();
  BitFields();
  Unions();
  return 0;
}

// Fake OOP functions

// Making the argument 'void*' so we can pass any type into it
// (namely a struct parent or struct child)
void print_parent(void *p) {
  // Expects a struct prent--but a struct child will also work
  // because the pointer points to the struct parent in the first
  // field:
  struct parent *self = p;
  
  printf("Parent: %d, %d\n", self->a, self->b);
}

void print_child(struct child *self) {
  printf("Child: %d, %d\n", self->c, self->d);
}

