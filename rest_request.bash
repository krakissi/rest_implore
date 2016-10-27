#!/bin/bash
export server=${server:-localhost}
export port=${port:-8080}

# Use the installed version if present, else attempt to use the local bin.
implore=$(which rest_implore)

if [ -z "$implore" ] || ! [ -x "$implore" ]; then
    implore="./rest_implore"
fi

if ! [ -x "$implore" ]; then
    echo "FATAL: Could not locate rest_implore binary (or it was not executable)."
    exit 1
fi

export implore

# Verify netcat is installed/executable.
if ! [ -x "$(which nc)" ]; then
    echo "FATAL: netcat (nc) is not available."
    exit 2
fi

$implore <&0 | nc "$server" "$port"

echo ""
