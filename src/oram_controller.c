#include "oram_controller.h"

ORAM_queue_req* init_ORAM_queue_req(
    long long int vir_address,
    optype_t optype,
    long long int instrpc,
    int ROB_loc)
{
    ORAM_queue_req* req = (ORAM_queue_req*) malloc(sizeof(ORAM_queue_req));
    if (req == NULL) {
        return NULL;
    }
    req->complete = NO;
    req->comptime = 0;
    req->instrpc = instrpc;
    req->ROB_loc = ROB_loc;
    req->optype = optype;
    req->vir_address = vir_address;
    req->writes_scheduled = 0;
    req->reads_scheduled = 0;
    req->leaf_id = 0; // computation of leaf id to be done
    req->read_queue  = (ORAM_access*) malloc(sizeof(ORAM_access) * ORAM_TREE_LEVEL);
    req->write_queue = (ORAM_access*) malloc(sizeof(ORAM_access) * ORAM_TREE_LEVEL);
    memset(req->read_queue, 0, sizeof(ORAM_access) * ORAM_TREE_LEVEL);
    memset(req->read_queue, 0, sizeof(ORAM_access) * ORAM_TREE_LEVEL);
    return req;
}

void ORAM_queue_req_destroy(ORAM_queue_req* req) {
    if (req == NULL){
        return;
    }
    free(req->read_queue);
    free(req->write_queue);
    free(req);
    return;
}
