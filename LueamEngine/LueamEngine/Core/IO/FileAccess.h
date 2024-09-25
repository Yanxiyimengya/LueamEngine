#pragma once

#include <fstream>
#include "Core/UString.h"
#include "Core/Buffer.h"

enum OpenMod {
	IN = 0x01,
	OUT = 0x02
};

class FileAccess
{
	std::fstream file_stream;
	unsigned long long io_cursor = 0;
	unsigned long long file_length = 0;

	inline void correction_cursor();
public : 
	static FileAccess* open(String &f_path, int ope_mod = IN | OUT);
	static bool file_exists(String &f_path);
	inline bool is_open();
	unsigned long long get_length();
	void close();

	void store_u8(unsigned char value);
	unsigned char get_u8();
	void store_s8(char value);
	char get_s8();
	void store_u16(unsigned short value);
	unsigned short get_u16();
	void store_s16(short value);
	short get_s16();
	void store_u32(unsigned int value);
	unsigned int get_u32();
	void store_s32(int value);
	int get_s32();
	void store_u64(unsigned long value);
	unsigned long get_u64();
	void store_s64(long value);
	long get_s64();
	String get_as_text();
	Buffer* get_buffer(unsigned long long length);

};
