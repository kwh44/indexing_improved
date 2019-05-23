#ifndef PARALLEL_INDEXING_READ_FROM_ARCHIVE_H
#define PARALLEL_INDEXING_READ_FROM_ARCHIVE_H

#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <boost/lockfree/queue.hpp>
#include "mqueue.hpp"


void get_path_content(mqueue<std::string> &, std::string &);

#endif