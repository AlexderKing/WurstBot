#include <stdint.h>
#include <stdlib.h>
#include "node.h"
#include "node_list.h"
#include "map.h"

Map* CreateMap(void) {  
    Map* temp_map = (Map*)malloc(sizeof(Map));
    
    temp_map->max_number = 1;
    temp_map->floor = NULL;
    temp_map->robot_tile = NULL;

    return temp_map;
}

void InitializeRobotTile(Map* _map) {

    Node *n = CreateMapNodeOnPosition( 0, 0);
    InsertNodeIntoFloor(_map, n);

    _map->robot_tile = n;
}

//node* CreateMapNodeOnPosition(Map* _map, int x, int y) { //Why Map is needed?????
//    tile* temp_Tile = CreateMapTile();
//
//    temp_tile->X = x;
//    temp_tile->Y = y;
//    temp_tile->number = -1;
//
//    return CreateNode(standard_tile, temp_tile);
//}

Node* CreateMapNodeOnPosition(int x, int y) {
    Tile* temp_tile = CreateMapTile();

    temp_tile->X = x;
    temp_tile->Y = y;
    temp_tile->number = -1;

    return CreateNode(standard_tile, temp_tile);
}

BOOL_TYPE InsertNodeIntoFloor(Map* _map, Node* _node) {

    if(_map->floor == NULL) {
        _map->floor = CreateNodeList(_node);
        _node->tile->number = _map->max_number++;
        return b_true;
    }

    if(_node->tile->Y < _map->floor->currentIndex) {
        // Create new first pool
        node_list* temp_list = CreateNodeList(_node);
        temp_list->next = _map->floor;
        _map->floor = temp_list;
        _node->tile->number = _map->max_number++;
        return b_true;
    }

    node_list* current_row = _map->floor;
    node_list* previous_row = NULL;

    while(_node->tile->Y != current_row->currentIndex) {

        if(current_row->next == NULL) {
            current_row->next = CreateNodeList(_node);
            _node->tile->number = _map->max_number++;
            return b_true;
        }

        previous_row = current_row;
        current_row = current_row->next;

    }

    BOOL_TYPE return_value = b_false;

    node_list_element *inserted = InsertNodeIntoList(current_row, _node);
    if (inserted->node->tile->number == -1) {
        _node->tile->number = _map->max_number++;
        return_value = b_true;
    }
    
    if (previous_row != NULL) {
        previous_row->next = current_row;
    } else {
        _map->floor = current_row;
    }
    return return_value;
}

direction GetDirectionForRobot(Map* _map) {
    // Starting from N go to the first unknown tile
    // If all are known go to the Tile with the smallest number

    Tile *robot = _map->robot_tile->tile;
    int smallest = 99999;
    direction proposed_direction = north;

    for (direction dir = north; dir<= west; dir++) {
        Node *neighbor = robot->neighbors[dir];
        if (neighbor == NULL) {                         // UNKNOWN !!!
            return dir + override;
        }

        if (IsWall(neighbor) == b_false) {                // Not a wall?
            if (neighbor->tile->number<smallest) {
                smallest = neighbor->tile->number;
                proposed_direction = dir;
            }
        }
    }
    return proposed_direction;    
}

Node *GetNodeAtPosition(Map *_map, int x, int y) {
    node_list *current_row = _map->floor;

    if (current_row->currentIndex > y)
        return NULL;

    while (current_row->currentIndex<y) {
        current_row = current_row->next;
        if (current_row == NULL) {
            return NULL;
        }
    }

    // Now look into the row
    node_list_element *current_element = current_row->list;
    while (current_element->node->tile->X < x) {
        current_element = current_element->next;
        if (current_element == NULL) {
            return NULL;
        }
    }

    return current_element->node->tile->X == x ? current_element->node : NULL;
}

BOOL_TYPE AddTileInDirection(Map *_map, direction _direction, Node *node_to_add) {

    if ((_direction & override) == 0 || IsWall(node_to_add))
        return b_false;

    _direction &= ~override;

    Tile *robot = _map->robot_tile->tile;

    Node *node = GetNodeAtPosition(_map,
                                   XInDirection(robot->X, _direction),
                                   YInDirection(robot->Y, _direction));
    if (node == NULL) { // there is no Node at this position
        node = node_to_add;
    }

    robot->neighbors[_direction] = node;
    node->tile->neighbors[GetOppositeDirection(_direction)] = _map->robot_tile;

    return InsertNodeIntoFloor(_map, node);
}
