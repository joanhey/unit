
/*
 * Copyright (C) NGINX, Inc.
 */

#ifndef _NXT_H1PROTO_H_INCLUDED_
#define _NXT_H1PROTO_H_INCLUDED_


#include <nxt_main.h>
#include <nxt_http_parse.h>
#include <nxt_http.h>
#include <nxt_router.h>


typedef struct nxt_h1p_websocket_timer_s nxt_h1p_websocket_timer_t;


struct nxt_h1proto_s {
    nxt_http_request_parse_t  parser;

    uint8_t                   nbuffers;
    uint8_t                   keepalive;            /* 1 bit  */
    uint8_t                   chunked;              /* 1 bit  */
    uint8_t                   websocket;            /* 1 bit  */
    uint8_t                   connection_upgrade;   /* 1 bit  */
    uint8_t                   upgrade_websocket;    /* 1 bit  */
    uint8_t                   websocket_version_ok; /* 1 bit  */
    nxt_http_te_t             transfer_encoding:8;  /* 2 bits */

    uint8_t                   websocket_cont_expected;  /* 1 bit */
    uint8_t                   websocket_closed;         /* 1 bit */

    uint32_t                  header_size;

    nxt_http_field_t          *websocket_key;
    nxt_h1p_websocket_timer_t *websocket_timer;

    nxt_http_request_t        *request;
    nxt_buf_t                 *buffers;
    /*
     * All fields before the conn field will
     * be zeroed in a keep-alive connection.
     */
    nxt_conn_t                *conn;
};

#endif  /* _NXT_H1PROTO_H_INCLUDED_ */
