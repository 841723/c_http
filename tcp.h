#ifndef TCP_H
#define TCP_H

typedef void (*tcp_handler_t)(int client_fd, void *userdata);

int tcp_listen(
    const char *port,
    tcp_handler_t handler,
    void *userdata,
    void (*on_listen)(void)
);
void tcp_stop_listener();

#endif