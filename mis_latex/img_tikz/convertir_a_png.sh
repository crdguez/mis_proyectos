#!/bin/sh
for f in *.tex; do pandoc --lua-filter tikz2.lua -s -o "${f%.tex}.md" < "$f"; done; rm *.md;
