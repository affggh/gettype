/* 
  Edit by affggh
  GPLv3 LICENSE
  format.cpp and format.hpp from magiskboot source
  you can find it here : https://github.com/topjohnwu/Magisk
  This function is add up for some file format cannot auto detect
*/

#include <iostream>
#include <cstdlib>
#include <sys/uio.h>
#include <cstdio>
#include <memory>
#include <unistd.h>
#include <cstring>
// From magiskboot source
#include "format.hpp"

class stream {
public:
    virtual ssize_t read(void *buf, size_t len);
    virtual ssize_t readFully(void *buf, size_t len);
    virtual ssize_t readv(const iovec *iov, int iovcnt);
    virtual bool write(const void *buf, size_t len);
    virtual ssize_t writev(const iovec *iov, int iovcnt);
    virtual off_t seek(off_t off, int whence);
    virtual ~stream() = default;
};

using namespace std;
// From Magisk/jni/native/utils/include/stream.hpp
using stream_ptr = std::unique_ptr<stream>;

// source from magiskboot/compress.cpp
char *getfmt(char *infile) {

    FILE *in_fp = fopen(infile, "re");
	stream_ptr strm;
	char *t;
    char buf[4096];
    size_t len;
    while ((len = fread(buf, 1, sizeof(buf), in_fp))) {
        if (!strm) {
            format_t type = check_fmt(buf, len);
			t = (char*)fmt2name[type];
            //fprintf(stdout, "Detected format: [%s]\n", fmt2name[type]);
			break;
        }
	}
	strm.reset(nullptr);
    fclose(in_fp);
	return t;
}
