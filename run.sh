#!/bin/bash
# cp sml.g4 java/sml.g4
# cd java
# java -jar /usr/local/lib/antlr-4.7-complete.jar sml.g4
# javac *.java
# java org.antlr.v4.gui.TestRig sml commandSeq -gui < ../input.txt
# rm *class
# cd ..
java -jar /usr/local/lib/antlr-4.7-complete.jar -Dlanguage=Python3 sml.g4 -visitor
time python3 -O sml.py input.txt