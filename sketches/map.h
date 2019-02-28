#ifndef MAP_H_
#define MAP_H_

#include "node.h"
#include "node_list.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _Map {
        Node* robot_tile;
        int max_number;

        node_list* floor;

    } Map;

    Map* CreateMap(void);
    void InitializeRobotTile(Map* _map);
    Node* CreateMapNodeOnPosition(int x, int y);
    direction GetDirectionForRobot(Map* _map);
    BOOL_TYPE AddTileInDirection(Map *_map, direction _direction, Node *node_to_add);

    void MoveRobotToNextPosition(Map *map, BOOL_TYPE *current_walls);

    BOOL_TYPE InsertNodeIntoFloor(Map* _map, Node* _node);
    Node *GetNodeAtPosition(Map *_map, int x, int y);

#ifdef __cplusplus
}
#endif

#endif // MAP_H_
