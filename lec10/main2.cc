#include <iostream>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <system_error>

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

int check(int ret) {
    if (ret == -1) {
        throw std::system_error(errno, std::generic_category());
    }
    return ret;
}

int main() {
    File f("myfile.txt");
/*    std::cout << check(f.f_write("abc"));
    std::cout << check(f.f_read());
    std::cout << f.buff[5] << "\n";
    std::cout << f.fd << "\n";
    std::cout << check(f.change_pos(2));
    f.f_write("yy");
    File ff;
    std::cout << ff.fd << "\n";
    f = ff;
    std::cout << f.fd;
    File ff(std::move(f));
    ff = std::move(f);
    std::cout << ff.fd; */
    return 0;
}
