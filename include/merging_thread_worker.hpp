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

using boost::lockfree::queue;
void merge_worker(queue<std::map<std::string, size_t>> &merge_queue);

#endif //INDEXING_MERGING_THREAD_WORKER_H
