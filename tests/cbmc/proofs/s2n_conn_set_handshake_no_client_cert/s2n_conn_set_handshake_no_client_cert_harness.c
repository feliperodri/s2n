/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <assert.h>
#include <cbmc_proof/cbmc_utils.h>
#include <cbmc_proof/make_common_datastructures.h>

#include "api/s2n.h"
#include "tls/s2n_handshake.h"

void s2n_conn_set_handshake_no_client_cert_harness()
{
    /* Non-deterministic input. */
    struct s2n_connection *s2n_connection = malloc(sizeof(*s2n_connection));
    
    /* Operation under verification. */
    s2n_conn_set_handshake_no_client_cert(s2n_connection);
}
