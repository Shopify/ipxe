#ifndef _IPXE_NVO_H
#define _IPXE_NVO_H

/** @file
 *
 * Non-volatile stored options
 *
 */

FILE_LICENCE ( GPL2_OR_LATER );

#include <stdint.h>
#include <ipxe/dhcpopts.h>
#include <ipxe/settings.h>

struct nvs_device;
struct refcnt;

/**
 * A block of non-volatile stored options
 */
struct nvo_block {
	/** Settings block */
	struct settings settings;
	/** Underlying non-volatile storage device */
	struct nvs_device *nvs;
	/** Address within NVS device */
	unsigned int address;
	/** Length of options data */
	size_t len;
	/** Option-containing data */
	void *data;
	/** DHCP options block */
	struct dhcp_options dhcpopts;
};

extern void nvo_init ( struct nvo_block *nvo, struct nvs_device *nvs,
		       size_t address, size_t len, struct refcnt *refcnt );
extern int register_nvo ( struct nvo_block *nvo, struct settings *parent );
extern void unregister_nvo ( struct nvo_block *nvo );

#endif /* _IPXE_NVO_H */
