/* Header info for vector.c. The Vector struct contains the data necessary; but
   since C is not object-oriented, the traditional "methods" that you're
   accustomed to are instead functions that take a pointer to that struct as a
   parameter. */

struct Vector
{
    // A pointer to a standard C int array to hold data
    int *array;

    // The size of the actual C array that you have allocated, expressed
    // in terms of the number of int-sized slots allocated for the array.
    int memorySize;

    // The virtual size of the vector, i.e., how many integers are currently
    // in it from the user's perspective.
    int size;
};

/* Typing "struct Vector" all the time is cumbersome; this sets it up so you can
 just type "Vector" instead. */

typedef struct Vector Vector;

/* Function prototypes. */

/* Take an already existing Vector as a parameter. (Do not create a Vector struct
 inside this function.) Set its internal memory size to match the value given in
 the parameter, allocate an appropriately sized C array to hold the actual data,
 initialize the Vector's array variable to point to this array, and initialize 
 the Vector's size variable to 0. */

void init(Vector *vector, int memorySize);


/* Print out the Vector for debugging purposes. */

void print(Vector *vector);


/* Insert value at location inside the Vector. If the list has items in
 positions 0 through n-1, you are only permitted to insert new values at
 locations 0 through n. (This is identical to Java's ArrayList behavior.) If
 there is already data at array[location], insert() slides the rest of the data 
 down one position to make room for the new value. Return 1 for success, otherwise 0
 if the location is invalid (less than 0, or greater than the vector size). Inserting 
 at the very end of the current data (at position equal to size) is fine. All 
 inserts should increase size by 1.

 If the internal array is too small to fit a new value, a new array of twice the
 size is created with malloc. The values are copied, the Vector is appropriately
 updated, and the old array is freed.) */

int insert(Vector *vector, int location, int value);


/* Obtains value at location inside the Vector. Return 1 for success, otherwise 
 0 if the location is invalid (less than 0, or greater than or equal to the
 size). The value itself is passed on through the parameter value. */

int get(Vector *vector, int location, int *value);


/* Removes the array associated with the Vector. */

void cleanup(Vector *vector);


/* Deletes value at location inside the Vector.  Return 1 for success, otherwise 
 0 if the location is invalid (less than 0, or greater than or equal to the
 size). When an item is deleted, everything else past it in the array should be
 slid down. The internal array itself does not need to be compressed, i.e., you
 don't need to halve it in size if it becomes half full, or anything like
 that. */

int delete(Vector *vector, int location);
