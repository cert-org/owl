#ifndef AWDL_TX_H_
#define AWDL_TX_H_

#include "frame.h"
#include "version.h"
#include "state.h"

enum TX_RESULT {
	TX_OK = 0,
	TX_FAIL = -1,
};

int awdl_init_action(uint8_t *buf, enum awdl_action_type);

int awdl_init_chanseq(uint8_t *buf, const struct awdl_state *);

int awdl_init_sync_params_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_chanseq_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_election_params_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_election_params_v2_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_service_params_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_ht_capabilities_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_data_path_state_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_arpa_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_version_tlv(uint8_t *buf, const struct awdl_state *);

int awdl_init_full_action_frame(uint8_t *buf, struct awdl_state *, struct ieee80211_state *, enum awdl_action_type);

int awdl_init_data(uint8_t *buf, struct awdl_state *);

int awdl_init_full_data_frame(uint8_t *buf, const struct ether_addr *src, const struct ether_addr *dst,
                              const uint8_t *payload, unsigned int plen,
                              struct awdl_state *, struct ieee80211_state *);

int ieee80211_init_radiotap_header(uint8_t *buf);

int ieee80211_init_awdl_hdr(uint8_t *buf, const struct ether_addr *src, const struct ether_addr *dst,
                            struct ieee80211_state *, uint16_t type);

int ieee80211_init_awdl_action_hdr(uint8_t *buf, const struct ether_addr *src, const struct ether_addr *dst,
                                   struct ieee80211_state *);

int ieee80211_init_awdl_data_hdr(uint8_t *buf, const struct ether_addr *src, const struct ether_addr *dst,
                                 struct ieee80211_state *);

int llc_init_awdl_hdr(uint8_t *buf);

#endif /* AWDL_TX_H_ */
