#pragma once

#include <string>
#include <optional>

struct dns_header_t {
    uint16_t m_question_count;
    uint16_t m_answer_count;
    uint16_t m_authority_count;
    uint16_t m_additional_count;
};

struct dns_question_t {
    const char *m_name;
    uint16_t    m_type;
    uint16_t    m_class;
};

struct dns_resource_record_t {
    const char *m_name;
    uint16_t    m_type;
    uint16_t    m_class;
    uint32_t    m_ttl;
    uint16_t    m_data_length;
    const char *m_data;
};

bool
dns_parse_header(
    const char *const          p_packet,
    const size_t               p_packet_size,
    struct dns_header_t *const p_result
);

const char *
dns_parse_question(
    const char *const            p_packet,
    const size_t                 p_packet_size,
    const char *                 p_iter,
    struct dns_question_t *const p_result
);

const char *
dns_parse_record(
    const char *const                   p_packet,
    const size_t                        p_packet_size,
    const char *                        p_iter,
    struct dns_resource_record_t *const p_result
);

std::optional<std::string>
dns_decode_qname(
    const char *const p_packet,
    const size_t      p_packet_size,
    const char *      p_iter,
    const bool        p_recurse=true
);

const char *
dns_get_body(const char *const p_buffer);

uint16_t
read_network_u16(const char *const p_buffer);
