/*
 * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")
 * Copyright (C) 2002  Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* $Id: ds.h,v 1.5 2005/03/06 15:30:37 marka Exp $ */

#ifndef DNS_DS_H
#define DNS_DS_H 1

#include <isc/lang.h>

#include <dns/types.h>

#define DNS_DSDIGEST_SHA1 (1)

/*
 * Assuming SHA-1 digest type.
 */
#define DNS_DS_BUFFERSIZE (24)

ISC_LANG_BEGINDECLS

isc_result_t
dns_ds_buildrdata(dns_name_t *owner, dns_rdata_t *key,
		  unsigned int digest_type, unsigned char *buffer,
		  dns_rdata_t *rdata);
/*
 * Build the rdata of a DS record.
 *
 * Requires:
 *	key	Points to a valid DNS KEY record.
 *	buffer	Points to a temporary buffer of at least
 * 		DNS_DS_BUFFERSIZE bytes.
 *	rdata	Points to an initialized dns_rdata_t.
 *
 * Ensures:
 *      *rdata	Contains a valid DS rdata.  The 'data' member refers
 *		to 'buffer'.
 */

isc_boolean_t
dns_ds_digest_supported(unsigned int digest_type);
/*
 * Is this digest algorithm supported by dns_ds_buildrdata()?
 */

ISC_LANG_ENDDECLS

#endif /* DNS_DS_H */
