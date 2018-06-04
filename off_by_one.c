struct session {
    int sequence;
    int mac[MAX_MAC];
    char *key;
};

int delete_session(struct session *session)
{
    memset(session->key, 0, KEY_SIZE);
    free(session->key);
    free(session);
}

int get_mac(int fd, struct session *session)
{
    unsigned int i;
    unsigned int n;

    n = read_network_integer(fd);

    /* This doesnt fail if n == MAX_MAC */
    /* Therefore, one byte overwrite of session->mac occurs in the for loop */
    /* In the session struct, this means that one byte of char *key is overwritten */
    /* When session is deleted, this *key pointer is used to zero out, giving us arbitrary null KEY_SIZE write */
    if (n > MAX_MAC)
        return -1;

    for (i = 0; i <= n; i++) {
        session->mac[i] = read_network_integer(fd);
    }

    return 0;
}
