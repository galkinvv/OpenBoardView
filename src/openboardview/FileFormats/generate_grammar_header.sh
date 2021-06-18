#!/bin/bash
#Use as: ./generate_grammar_header.sh GENCADFileBnf.h GENCADFileGrammar.h
outname=$2
outname=$(echo ${outname%.*})
outname=$(echo $outname | awk '{print toupper($0)}')
echo "#ifndef "$outname"_H" > $2
echo "#define "$outname"_H

/**
 *********************************************************************************
 *********************************************************************************
  WARNING THIS IS AN AUTOGENERATED FILE!!!
  Do not modify this file, but edit the:
  $1 file
  and then run:
  ./generate_grammar_header.sh $1 $2
 *********************************************************************************
 *********************************************************************************
 **/

#include \"mpc/mpc.h\"

" >> $2

echo "#define X_MACRO_PARSE_VARS\\" >> $2

grep -v SKIP_LINE_IN_GRAMMAR_GENERATOR $1 | while IFS='' read -r line || [[ -n "$line" ]]; do
    #echo "$line"
    var=$(echo "$line" | sed -re 's/([^[:space:]]*)\s*\:.*/\1/g')
    string=$var
    if [ "$var" = "float" ]; then
        var=$var"_"
    fi
    echo "  X($var, \"$string\")\\" >> $2
done
echo " /*empty string to end last continuation*/" >> $2
echo "#endif" >> $2
