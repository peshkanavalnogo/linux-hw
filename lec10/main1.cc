#include <iostream>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <system_error>

class File {
private:
    char* s;
    int fd;
public:
    char* buff;
    
    File(char* ss): s(ss), fd(open(ss, O_CREAT|O_TRUNC|O_RDWR, 0644)){}
    
    File(File&& f): s(f.s), fd(f.fd) {
        f.s = nullptr;
        f.fd = -1;    
    }
    File& operator=(File&& f) {
        File tmp(std::move(f));
        swap(tmp);
        return *this;
    }
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
        std::swap(fd, f.fd);
    }
};

int check(int ret) {
    if (ret == -1) {
        throw std::system_error(errno, std::generic_category());
    }
    return ret;
}

int main() {
    File f("myfile.txt");
//    File ff = f;
    std::cout << check(f.f_write("abc"));
    std::cout << f.f_read();
    std::cout << f.buff[1];
    return 0;
}
