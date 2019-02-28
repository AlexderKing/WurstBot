/************ Algorithm declaration ***************/
/*
 * 1.   Scan all 4 sides and update map by walls
 *
 * 2.   Drive to the left side when unknown if not drive to the left right
 * 2.1  Save your tile with number (from map) as neighbor and update robot location as well as number
 * 2.2  If all tiles are already known drive back (always to smallest number) to the first with unknown tiles
 *      and go back to 1.
 *
 * 3.   If all tiles are already passed you should be at tile number 1 => Finish
 * 3.1  (optional) check if there are no more unknown tiles
 *
 */

#ifndef NODE_H_
#define NODE_H_

#ifdef __cplusplus
extern "C"
{
#endif

// Defining boolean type
#ifndef BOOL_TYPE
    #define BOOL_TYPE char
    #endif
//typedef char boolean;
#define b_false (char)0
#define b_true (char)1

/* Definition of Enums */
typedef enum TileType{
    virtual_wall = -2, 
    wall = -1, 
    standard_tile = 1, 
    black_tile = 2, 
    checkpoint = 3, 
    ramp = 4
} tile_type;

typedef enum _Direction {
    north = 0,
    east = 1,
    south = 2,
    west = 3,
    override = 128,
    override_north = 128,
    override_east = 129,
    override_south = 130,
    override_west = 131
} direction;

typedef struct tile Tile;
typedef struct node Node;

struct tile {

    Node* neighbors[4]; // Neighbors should be 0123
                        //                     NESW
    int number;
    int X, Y;
};

struct node {
    Tile* tile;
    tile_type type;
};

Tile* CreateMapTile(void);
Node* CreateNode(const tile_type type, Tile* data);

void DestroyTile(Tile *t);
void DestroyNode(Node *n);
        
    

// Walls
Node* CreateMapWall(const tile_type type);
Node* CreateWall(void);
Node* CreateVirtualWall(void);

void UpdateTile(Tile *tile, const BOOL_TYPE *wall_info);

inline BOOL_TYPE IsWall(Node *n) { return n->type == wall || n->type == virtual_wall; }
inline int XInDirection(int x, direction dir) { return dir == west ? (direction)(x - 1) : dir == east ? (direction)(x + 1) : (direction)x; }
inline int YInDirection(int y, direction dir) { return dir == north ? y - 1 : dir == south ? y + 1 : y; }

direction GetOppositeDirection(direction direction);

#ifdef __cplusplus
}
#endif
#endif // NODE_H_
