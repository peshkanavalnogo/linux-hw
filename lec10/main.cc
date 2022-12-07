#include <iostream>
#include <unistd.h>
#include <string>
#include <system_error>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
   
class File{
private:
    int fd;
    std::string str;

    File(std::string& s): str(s), fd(open(str, O_CREAT|O_RDWR|O_TRUNC, 0644)) {}
    
    ~File() {
        close(fd);   
    }
public:
    void _write(std::string& msg) {
        write(fd, msg, sizeof(msg));
    }
    
    ssize_t _read() {
        ssize_t r = read(fd, str, sizeof(str));
        return r;
    }
};

int check(int ret) {
    if (ret == -1) {
        throw std::system_error(errno, std::generic_category());
    }
    return ret;

int main() {
    std::string s;
    std::cin << s;

    check(File f(s));
    f._write("abc");
    f._read();
}
