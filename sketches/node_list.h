#ifndef NODE_LIST_H_
#define NODE_LIST_H_

#include "node.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Forward definitions
typedef struct _node_list_element node_list_element;
typedef struct _node_list node_list;

struct _node_list_element {
    Node* node;
    node_list_element* next;
};

struct _node_list {
    int currentIndex;

    node_list_element* list;
    node_list* next;
};

node_list* CreateNodeList(Node* first_node);
node_list_element* CreateListElement(Node* node);
node_list_element* InsertNodeIntoList(node_list* list, Node* node);

#ifdef __cplusplus
}
#endif

#endif // NODE_LIST_H_
