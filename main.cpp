#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <mutex>
#include <numeric>
#include <boost/locale/generator.hpp>
#include <boost/locale.hpp>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include <condition_variable>
#include "read_config.hpp"
#include "measure_time.hpp"
#include "read_from_path.hpp"
#include "boundary_analysis.hpp"
#include "count_token_usage.hpp"

#include "indexing_thread_worker.hpp"
#include "merging_thread_worker.hpp"


int main(int argc, char **argv) {
    // help info
    if (argc == 2 && std::string(argv[1]) == "--help") {
        std::cout << "Description\n" <<
                  "$ ./parallel_indexing <path_to_config_file>\n";
        return 0;
    }
    std::string filename("../config.dat");
    // user's config file
    if (argc == 2) {
        filename = std::string(argv[1]);
    }
    std::ifstream config_stream(filename);
    if (!config_stream.is_open()) {
        std::cerr << "Failed to open configuration file " << filename << std::endl;
        return 1;
    }
    config_data_t conf_data;
    try {
        read_config_data(config_stream, conf_data);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }

    // check output files
    std::ofstream output_alphabet(conf_data.output_alphabet_order);
    if (!config_stream.is_open()) {
        std::cerr << "Failed to open file for alphabet order result" << std::endl;
        return 1;
    }
    std::ofstream output_count(conf_data.output_count_order);
    if (!config_stream.is_open()) {
        std::cerr << "Failed to open file for count order result " << std::endl;
        return 1;
    }

#ifdef DEBUG
    std::cout << "Input dir name \"" << conf_data.input_dir_name << "\"." << std::endl;
    std::cout << "Output alphabet order filename \"" << conf_data.output_alphabet_order << "\"." << std::endl;
    std::cout << "Output count order filename \"" << conf_data.output_count_order << "\"." << std::endl;
    std::cout << "Indexing threads num to utilize " << conf_data.indexing_thread_num << "." << std::endl;
    std::cout << "Merging threads num to utilize " << conf_data.merging_thread_num << "." << std::endl;
#endif

    boost::locale::generator gen;
    std::locale::global(gen("en_us.UTF-8"));

    // array of blocks
    boost::lockfree::queue<std::string> index_queue;
//    boost::lockfree::queue<std::map<std::string, size_t>> merge_queue;
//
//
//    std::thread reader(get_path_content, std::ref(index_queue), std::ref(conf_data.input_dir_name));
//
//
//    boost::asio::thread_pool indexing_pool(conf_data.indexing_thread_num);
//    boost::asio::thread_pool merge_pool(conf_data.merging_thread_num);
//
//    boost::asio::post(indexing_pool,
//                      [&index_queue, &merge_queue]() { index_worker(index_queue, merge_queue); });
//
//
//    boost::asio::post(merge_pool, [&merge_queue]() { merge_worker(merge_queue); });
//    reader.join();
//    std::cout << "READER JOINED" << std::endl;
////    for (auto &v: indexing_threads) v.join();
//    indexing_pool.join();
//    std::map<std::string, size_t> merge_queue_empty;
//    merge_queue.push(merge_queue_empty);
//    std::cout << "INDEXING JOINED" << std::endl;
//    merge_pool.join();
//    std::cout << std::endl;
//    std::cout << "Printing final map\n";
//    auto final = std::move(merge_queue.pop());
//    for (auto it = final.begin(); it != final.end(); ++it) {
//        std::cout << it->first << " " << it->second << std::endl;
//    }
//    std::cout << "Merge_queue size is " << merge_queue.size() << std::endl;
    return 0;
}
