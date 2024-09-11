#include "Buffer.h"
#include "malloc.h"
#include <algorithm>

Buffer::Buffer() = default;
Buffer::Buffer(int size, BUFFER_TYPE buff_type = FIXED) {
	if (size > 0) {
		buffer_ptr = malloc(size); // ¿ª±ÙBufferÄÚ´æ
		seek_offset = size;
	};
	this->type = buff_type;
}

int Buffer::size() {
	return buffer_size;
};

void Buffer::seek(int pos) {
    if (pos < 0) return;
    seek_offset = pos;
};

void Buffer::resize(int new_size) {
    if (new_size <= 0 || new_size == buffer_size) return;

    void* new_buffer_ptr = nullptr;
    if (new_size > buffer_size) {
        new_buffer_ptr = malloc(new_size);
        if (buffer_ptr != nullptr && new_buffer_ptr != nullptr) {
            std::memcpy(new_buffer_ptr, buffer_ptr, std::min(buffer_size, new_size));
            std::memset(buffer_ptr, 0, buffer_size);
        }
    }
    else {
        new_buffer_ptr = buffer_ptr;
    }

    if (buffer_ptr != nullptr && buffer_ptr != new_buffer_ptr) {
        free(buffer_ptr);
    }

    buffer_ptr = new_buffer_ptr;
    buffer_size = new_size;
}

void Buffer::clear() { 
	if (this->buffer_ptr == nullptr) return;
	std::memset(this->buffer_ptr, 0, this->buffer_size);
	this->seek_offset = 0;
}

void Buffer::write_memory(void* value, int length) {
    if (length > 0 && this->buffer_ptr != nullptr) {
        void* target = (void*)((unsigned long long)this->buffer_ptr + this->seek_offset);
        int vacant = length - (this->buffer_size - this->seek_offset);

        if (vacant > -1) {
            std::memcpy(target, value, length);
            this->seek_offset += length;
        }
        else {
            switch (this->type) {
            case FIXED:
                std::memcpy(target, value, length + vacant);
                this->seek_offset += length + vacant;
                break;
            case GROW:
                resize(this->buffer_size + length);
                std::memcpy(target, value, length);
                this->seek_offset += length;
                break;
            case WRAP:
                std::memcpy(target, value, length - vacant);
                std::memcpy(this->buffer_ptr, (void*)((unsigned long long)value + vacant), vacant);
                this->seek_offset = vacant;
                break;
            }
        }
    }
};

void Buffer::write(unsigned char value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(char value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(unsigned short value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(short value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(unsigned int value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(int value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(unsigned long value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(long value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(bool value) {
    write_memory(&value, sizeof(value));
};
void Buffer::write(float value) {
    write_memory(&value, sizeof(value));
}
void Buffer::write(double value) {
    write_memory(&value, sizeof(value));
};

void Buffer::copy_buffer(Buffer& value, int position, int length) {
    if (position + length <= value.buffer_size) {
        this->write_memory(value.buffer_ptr, value.buffer_size);
    }
}

char Buffer::get_byte() {
    if (this->buffer_size > 0 && this->buffer_ptr != nullptr) {
        char* pos = (char*)((unsigned long long)this->buffer_ptr + this->seek_offset);
        return *pos;
    }
    return 0;
}

