/*
Copyright 2014 Cisco. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY CISCO ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed
or implied, of Cisco.
*/

#include "sockaddr_util.h"
#include "icelibtypes.h"
#include <stdlib.h>
#include <string.h>

char const * ICELIBTYPES_ICE_CANDIDATE_TYPE_toString(const ICE_CANDIDATE_TYPE candidateType){
    switch(candidateType){
    case ICE_CAND_TYPE_NONE:
        return "NONE";
    case ICE_CAND_TYPE_HOST:
        return "HOST";
    case ICE_CAND_TYPE_SRFLX:
        return "SRFLX";
    case ICE_CAND_TYPE_RELAY:
        return "RELAY";
    case ICE_CAND_TYPE_PRFLX:
        return "PRFLX";
    }
    return "UNKNOWN";
}

char const * ICELIBTYPES_ICE_CANDIDATE_Component_toString (uint32_t componentid)
{
    if (componentid == ICELIB_RTP_COMPONENT_ID)
        return "RTP";
    else if (componentid == ICELIB_RTCP_COMPONENT_ID)
        return "RTCP";

    return "UNKNOWN Component";

}

void ICELIBTYPES_ICE_CANDIDATE_reset(ICE_CANDIDATE *candidate)
{
	memset(candidate, 0, sizeof(*candidate));
}

bool ICELIBTYPES_ICE_MEDIA_STREAM_isEmpty(const ICE_MEDIA_STREAM *iceMediaStream)
{
    if (iceMediaStream->numberOfCandidates > 0) {
        return false;
    }
    return true;
}

bool ICELIBTYPES_ICE_MEDIA_isEmpty(const ICE_MEDIA *iceMedia)
{
    if (iceMedia->numberOfICEMediaLines > 0) {
        return false;
    }
    return true;
}

void ICELIBTYPES_ICE_MEDIA_STREAM_reset(ICE_MEDIA_STREAM *iceMediaStream)
{
    memset(iceMediaStream, 0, sizeof(*iceMediaStream));
}

void ICELIBTYPES_ICE_MEDIA_reset(ICE_MEDIA *iceMedia)
{
    memset(iceMedia, 0, sizeof(*iceMedia));
}

int ICE_TRANSPORT_proto(ICE_TRANSPORT transport)
{
    switch (transport) {
    case ICE_TRANS_UDP:
        return IPPROTO_UDP;

    case ICE_TRANS_TCPACT:
    case ICE_TRANS_TCPPASS:
        return IPPROTO_TCP;
    }

    abort();
}
