
#include "indexing_thread_worker.hpp"
#include "mqueue.hpp"

void index_worker(mqueue<std::string> &index_queue, mqueue<std::map<std::string, std::size_t>> &merge_queue) {
    std::string string_to_index;
    while (true) {
        string_to_index = std::move(index_queue.pop());
        if (string_to_index.empty()) {
            index_queue.push(string_to_index);
//            finish work
            break;
        }
        std::map<std::string, size_t> tls_map;
        std::vector<std::string> tokens;
        parse(string_to_index, tokens);
        token_usage(string_to_index, tokens, tls_map);
        merge_queue.push(std::move(tls_map));
    }
}

