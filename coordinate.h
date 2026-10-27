#ifndef COORDINATE_H
#define COORDINATE_H

struct _coordinate {
    float x;
    float y;
    int coord_id;
    struct _coordinate *next;
    struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;

void add_coordinate(Coordinate *list_end, float x, float y); // adds a coordinate to the end of the linked list
void forward_display(Coordinate *list_beginning); // displays all coordinates from beginning to end
void backward_display(Coordinate *list_end); // displays all coordinates from end to beginning
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete); // removes a coordinate from the linked list (free memory!)
int list_length(Coordinate *list_beginning); // return the length of the list
void closest_to(Coordinate *list_beginning, float x, float y); // find the coordinate that is closest to the given x, y and output the distance between the 2

#endif
