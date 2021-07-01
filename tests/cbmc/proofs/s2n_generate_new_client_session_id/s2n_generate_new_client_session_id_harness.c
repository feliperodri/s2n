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

#include <tls/s2n_connection.h>

void s2n_generate_new_client_session_id_harness()
{
    /* Non-deterministic inputs. */
    struct s2n_connection *s2n_connection = malloc(sizeof(*s2n_connection));

    /* Operation under verification. */
    if (s2n_generate_new_client_session_id(s2n_connection) == S2N_SUCCESS)
    {
        /* Post-conditions. */
        //assert(s2n_result_is_ok(s2n_blob_validate(s2n_connection->se)));
        assert(S2N_IMPLIES(s2n_connection->mode == S2N_SERVER, s2n_connection->session_id_len == S2N_TLS_SESSION_ID_MAX_LEN));
    }

    /* Post-conditions. */
    //assert(S2N_IMPLIES(last_message_name != NULL, s2n_result_is_ok(s2n_handshake_validate(&(s2n_connection->handshake)))));
}
