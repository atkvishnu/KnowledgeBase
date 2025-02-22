
sudo /opt/fluent-bit/bin/fluent-bit -c /etc/fluent-bit/fluent-bit.conf --verbose --output stdout

systemctl status fluent-bit.service
systemctl stop fluent-bit.service
systemctl start fluent-bit.service
systemctl restart fluent-bit.service


sudo /opt/fluent-bit/bin/fluent-bit -c /etc/fluent-bit/fluent-bit.conf --log_file=/etc/fluent-bit/fluent_bit_logs/latest.log --verbose




### Debug && Log files stored in `/tmp/fluentbit.log` 
tail /tmp/fluentbit.log

journalctl | grep "fluent"



# NOTE:
- If ingest not happening, or if fluent bit is not able to send to destination then:
	- To debug, change log level in SERVICE section.
	- Something must be wrong with the payload which is why it is not able to send the logs.