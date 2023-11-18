#!/bin/bash

path=$1
dest=$2

find "$path" -type f -print0 | while IFS= read -r -d '' file
do 
    ext="${file##*.}"
    year=$(stat -c "%y" "$file" | cut -d '-' -f 1)
    if [[ ${ext,,} =~ ^(mp4|avi|3gp|mpeg|mkv|wmv|mov)$ ]]; then
        mkdir -p "$dest/$year/videos" && cp "$file" "$dest/$year/videos"
    elif [[ ${ext,,} =~ ^(jpg|jpeg|png)$ ]]; then
        w=$(identify -format "%w" "$file")
        if [ $w -gt 1024 ]
        then 
            mkdir -p "$dest/$year/photos" && convert "$file" -resize "1024x" "$dest/$year/photos/$(basename $file)"
        else 
            mkdir -p "$dest/$year/photos" && cp "$file" "$dest/$year/photos"
        fi
    fi
done
