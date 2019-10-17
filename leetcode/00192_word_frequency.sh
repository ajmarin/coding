# Read from the file words.txt and output the word frequency list to stdout.
sed 's/ /\n/g;' words.txt  | sed '/^\s*$/D' | sort | uniq -c | sort -nr | awk '{print $2 " " $1}'