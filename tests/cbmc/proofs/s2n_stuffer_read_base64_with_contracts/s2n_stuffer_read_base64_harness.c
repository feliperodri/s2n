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
#include "stuffer/s2n_stuffer.h"
#include "utils/s2n_mem.h"

void s2n_stuffer_read_base64_harness()
{
    /* Non-deterministic inputs. */
    struct s2n_stuffer *stuffer = cbmc_allocate_s2n_stuffer();
    struct s2n_stuffer *out = cbmc_allocate_s2n_stuffer();

    /* Bound input. */
    __CPROVER_assume(S2N_IMPLIES(stuffer!= NULL, s2n_blob_is_bounded(&stuffer->blob, MAX_BLOB_SIZE)));

    /* Non-deterministically set initialized (in s2n_mem) to true. */
    nondet_s2n_mem_init();

    /* Operation under verification. */
    s2n_stuffer_read_base64(stuffer, out);
}
