#pragma once

#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
class Error
{
public:
    std::string msg;

    virtual ~Error() = default;
};

#endif