# Assignment6_NaySanHtut

## Files
- `coordinate.h`: the `Coordinate` struct, the `Coordinate` typedef, and the function declarations
- `coordinate.cpp`: the doubly-linked list functions (`add_coordinate`, `forward_display`, `backward_display`, `delete_coordinate`, `list_length`, `closest_to`)
- `main.cpp`: the main program that builds a random list and calls each function

## How to Compile
```bash
g++ -std=c++11 -Wall -o main main.cpp coordinate.cpp
```

## How to Run
```bash
./main 10
```
The number is how many random x-y coordinates to create (use any positive number). The program prints to the screen and does not create a file. In order, it prints:

1. The list length
2. The list forward, then backward
3. The coordinate closest to (50, 50) and its distance
4. A message that ID 2 is being deleted, then the shorter list
5. The coordinate closest to (25, 75) and its distance

## How to Check the Output
Run the program and look at the screen:
```bash
./main 10
```
The forward and backward lists should show the same 10 coordinates in opposite order, with IDs 1 through 10. After the delete, the list length should be 9 and ID 2 should be gone.

To count the coordinate lines:
```bash
./main 10 | grep -c "^ID"
```
It should print `29` (10 forward + 10 backward + 9 after the delete).

## Troubleshooting
- `No such file or directory` when compiling: you are in the wrong folder. Use `cd` to move into the project folder.
- `g++: command not found`: the compiler is not installed on that machine.
- `coordinate.h: No such file or directory`: `coordinate.h` is not in the same folder as the `.cpp` files.
- `undefined reference to 'add_coordinate'` (or another list function): `coordinate.cpp` was left out of the compile command.
- `Usage: ./main <number of coordinates>`: you ran the program without a number. Run `./main 10`.
- `Please enter a positive number of coordinates.`: the number must be 1 or greater.
- The program hangs or crashes: check the loop in `main()` that finds the end of the list after the delete. It must say `end = end->next;`.
- Two runs print the same numbers: the random generator is seeded with the clock, so runs started in the same second match. Wait a moment and run again.
