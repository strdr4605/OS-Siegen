#!/bin/bash
for file in "${1-.}"/*; do
        [ -d "${file}" ] && ((directories++))
        [ -s "${file}" ] && [ -f "${file}" ]&& ((nonEmptyFiles++))
        [ -f "${file}" ] && ((files++))
done

echo "Number of directories: ${directories}"
echo "Number of non empty files: ${nonEmptyFiles}"
echo "Number of empty files: $((files - nonEmptyFiles))"
echo "${1-.}"/*
