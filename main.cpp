#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

static float rand_coord() {
    return (float)rand() / RAND_MAX * 100.0f; // this is 0.0 to 100.0
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <number of coordinates>\n";
        return 1;
    }

    int count = atoi(argv[1]);
    if (count < 1) {
        cerr << "Please enter a positive number of coords.\n";
        return 1;
    }

    srand((unsigned)time(NULL));

    // First node
    Coordinate *begin = new Coordinate;
    begin->x = rand_coord();
    begin->y = rand_coord();
    begin->coord_id = 1;
    begin->next = NULL;
    begin->previous = NULL;
    Coordinate *end = begin;

    // Remaining nodes
    for (int i = 1; i < count; i++) {
        add_coordinate(end, rand_coord(), rand_coord());
        end = end->next;
    }

    cout << "List length: " << list_length(begin) << "\n\n";

    cout << "Forward:\n";
    forward_display(begin);
    cout << "\nBackward:\n";
    backward_display(end);

    cout << "\n";
    closest_to(begin, 50.0f, 50.0f);

    // Delete a coord
    int to_delete = (count >= 2) ? 2 : 1;
    cout << "\nDeleting ID " << to_delete << "\n";
    delete_coordinate(begin, to_delete);

    // Find end node if changed
    end = begin;
    while (end->next != NULL) { end = end->next; }

    cout << "List length: " << list_length(begin) << "\n";
    forward_display(begin);

    cout << "\n";
    closest_to(begin, 25.0f, 75.0f);

    // Free all
    while (begin != NULL) {
        Coordinate *next = begin->next;
        delete begin;
        begin = next;
    }
    return 0;
}
