/*
    Take a width, height, and initial row
    Create a table in memory where each row is initialized to have same contents as init_row

    This function has an integer overflow bug, too large width * height can result in 
    a small malloc, but the memory past buf will be overwritten with init_row.
*/

u_char *make_table(unsigned int width, unsigned int height, u_char *init_row)
{
    unsigned int n;
    int i;
    u_char *buf;

    n = width * height;

    buf = (char *)malloc(n);

    if (!buf) {
        return NULL;
    }

    for (i = 0; i<height; i++) {
        memcpy(&buf[i*width], init_row, width);
    }

    return buf;
}

/*
    Openssh 3.1 overflow example
    nresp, if large enough, would cause a small malloc due to the multiplication in xmalloc() call
    then you can overwrite memory past response buffer.
    This was a major remotely exploitable bug.
*/
u_int nresp;
nresp = packet_get_int();
if (nresp > 0) {
    response = xmalloc(nresp * sizeof(char *));
    for (i = 0; i < nresp; i++) {
        response[i] = packet_get_string(NULL);
    }
    packet_check_eom();
}
