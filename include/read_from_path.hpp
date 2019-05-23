#ifndef PARALLEL_INDEXING_READ_FROM_ARCHIVE_H
#define PARALLEL_INDEXING_READ_FROM_ARCHIVE_H

#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <boost/lockfree/queue.hpp>
// queue of blocks, dir name, cv, m

using boost::lockfree::queue;

void get_path_content(queue<std::string> &, std::string &);

#endif