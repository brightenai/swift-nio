#ifdef __ANDROID__
/*
Copyright (c) 2011, The WebRTC project authors. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in
    the documentation and/or other materials provided with the
    distribution.

  * Neither the name of Google nor the names of its contributors may
    be used to endorse or promote products derived from this software
    without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//#ifndef WEBRTC_BASE_IFADDRS_ANDROID_H_
//#define WEBRTC_BASE_IFADDRS_ANDROID_H_
//
//#include <stdio.h>
//#include <sys/socket.h>
//#include <netdb.h>
//
///* Implementation of getifaddrs for Android.
// * Fills out a list of ifaddr structs (see below) which contain information
// * about every network interface available on the host.
// * See 'man getifaddrs' on Linux or OS X (nb: it is not a POSIX function). */
//struct ifaddrs {
//  struct ifaddrs* ifa_next;
//  char* ifa_name;
//  unsigned int ifa_flags;
//  struct sockaddr* ifa_addr;
//  struct sockaddr* ifa_netmask;
//union {
//struct sockaddr *ifu_broadaddr;
//struct sockaddr *ifu_dstaddr;
//} ifa_ifu;
//  /* Real ifaddrs has broadcast, point to point and data members.
//   * We don't need them (yet?). */
//};
//
//int android_getifaddrs(struct ifaddrs** result);
//void android_freeifaddrs(struct ifaddrs* addrs);
//
//#endif  /* WEBRTC_BASE_IFADDRS_ANDROID_H_ */


#ifndef    _IFADDRS_H_
#define    _IFADDRS_H_

/*
 * Copyright (C) 2015 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#pragma once

/**
 * @file ifaddrs.h
 * @brief Access to network interface addresses.
 */

#include <sys/cdefs.h>
#include <netinet/in.h>
#include <sys/socket.h>

__BEGIN_DECLS

/**
 * Returned by getifaddrs() and freed by freeifaddrs().
 */
struct ifaddrs {
  /** Pointer to the next element in the linked list. */
  struct ifaddrs* ifa_next;

  /** Interface name. */
  char* ifa_name;
  /** Interface flags (like `SIOCGIFFLAGS`). */
  unsigned int ifa_flags;
  /** Interface address. */
  struct sockaddr* ifa_addr;
  /** Interface netmask. */
  struct sockaddr* ifa_netmask;

  union {
    /** Interface broadcast address (if IFF_BROADCAST is set). */
    struct sockaddr* ifu_broadaddr;
    /** Interface destination address (if IFF_POINTOPOINT is set). */
    struct sockaddr* ifu_dstaddr;
  } ifa_ifu;

  /** Unused. */
  void* ifa_data;
};

/** Synonym for `ifa_ifu.ifu_broadaddr` in `struct ifaddrs`. */
#define ifa_broadaddr ifa_ifu.ifu_broadaddr
/** Synonym for `ifa_ifu.ifu_dstaddr` in `struct ifaddrs`. */
#define ifa_dstaddr ifa_ifu.ifu_dstaddr

/**
 * [getifaddrs(3)](http://man7.org/linux/man-pages/man3/getifaddrs.3.html) creates a linked list
 * of `struct ifaddrs`. The list must be freed by freeifaddrs().
 *
 * Returns 0 and stores the list in `*__list_ptr` on success,
 * and returns -1 and sets `errno` on failure.
 *
 * Available since API level 24.
 */

#if __ANDROID_API__ >= 24
int getifaddrs(struct ifaddrs** __list_ptr) __INTRODUCED_IN(24);

/**
 * [freeifaddrs(3)](http://man7.org/linux/man-pages/man3/freeifaddrs.3.html) frees a linked list
 * of `struct ifaddrs` returned by getifaddrs().
 *
 * Available since API level 24.
 */
void freeifaddrs(struct ifaddrs* __ptr) __INTRODUCED_IN(24);
#endif /* __ANDROID_API__ >= 24 */


__END_DECLS

//
//struct ifaddrs {
//    struct ifaddrs  *ifa_next;
//    char        *ifa_name;
//    unsigned int     ifa_flags;
//    struct sockaddr    *ifa_addr;
//    struct sockaddr    *ifa_netmask;
//    struct sockaddr    *ifa_dstaddr;
//    void        *ifa_data;
//};
//
///*
// * This may have been defined in <net/if.h>.  Note that if <net/if.h> is
// * to be included it must be included before this header file.
// */
//#ifndef    ifa_broadaddr
//#define    ifa_broadaddr    ifa_dstaddr    /* broadcast address interface */
//#endif
//
//#include <sys/cdefs.h>
//
//__BEGIN_DECLS
//extern int getifaddrs(struct ifaddrs **ifap);
//extern void freeifaddrs(struct ifaddrs *ifa);
//__END_DECLS

#endif

#endif

