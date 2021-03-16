#!/usr/bin/env bash

valgrind --tool=memcheck ./meta-game-fun --leak-check=full a.out > log-valgrind.txt 2>&1
