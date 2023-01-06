install nvm

nvm curl -o-https://................./nvm-sh/nvm/v0.37.2/install.sh | bash
nvm install 12
sudo apt install libmysqlclient-dev python3.8-dev gcc g++ libsasl2-dev python3-venv
python3 -m venv env
pip install -r requirements.txt -r requirements_dev.txt
pip install -r requirements_all_ds.txt
source env/bin/activate
bin/run ./manage.py database create-table (or create-tables)

export REDIS_HOST=localhost
export POSTGRES_HOST=localhost
export JWE_AUTH_COOKIE_PRIVATE_KEY=/home/tito/go/src/bitbucket.org/logiqclient/flash/certs/june-2019/Syslog.key
export JWE_AUTH_COOKIE_PUBLIC_KEY=/home/tito/go/src/bitbucket.org/logiqclient/flash/certs/june-2019/Syslog.crt
bin/run ./manage.py runserver --debugger --reload --host 0.0.0.0
bin/run celery worker --app=redash.worker --beat -Qscheduled_queries,queries,celery -c2
alias serve = 'cdfe && npm run build && npm start'

dependencies
ser
cel
prom
serve

./flash-test-framework -mps 1000 -idur 50 -ingest --jsonb --namespace ns3 --ApplicationName app3 --host http://localhost:9999


cdbe && go build -tags "sqlite_vtable sqlite_json" && ./flash --config examples/configs/tito/config-free-tito.yaml --runtime_folder=/home/tito/.data --load-from-file=true -pg_max_open_Conns 50 -postgres_timeout 20s --all --disable-auth-interceptor -prometheus-host http://localhost:9090 -event_rule_path=/config --localhost=true
