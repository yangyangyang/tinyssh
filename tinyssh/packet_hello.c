/*
20140125
Jan Mojzis
Public domain.
*/

#include "buf.h"
#include "byte.h"
#include "writeall.h"
#include "purge.h"
#include "log.h"
#include "bug.h"
#include "str.h"
#include "getln.h"
#include "packet.h"

/*
The 'packet_hello_send()' function sends SSH hello string to the client.
See RFC 4253 4.2. Protocol Version Exchange.
Example: SSH-2.0-tinyssh_20140501experimental 65f8E84J
*/
int packet_hello_send(void) {

    struct buf *b = &packet.hellosend;

    buf_purge(b);
    buf_puts(b, "SSH-2.0-tinyssh_");
    buf_puts(b, VERSION);
    buf_puts(b, " ");
    buf_puts(b, log_string());
    buf_puts(b, "\r\n");
    if (writeall(1, b->buf, b->len) == -1) bug();
    b->len -= 2; /* remove "\r\n" */
    b->buf[b->len] = 0;
    log_d2("hello: server: ", (char *)(b->buf));
    purge(b->buf + b->len, b->alloc - b->len);
    return 1;
}

/*
The 'packet_hello_receive()' function receives SSH hello string from the client.
See RFC 4253 4.2. Protocol Version Exchange.
Example: SSH-2.0-OpenSSH_6.6.1p1 Debian-4~bpo70+1
*/
int packet_hello_receive(void) {

    int r;
    struct buf *b = &packet.helloreceive;

    r = getln(0, b->buf, b->alloc);
    if (r != 1) bug();
    b->len = str_len((char *)b->buf);
    if (b->len < 6) bug_proto();
    if (b->buf[b->len - 1] == '\n') --(b->len); /* remove '\n' */
    if (b->buf[b->len - 1] == '\r') --(b->len); /* remove '\r' */
    if (!byte_isequal(b->buf, 4, "SSH-")) bug_proto();
    b->buf[b->len] = 0;
    log_d2("hello: client: ", (char *)b->buf);
    purge(b->buf + b->len, b->alloc - b->len);
    return 1;
}
