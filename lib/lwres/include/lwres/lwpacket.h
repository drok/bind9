/*
 * Copyright (C) 1999  Internet Software Consortium.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#ifndef ISC_LWPACKET_H
#define ISC_LWPACKET_H 1

#include <stddef.h>

#include <isc/lang.h>
#include <isc/types.h>

typedef struct isc_lwpacket isc_lwpacket_t;

struct isc_lwpacket {
	isc_uint32_t		length;
	isc_uint32_t		version;
	isc_uint32_t		serial;
	isc_uint32_t		opcode;
	isc_uint32_t		result;
	isc_uint16_t		authtype;
	isc_uint16_t		authlength;
};

#define ISC_LWPACKETVERSION_0

/*
 * "length" is the overall packet length, including the entire packet header.
 *
 * "version" specifies the header format.  Currently, there is only one
 * format, ISC_LWPACKETVERSION_0
 *
 * "serial" is set by the requestor and is returned in all replies.  If two
 * packets from the same source have the same serial number and are from 
 * the same source, they are assumed to be duplicates and the latter ones
 * may be dropped.  (The library does not do this by default on replies, but
 * does so on requests.)
 *
 * "opcode" is application defined.  Opcodes between 0x04000000 and 0xffffffff
 * are application defined.  Opcodes between 0x00000000 and 0x03ffffff are
 * reserved for library use.
 *
 * "result" is application defined, and valid only on replies.
 * Results between 0x04000000 and 0xffffffff are application defined.
 * Results between 0x00000000 and 0x03ffffff are reserved for library use.
 * (This is the same reserved range defined in <isc/resultclass.h>, so it
 * would be trivial to map ISC_R_* result codes into packet result codes
 * when appropriate.)
 *
 * "authtype" is the packet level auth type used.
 * Authtypes between 0x1000 and 0xffff are application defined.  Authtypes
 * between 0x0000 and 0x0fff are reserved for library use.
 *
 * "authlen" is the length of the authentication data.  See the specific
 * authtypes for more information on what is contained in this field.
 *
 * The remainder of the packet consists of two regions, one described by
 * "authlen" and one of "length - authlen - sizeof(isc_lwpacket_t)".
 *
 * That is:
 *
 *	pkt header
 *	authlen bytes of auth information
 *	data bytes
 */

/* XXXMLG Some of this belongs here, some elsewhere.
 *
 * Initially, we will define only a few opcodes:
 *
 *	NOOP.  Success is always returned.
 *
 *	GETADDRSBYNAME.  Return all known addresses for a given name.
 *		This may return NIS or /etc/hosts info as well as DNS
 *		information.  Flags will be provided to indicate ip4/ip6
 *		addresses are desired.
 *
 *	GETNAMEBYADDR.	Return the hostname for the given address.  Once
 *		again, it will return data from multiple sources.
 *
 *	GETDNSTYPE.  Return information about a given name using DNS
 *		specific structure formats.  That is, one can request MX,
 *		NS, SOA, etc. using this opcode.
 */

ISC_LANG_BEGINDECLS


ISC_LANG_ENDDECLS

#endif /* ISC_EVENT_H */






