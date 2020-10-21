#ifndef __ORAM_CONTROLLER_H__
#define __ORAM_CONTROLLER_H__
#include <string.h>
#include "linked_list.h"
//#include <iostream>
//#include <queue>
//#include <map>
//#include <array>

#define ORAM_TREE_LEVEL 2

typedef enum {READ, WRITE} optype_t;

typedef enum
{
    YES,
    NO
} complete_t;

typedef struct {
    long long int node_id;
    long long int comptime;
} ORAM_access;

typedef struct
{
    /*ORAM_queue_node();
    void add_ORAM_request(long long int vir_address, char optype);  // given a new ORAM request, add it to ORAM job queue
    void get_ORAM_request();
    void set_ORAM_access_completion_time(int idx, char queue_type, long long int comptime); // set 'queue' idx request completion time
*/
    long long int comptime;
    long long int vir_address;
    long long int leaf_id;
    //char optype;
    long long int instrpc;
    int ROB_loc;
    int reads_scheduled;
    int writes_scheduled;
    optype_t optype;
//    std::array<ORAM_access, ORAM_TREE_LEVEL> read_queue;
//    std::array<ORAM_access, ORAM_TREE_LEVEL> write_queue;
	ORAM_access* read_queue;
	ORAM_access* write_queue;
    complete_t complete;
} ORAM_queue_req;

ORAM_queue_req* init_ORAM_queue_req(long long int vir_address, optype_t optype, long long int instrpc, int ROB_loc);
void ORAM_queue_req_destroy(ORAM_queue_req* req);

#endif          // end define __ORAM_CONTROLLER_H__
