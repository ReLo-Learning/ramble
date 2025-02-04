#pragma once

#ifndef FILE_SET_HPP
#define FILE_SET_HPP

#include <fstream>
#include <string>
#include <filesystem>

struct FileSet
{
    std::string filename;
    std::filesystem::path filepath;
    std::ifstream src;
};

#endif