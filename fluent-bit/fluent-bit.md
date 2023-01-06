
location of conf file

> cd /snap/fluent-bit/17/etc/fluent-bit/fluent-bit.conf

https://docs.logiq.ai/integrations/fluent-bit/fluent-bit-installation-on-ubuntu

> locate fluent-bit | grep conf


```
 9626  gedit fluent-bit.conf
 9627  sudo systemctl status
 9628  sudo systemctl status | grep fluent
 9629  sudo systemctl status snap.fluent-bit.service.service
 9630  sudo systemctl stop snap.fluent-bit.service.service
 9631  sudo systemctl status snap.fluent-bit.service.service
```


>  sudo systemctl status snap.fluent-bit.service.service

**after changing namespace, appname and host and all details, do**
> sudo systemctl restart snap.fluent-bit.service.service

**TO stop fluent-bit**
>  sudo systemctl stop snap.fluent-bit.service.service


```
[SERVICE]
    Flush                      1
    Parsers_File              /etc/td-agent-bit/parsers.conf
    Log_Level                 error
    Storage.type              filesystem
    Storage.path              /var/log/flb_storage_
    Buffer storage.sync       normal
    Storage.checksum          On
    Storage.backlog.mem_limit 700kb
    Storage.metrics           On
    
[INPUT]
    Name              tail
    Path              /home/tito/Documents/test-logs-to-send/test.log
    Path_Key          filename
    Tag               logiq
    Buffer_Max_Size   1024k
    Read_from_Head    On
    Mem_Buf_Limit     1MB
    Refresh_Interval  5
    Storage.type      filesystem

[FILTER]
    Name               record_modifier
    Match              logiq
    Record cluster_id  flash

[FILTER]
    Name             record_modifier
    Match            logiq
    Record namespace syslog_ng_kv

[FILTER]
    Name            record_modifier
    Match           logiq
    Record app_name reshamandi-logs-test

[FILTER}
    Name            throttle
    Match           *
    Rate            700
    Window          300
    Interval        1s

[OUTPUT]
    Name          http
    Match         *
    Host          lq5955.logiq.ai
    Port          514
    URI           /v1/json_batch
    Format        json
    tls           off
    tls.verify    off
    net.keepalive off
    compress      gzip
    Header Authorization Bearer eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3MiOltdLCJhdWQiOiJsb2dpcS1jbGllbnRzIiwianRpIjoiOWNmYzMzYzEtNWI5MC00ZGQ2LWE4ZmMtMDYxZjVjZmZlMDQxIiwiaWF0IjoxNjY3OTgxOTI3LCJpc3MiOiJsb2dpcS1jb2ZmZWUtc2VydmVyIiwibmJmIjoxNjY3OTgxOTI3LCJzdWIiOiJmbGFzaC1hZG1pbkBmb28uY29tIiwiVWlkIjoyLCJyb2xlIjoiYWRtaW4ifQ.RYa32OrVYzBC1jeIYWv_sRsPwkEZDnKw3HUzdNoLzYWZHk_usrhT-IatIpn-85LBxukkrx30lpvATLdMJ-xngnSFsNYrHQgophRfzmeZYZIuQ_NaZzb0IasJofdaMvcJ99Uv-L0GRRfzDIc7RYSLj8ktuEPnBYyfscgUJ411tTuHxVNjjw0e10oH268LuAfl_FN6XpMloWEbgDI6jOlKbbQkZP9nK3nLhPsDsF-Z8P5Q0R47xfzXBxxmvJLlZDGS8OyzBqv__xYFr2ODXpE2oWgxFqTz1EYo16DtArE4HqjjGXAyvYqBZwd_SjM1CRZ2t_qY09lc8khsD_IgsPDxxw
```