# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License"). You may not use
# this file except in compliance with the License. A copy of the License is
# located at
#
#     http://aws.amazon.com/apache2.0/
#
# or in the "license" file accompanying this file. This file is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing permissions and
# limitations under the License.

# Enough to get full coverage with 3 minutes of runtime.
MAX_BLOB_SIZE = 4
DEFINES += -DMAX_BLOB_SIZE=$(MAX_BLOB_SIZE)

CONTRACTS_FLAG = --enforce-contract s2n_stuffer_read_base64

CBMCFLAGS +=

PROOF_UID = s2n_stuffer_read_base64
HARNESS_ENTRY = $(PROOF_UID)_harness
HARNESS_FILE = $(HARNESS_ENTRY).c

PROOF_SOURCES += $(PROOFDIR)/$(HARNESS_FILE)
PROOF_SOURCES += $(PROOF_SOURCE)/cbmc_utils.c
PROOF_SOURCES += $(PROOF_SOURCE)/make_common_datastructures.c
PROOF_SOURCES += $(PROOF_STUB)/mlock.c
PROOF_SOURCES += $(PROOF_STUB)/munlock.c
PROOF_SOURCES += $(PROOF_STUB)/posix_memalign_override.c
#PROOF_SOURCES += $(PROOF_STUB)/memmove_override.c
PROOF_SOURCES += $(PROOF_STUB)/s2n_calculate_stacktrace.c
PROOF_SOURCES += $(PROOF_STUB)/sysconf.c

PROJECT_SOURCES += $(SRCDIR)/stuffer/s2n_stuffer.c
PROJECT_SOURCES += $(SRCDIR)/stuffer/s2n_stuffer_base64.c
PROJECT_SOURCES += $(SRCDIR)/stuffer/s2n_stuffer_network_order.c
PROJECT_SOURCES += $(SRCDIR)/utils/s2n_blob.c
PROJECT_SOURCES += $(SRCDIR)/utils/s2n_ensure.c
PROJECT_SOURCES += $(SRCDIR)/utils/s2n_result.c
PROJECT_SOURCES += $(SRCDIR)/utils/s2n_safety.c
PROJECT_SOURCES += $(SRCDIR)/utils/s2n_mem.c

# We abstract these functions because manual inspection demonstrates they are unreachable.
REMOVE_FUNCTION_BODY += __CPROVER_file_local_s2n_mem_c_s2n_mem_cleanup_impl
REMOVE_FUNCTION_BODY += s2n_blob_slice
REMOVE_FUNCTION_BODY += s2n_stuffer_wipe

UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.0:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.1:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.2:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.3:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.4:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.5:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.6:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.7:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.8:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.9:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.10:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.11:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.12:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.13:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.14:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.15:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.16:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.17:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.18:$(MAX_BLOB_SIZE)
UNWINDSET += __CPROVER_contracts_original_s2n_stuffer_read_base64.19:$(MAX_BLOB_SIZE)

include ../Makefile.common
