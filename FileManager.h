#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

namespace FM
{
    int create(std::string file_name);
    void read(std::string file_name);
    void copy(std::string file_name, std::string file_copy);
    void move(std::string file_name, std::string move_path);
    void Remove(std::string file_name);
    void read_dir(std::string dir_name);
    void create_Slink(std::string file_name, std::string link_name);
    void create_Hlink(std::string file_name, std::string link_name);
}