//
// Created by kwh44 on 5/21/19.
//

#ifndef INDEXING_MERGING_THREAD_WORKER_H
#define INDEXING_MERGING_THREAD_WORKER_H

#include <map>
#include <string>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <boost/lockfree/queue.hpp>
#include "mqueue.hpp"
void merge_worker(Mqueue<std::map<std::string, size_t>> &merge_queue);

#endif //INDEXING_MERGING_THREAD_WORKER_H
