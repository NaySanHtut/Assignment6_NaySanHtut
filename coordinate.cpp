#include <iostream>
#include <cmath>
#include "coordinate.h"

using namespace std;

void add_coordinate(Coordinate *list_end, float x, float y) {
    if (list_end == NULL) { return; }

    Coordinate *begin = list_end;
    while (begin->previous != NULL) { begin = begin->previous;}

    Coordinate *node = new Coordinate;
    node->x = x;
    node->y = y;
    node->coord_id = list_length(begin) + 1;
    node->next = NULL;
    node->previous = list_end;
    list_end->next = node;
}

void forward_display(Coordinate *list_beginning) { // ID 123: (x, y)
    for (Coordinate *c = list_beginning; c != NULL; c = c->next) {
        cout << "ID " << c->coord_id << ": (" << c->x << ", " << c->y << ")\n";
    }
}

void backward_display(Coordinate *list_end) {
    for (Coordinate *c = list_end; c != NULL; c = c->previous) {
        cout << "ID " << c->coord_id << ": (" << c->x << ", " << c->y << ")\n";
    }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate *c = list_beginning;
    while (c != NULL && c->coord_id != coord_id_to_delete) { c = c->next; }

    if (c == NULL) { // Coordinate ID 123 not found.
        cout << "Coordinate ID " << coord_id_to_delete << " not found.\n";
        return;
    }

    if (c == list_beginning) {
        Coordinate *second = c->next;
        
        if (second == NULL) {
            cout << "Can't delete the only node in the list.\n";
            return;
        }

        c->x = second->x;
        c->y = second->y;
        c->coord_id = second->coord_id;
        c->next = second->next;
        if (second->next != NULL) { second->next->previous = c; }
        delete second;
        return;
    }

    c->previous->next = c->next;
    if (c->next != NULL) { c->next->previous = c->previous; }
    delete c;
}

int list_length(Coordinate *list_beginning) {
    int n = 0;
    for (Coordinate *c = list_beginning; c != NULL; c = c->next) { n++; }
    return n;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    if (list_beginning == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Coordinate *best = list_beginning;
    float best_dist = sqrt((best->x - x) * (best->x - x) + (best->y - y) * (best->y -y));
    
    for (Coordinate *c = list_beginning->next; c != NULL; c = c->next) {
        float d = sqrt((c->x - x) * (c->x - x) + (c->y - y) * (c->y - y));
        if (d < best_dist) {
            best_dist = d;
            best = c;
        }
    }

    cout << "Closest to (" << x << ", " << y << ") is ID " << best->coord_id << " at (" << best->x << ", " << best->y
         << "), distance = " << best_dist << "\n";
}
