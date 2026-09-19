#!/bin/bash

sleep 0.1 ; (echo -n $(( 1000 + RANDOM % 9999 )) | nc localhost 8888)