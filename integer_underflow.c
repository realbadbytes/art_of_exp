struct header {
    unsigned int length;
    unsigned int message_type;
}

char *read_packet(int sockfd)
{
    int n;
    unsigned int length;
    struct header hdr;
    static char buffer[1024];

    /* read packet header from the network */
    if (full_read(sockfd, (void *)&hdr, sizeof(hdr)) <= 0) {
        error("full_read: %m");
        return NULL;
    }

    /* extract 32-bit packet length */
    length = ntohl(hdr.length);

    /* make sure length isnt greater than 1024, prevent overflow */
    if (length > (1024 + sizeof(struct header) - 1)) {
        error("not enough room in buffer\n");
        return NULL;
    }

    /* read rest of packet up to length minus header */
    /* bug: if length is less than sizeof(struct header), you are now reading a shitload of data in */
    /* this is stack buffer overflow now due to integer underflow */
    if (full_read(sockfd, buffer, length-sizeof(struct header)) <= 0) {
        error("read: %m");
        return NULL;
    }

    buffer[sizeof(buffer) - 1] = '\0';

    return strdup(buffer);
}
