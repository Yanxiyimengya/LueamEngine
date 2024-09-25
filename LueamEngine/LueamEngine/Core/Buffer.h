#pragma once

enum BUFFER_TYPE {
	FIXED,
	GROW,
	WRAP
};

class Buffer
{
	int buffer_size = 0;			// 缓冲区大小
	BUFFER_TYPE type = FIXED;
	void* buffer_ptr = nullptr;		// 指向缓冲区内存的指针
	unsigned long long seek_offset = 0;	// 搜索偏移量

	void write_memory(void* value, int length);
public :
	Buffer();
	Buffer(int size, BUFFER_TYPE buff_type);

	int size();
	void seek(int pos);
	void clear();
	void resize(int size);

	void write(unsigned char value);
	void write(char value);
	void write(unsigned short value);
	void write(short value);
	void write(unsigned int value);
	void write(int value);
	void write(unsigned long value);
	void write(long value);
	void write(bool value);
	void write(float value);
	void write(double value);
	void copy_buffer(Buffer& value, int position, int length);

	char operator[](unsigned long long value);
};

