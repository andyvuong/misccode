cd data

url=someurlhere
tag=crawl_

for((n=40000;n<50001;n++)) 
do
    out="$tag""$n".html
    result= wget --tries=3 -c -O $out "$url"
done
