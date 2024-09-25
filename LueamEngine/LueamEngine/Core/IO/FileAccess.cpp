#include "FileAccess.h"

inline void FileAccess::correction_cursor()
{
	if (this->file_stream.tellp() != io_cursor) {
		this->file_stream.seekp(io_cursor, std::ios::beg);
	}
	if (this->file_stream.tellg() != io_cursor) {
		this->file_stream.seekg(io_cursor, std::ios::beg);
	}
}

FileAccess* FileAccess::open(String &f_path, int ope_mod)
{
	FileAccess* fs = new FileAccess();
	if (!file_exists(f_path)) {
		std::ofstream cfs(f_path);
		cfs.close();
	}
	fs->file_stream.open(f_path, ope_mod);

	fs->file_stream.seekg(0, std::ios_base::end);
	fs->file_length = fs->file_stream.tellg();
	fs->file_stream.seekg(0, std::ios_base::beg);
	return fs;
}

bool FileAccess::file_exists(String &f_path)
{
	if (f_path.is_empty()) {
		return false;
	}
	std::ifstream fs(f_path);
	return fs.good();
}

inline bool FileAccess::is_open()
{
	return this->file_stream && this->file_stream.is_open();
}

unsigned long long FileAccess::get_length()
{
	return this->file_length;
}

void FileAccess::close()
{
	if (this->is_open()) {
		this->file_stream.close();
		io_cursor = 0;
	}
}

void FileAccess::store_u8(unsigned char value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(unsigned char);
}

unsigned char FileAccess::get_u8()
{
	this->correction_cursor();
	unsigned char result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_s8(char value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(char);
}

char FileAccess::get_s8()
{
	this->correction_cursor();
	char result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_u16(unsigned short value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(unsigned short);
}

unsigned short FileAccess::get_u16()
{
	this->correction_cursor();
	unsigned short result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_s16(short value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(short);
}

short FileAccess::get_s16()
{
	this->correction_cursor();
	short result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_u32(unsigned int value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(unsigned int);
}

unsigned int FileAccess::get_u32()
{
	this->correction_cursor();
	unsigned int result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_s32(int value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(int);
}

int FileAccess::get_s32()
{
	this->correction_cursor();
	int result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_u64(unsigned long value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(unsigned long);
}

unsigned long FileAccess::get_u64()
{
	this->correction_cursor();
	unsigned long result;
	this->file_stream >> result;
	return result;
}

void FileAccess::store_s64(long value)
{
	this->correction_cursor();
	this->file_stream << value;
	this->io_cursor += sizeof(long);
}

long FileAccess::get_s64()
{
	this->correction_cursor();
	long result;
	this->file_stream >> result;
	return result;
}
String FileAccess::get_as_text()
{
	this->file_stream.seekg(0);
	this->file_stream.seekp(0);
	char* buff = new char[this->file_length + 1] {'\0'};
	this->file_stream.read(buff, this->file_length);
	return String(buff);
}

Buffer* FileAccess::get_buffer(unsigned long long length)
{
	unsigned long long size = this->file_length - this->io_cursor;
	char* byte_arr = new char[size];
	this->file_stream.read(byte_arr, size);
	Buffer* buffer = new Buffer(size, FIXED);
	for (unsigned long long i = 0; i < size; i++) {
		buffer->write(byte_arr[i]);
	}
	buffer->seek(0);
	return buffer;
}
