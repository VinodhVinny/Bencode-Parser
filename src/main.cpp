#include <iostream>
#include <fstream>
#include <sstream>
#include <jsoncpp/json/json.h>

#include "../include/bencode_parser.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "\nUsage: " << argv[0] << "<torrent file>\n\n";
        return 1;
    }

    std::ifstream torr_file(argv[1]);
    if (!torr_file) {
        std::cout << "\nError: No such file <" << argv[1] << "> present\n\n";
        return 1;
    }

    std::stringstream torr_str_buff;
    torr_str_buff << torr_file.rdbuf();
    torr_file.close();

    std::string torr_str = torr_str_buff.str();
    if (torr_str[torr_str.length()-1] == '\n') torr_str.pop_back();

    Json::Value torrent_info = bencode_decode(torr_str);
    std::cout << torrent_info << '\n';
}
