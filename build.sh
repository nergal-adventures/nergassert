
# Build asserts
gcc -Iinclude -g -c ./src/nergassert.c -o ./build/nergassert.o 

# Build tests
gcc -Iinclude -g -c ./tests/test.c -o ./build/test.o

# Link them togheter 
gcc -Iinclude -g ./build/test.o ./build/nergassert.o -o ./bin/tests
