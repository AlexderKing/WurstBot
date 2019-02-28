#include <stdint.h>
#include <stdlib.h>
#include "./node.h"
#include "./node_list.h"
#include "./map.h"

static Node* Wall = NULL;
static Node* VWall = NULL;

Node* CreateNode(const tile_type type, Tile* data) {
    size_t size = sizeof(Node);
    Node* temp_Node = (Node*)malloc(size);
    temp_Node->tile = data;
    temp_Node->type = type;

    return  temp_Node;
}

Node* CreateMapWall(const tile_type type) {
    return CreateNode(type, NULL);
}

Node* CreateWall(void) {
    return Wall == NULL ? (Wall = CreateNode(wall, NULL)) : Wall;
}

Node* CreateVirtualWall(void) {
    return VWall == NULL ? (VWall = CreateNode(virtual_wall, NULL)) : VWall;
}

Tile* CreateMapTile(void) {
    Tile* temp_Tile = (Tile*)malloc(sizeof(Tile));
    for (int i = 0; i < 4; i++) {
        temp_Tile->neighbors[i] = NULL;
    }
    temp_Tile->number = -1;
    temp_Tile->X = 1234567;
    temp_Tile->Y = 1234567;

    return  temp_Tile;
} 

void UpdateTile(Tile *tile, const BOOL_TYPE *wall_info) {
    for (int i = 0; i < 4; i++) {
        tile->neighbors[i] = wall_info[i] ? CreateWall() : tile->neighbors[i];
    }
}

direction GetOppositeDirection(direction dir) {
    const BOOL_TYPE ov = (dir & override) != 0;

    dir &= ~override;

    if (dir % 2 == 0) {
        dir = 2 - dir;
    } else {
        dir = 4 - dir;
    }
    return ov ? dir | override : dir;
}

void DestroyTile(Tile *t) {
    free(t);
    t = NULL;
}

void DestroyNode(Node *n) {
    free(n);
    n = NULL;
}

