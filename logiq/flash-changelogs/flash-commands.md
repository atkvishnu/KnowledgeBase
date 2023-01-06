docker create --name fredis -p 6379:6379 redis


docker create --name fminio \
 -p 9000:9000 \
 -p 9001:9001 \
 -e "MINIO_ROOT_USER=minioadmin" \
 -e "MINIO_ROOT_PASSWORD=minioadmin" \
 minio/minio server /data --console-address ":9001"

docker volume create postgres

docker run --name postgres -p 5432:5432 -e POSTGRES_PASSWORD=postgres  -v postgres:/var/lib/postgresql/data -d postgres:13



# Command to run flash on localhost

- Change paths in: `examples/configs/tito/config-free-vishnu.yaml`

go run --tags "sqlite_vtable sqlite_json" flash.go -config examples/configs/tito/config-free-vishnu.yaml --runtime_folder=/home/tito/.data/flash --load-from-file=true -pg_max_open_Conns 50 -postgres_timeout 20s --all --disable-auth-interceptor --localhost true







