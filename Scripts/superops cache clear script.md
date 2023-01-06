Go into namespace logiq-flash-0 and clear all files in cache:
```
exec -it logiq-flash-0 -c logiq-flash -- bash -c "du -s -h /flash/db/keycache && cd /flash/db/keycache && ls | xargs rm -f && du -s -h /flash/db/keycache"
```


Go into each ns one by one, and clear all files in the cache:
```
for i in `seq 0 16`; do kubectl -n superops exec -it logiq-flash-$i -c logiq-flash -- bash -c "du -s -h /flash/db/keycache && cd /flash/db/keycache && ls | xargs rm -f && du -s -h /flash/db/keycache"; echo "Done with logiq-flash-$i"; done
```
