#ifndef INDEXING_INDEXING_THREAD_WORKER_H
#define INDEXING_INDEXING_THREAD_WORKER_H


#include <condition_variable>
#include <mutex>
#include <map>
#include "boundary_analysis.hpp"
#include "count_token_usage.hpp"

#include <boost/lockfree/queue.hpp>

using boost::lockfree::queue;

void index_worker(queue<std::string> &index_queue, queue<std::map<std::string, std::size_t>> &merge_queue);

#endif //INDEXING_INDEXING_THREAD_WORKER_H
