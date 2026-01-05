SOURCE="$1"
OUTPUT="a.out"

if [ -z "$SOURCE" ]; then
    echo "Usage: ./run.sh file.cpp"
    exit 1
fi

g++-14 -std=c++23 -O2 \
    -o "$OUTPUT" "$SOURCE"

if [ $? -eq 0 ]; then
    echo -e "\n--- Running $OUTPUT ---\n"
    ./"$OUTPUT"
else
    echo -e "\nCompilation failed."
fi