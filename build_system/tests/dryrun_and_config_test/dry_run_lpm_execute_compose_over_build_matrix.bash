#!/bin/bash

clear

# ....path resolution logic........................................................................
NBS_PATH_TO_SRC_SCRIPT="$(realpath "${BASH_SOURCE[0]}")"
NBS_ROOT_DIR="$(dirname "${NBS_PATH_TO_SRC_SCRIPT}")"
cd "${NBS_ROOT_DIR}/../../"

# ====begin========================================================================================
bash lpm_execute_compose_over_build_matrix.bash --fail-fast -- build --dry-run
