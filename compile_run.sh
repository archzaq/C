#!/usr/bin/env bash -x

programBinaryName="$1"
programCFileName="${programBinaryName}.c"

[[ -z "${programCFileName}" ]] && printf "ERROR: Missing program name\n"

clang -Wall -Wextra -Werror -g -O0 -o $programBinaryName $programCFileName && "./${programBinaryName}"; echo $? && rm "./${programBinaryName}"
