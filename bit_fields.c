struct controller {
    unsigned int id:4;
    unsigned int tflag:1;
    /* single bit flags */
    unsigned int rflag:1;
    unsigned int ack:2;
    unsigned int seqnum:8;
    unsigned int code:16;
};


