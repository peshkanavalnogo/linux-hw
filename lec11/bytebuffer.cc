#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <system_error>
#include <sys/fcntl.h>

class File {
private:
    char* s;
public:
    int fd;
    char buff[50];
    
    // constructor
    File(char* ss): s(ss), fd(open(ss, O_CREAT|O_TRUNC|O_RDWR, 0644)) {}

    // move constructor
    File(File&& f): s(f.s), fd(f.fd) {
        swap(f);    
    }

    // copy constructor
    File(const File& f) {
        fd = dup(f.fd);
        s = f.s;
        for (size_t i = 0; i < 50; ++i) {
            buff[i] = f.buff[i];
        }
    }
    // move assignment
    File& operator=(File&& f) {
        File tmp(std::move(f));
        swap(tmp);
        return *this;
    }
    // copy assignment
    File& operator=(const File& f) {
        File tmp(f);
        swap(tmp);
        return *this;
    }
    File() {}

    ~File() {
        close(fd);
    }


    int f_write(std::string msg) {
        return write(fd, msg.data(), msg.size());
    }
    
    int f_read() {
       	return read(fd, buff, 50);
    }

    void swap(File& f) {
        std::swap(s, f.s);
        std::swap(buff, f.buff);
        std::swap(fd, f.fd);
    }
    
    off_t change_pos(off_t bites) {
        return lseek(fd, bites, SEEK_SET);
    }
};

int check(int ret);

class ByteBuffer {
private:
    void* ptr;
    size_t size;
    friend int check();
public:
    File f;
    // constructor
    ByteBuffer(size_t n) {
        size = 4096 * n;
        ptr = mmap(
            nullptr,
            size,
            PROT_READ|PROT_WRITE,
            MAP_SHARED,
            -1,
             0
        );
    }

    ByteBuffer(char* ss): f(ss) {
        struct stat status;
        stat(ss, &status);
        size = status.st_size;
        ptr = mmap(
            nullptr,
            size,
            PROT_READ|PROT_WRITE,
            MAP_SHARED,
            f.fd,
            0
        );
    }

    // move constructor
    ByteBuffer(ByteBuffer&& buff): ptr(buff.ptr), size(buff.size) {
        swap(buff);
    }

    ByteBuffer& operator=(ByteBuffer&& buff) {
        ByteBuffer tmp(std::move(buff));
        swap(tmp);
        return *this;
    }
    
    ~ByteBuffer() {
      // std::cout << check(munmap(ptr, size));
      munmap(ptr, size);
    }

    void resize(size_t n) {
        ptr = mremap(
            ptr,
            size,
            size*n,
            MREMAP_MAYMOVE
        );
        size *= n;
    }

    void swap(ByteBuffer& buff) {
        std::swap(ptr, buff.ptr);
        std::swap(size, buff.size);
    }
};


int check(int ret) {
    if (ret == -1) {
        throw std::system_error(errno, std::generic_category());
    }
    return ret;
}

int main() {
    ByteBuffer buff1(3);
    ByteBuffer buff2(std::move(buff1));
    ByteBuffer buff3 = std::move(buff2);
    buff3.resize(2);
    ByteBuffer buff4("myfile.txt");
    buff4.f.f_write("abc");
    return 0;
}
