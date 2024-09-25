#include "UString.h"
#include <stdio.h>
#include <string.h>
#include "malloc.h"

String::String() = default;

String::String(const char*& value) {
    len = (unsigned long)std::strlen(value);
    data = new char[len + 1];
    strncpy_s(data, len + 1, value, len + 1);
};

String::String(const char value[]) {
    len = (unsigned long)std::strlen(value);
    data = new char[len + 1];
    strncpy_s(data, len + 1, value, len + 1);
};

String::operator const char* () {
    return (const char*)data;
}

char String::operator[](unsigned long index)
{
    return this->data[((index + len) % len)];
}

bool String::is_empty()
{
    return std::strlen(data) == 0;
}

unsigned long String::length()
{
    return this->len;
}
