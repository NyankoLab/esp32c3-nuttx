#pragma once

void esp_mbedtls_ctr_drbg_free();
void esp_mbedtls_ctr_drbg_init();
void esp_mbedtls_ctr_drbg_random();
void esp_mbedtls_ctr_drbg_seed();
void esp_mbedtls_entropy_free();
void esp_mbedtls_entropy_func();
void esp_mbedtls_entropy_init();
void esp_mbedtls_net_connect();
void esp_mbedtls_net_free();
void esp_mbedtls_net_init();
void esp_mbedtls_net_recv();
void esp_mbedtls_net_recv_timeout();
void esp_mbedtls_net_send();
void esp_mbedtls_pk_free();
void esp_mbedtls_pk_init();
void esp_mbedtls_pk_parse_keyfile();
void esp_mbedtls_ssl_close_notify();
void esp_mbedtls_ssl_conf_authmode();
void esp_mbedtls_ssl_conf_ca_chain();
void esp_mbedtls_ssl_conf_own_cert();
void esp_mbedtls_ssl_conf_read_timeout();
void esp_mbedtls_ssl_conf_rng();
void esp_mbedtls_ssl_config_defaults();
void esp_mbedtls_ssl_config_free();
void esp_mbedtls_ssl_config_init();
void esp_mbedtls_ssl_free();
void esp_mbedtls_ssl_get_verify_result();
void esp_mbedtls_ssl_handshake();
void esp_mbedtls_ssl_init();
void esp_mbedtls_ssl_read();
void esp_mbedtls_ssl_set_bio();
void esp_mbedtls_ssl_set_hostname();
void esp_mbedtls_ssl_setup();
void esp_mbedtls_ssl_write();
void esp_mbedtls_x509_crt_free();
void esp_mbedtls_x509_crt_init();
void esp_mbedtls_x509_crt_parse_file();
void esp_mbedtls_x509_crt_verify_info();