/*
    Read integer from network socket
    Performs sanity checks
*/
char *read_data(int sockfd)
{
    char *buf;
    int length = network_get_int(sockfd);

    if (! (buf = (char *)malloc(MAXCHARS))) {
        die("malloc: %m");
    }

    /* bug: adding +1 to length can change the sign */
    /* if length is the maximum positive integer, +1 will flip it negative */
    /* this leads to a huge read into buf, heap buffer overflow */
    if (length < 0 || length + 1 >= MAXCHARS) {
        free(buf);
        die("bad length: %d", length);
    }

    if (read(sockfd, buf, length) <= 0) {
        free(buf);
        die("read: %m");
    }

    buf[length] = '\0';

    return buf;
}


