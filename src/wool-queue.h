#ifndef WOOL_QUEUE_H
#define WOOL_QUEUE_H

#include <pthread.h>

Worker **workers;
Task   **bases;
int n_workers, n_procs, n_threads;

//void signal_worker_shutdown( void );
Task *push_task( Worker *self, Task *p );
void pop_task( Worker *self, Task *p );
int steal( Worker *self, Worker **victim_p, _wool_task_header_t card, int flags, volatile Task *jt, unsigned long ssn );

void init_worker( int w_idx );
void make_common_data( int n );

#endif /* not defined WOOL_QUEUE_H */

