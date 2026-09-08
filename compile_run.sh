#!/usr/bin/env bash -x

programBinaryName="$1"
programCFileName="${programBinaryName}.c"

[[ -z "${programCFileName}" ]] && printf "ERROR: Missing program name\n"

clang -Wall -Wextra -Werror -g -o $programBinaryName $programCFileName && "./${programBinaryName}"; echo $? && rm "./${programBinaryName}"
