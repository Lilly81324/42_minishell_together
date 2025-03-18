#!/bin/bash

SHLVL_VALUE=0
echo "Test: $SHLVL_VALUE"
bash <<EOF
export SHLVL=$SHLVL_VALUE
bash
echo $SHLVL
exit
exit
EOF

SHLVL_VALUE=5
echo "Test: $SHLVL_VALUE"
bash <<EOF
export SHLVL=$SHLVL_VALUE
bash
echo $SHLVL
exit
exit
EOF
