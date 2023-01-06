##### Extract Rule

[04/11/2022 11:03 AM] Ranjan Parthasarathy: - 
- They need a rule pack created for their applications - we can spend some time on that with the extract rules - @Kumar V

[04/11/2022 11:05 AM] Ranjan Parthasarathy: `dev-sor-service` - we can look at this and create rules to extract api call details - url, method, response time, status code

> - @Kumar V chethan can show you the IIS rules
> you will need to do some regex writing here 🙂

re2 

```
2022-11-03 16:35:13.690  INFO 1 --- [nio-8080-exec-9] com.reshamandi.advisors.HttpLogger       : HttpDetails(referer=https://occ-dev.reshamandi.com/, fullURL=http://api-dev.reshamandi.com:8080/api/search/pincodes/spec?search=(pincode==560026)&page=0&size=10&sort=officeName,desc, clientIpAddr=103.5.135.109, clientOS=Mac, clientBrowser=Chrome-107.0.0.0, userAgent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36, method=GET), Status=200, User=9353642520, HTTPRequestTime=24 millis
```

```
2022-11-03 16:35:52.137  INFO 1 --- [nio-8080-exec-3] SORRestClient                            : Received response for http://dev-userauth-service.resha-platform.svc.cluster.local:8080/api/authorize, statuscode=200 in 12.135724 millis
```

```
2022-11-03 16:35:52.125 INFO 1 --- [nio-8080-exec-6] SORRestClient : Sending request http://dev-userauth-service.resha-platform.svc.cluster.local:8080/api/authorize on null
```

```
(?P<server_ip>\S+) (?P<method>\S+) (?P<uri>\S+) (?P<uri_query>\S+) (?P<server_port>\d+) (?P<username>\S+) (?P<client_ip>\S+) (?P<user_agent>\S+) (?P<referer>\S+) (?P<status>\S+) (?P<substatus>\S+) (?P<win32_status>\S+) (?P<time_taken>\S+)
```


---
Kubernetes Extract rule from lq5955
(working perfectly, why?)
```
(?P<server_ip>\S+) (?P<method>\S+) (?P<uri>\S+) (?P<uri_query>\S+) (?P<server_port>\d+) (?P<username>\S+) (?P<client_ip>\S+) (?P<user_agent>\S+) (?P<referer>\S+) (?P<status>\S+) (?P<substatus>\S+) (?P<win32_status>\S+) (?P<time_taken>\S+)
```
```
2022-11-04T10:24:57.601933224+00:00 stdout F 10.244.1.0 - - [04/Nov/2022:10:24:57 +0000] "POST /v1/json_batch HTTP/1.1" 503 190 "-" "Fluent-Bit" 819 0.000 [lq5072-logiq-flash-9999] [] - - - - 1668c11250da6ec591d895ee604f4de9
```
---

(?P<fullURL>full\S+)
(?P<method>method\S+)
(?P<Status>Status\S+)
(?P<HTTPRequestTime>HTTPRequestTime\S+)


(?P<fullURL>([^[[:space:]]]*)\S+)
(?P<fullURL>fullURL=(.*?)\S+) - reluctant quantifier
works - (?P<fullURL>fullURL=.*?[[:space:]])


(?P<fullURL>fullURL=.*?[[:space:]]\S+) (?P<method>method=.*?\S+)

(?P<fullURL>fullURL=.*?[[:space:]]\S+) (?P<method>method=.*?\S+) (?P<Status>Status=.*?\S+)


(?P<fullURL>fullURL=.*\S+) (?P<clientIpAddr>clientIpAddr=.*\S+) (?P<clientOS>clientOS=.*\S+) (?P<clientBrowser>clientBrowser=.*\S+) (?P<method>method=.*?\S+) (?P<Status>Status=.*?\S+) (?P<UserID>User=.*?\S+) (?P<HTTPRequestTime>HTTPRequestTime=.*?.*\S+)





(?P<A1>[http|https:\/\/].*\S+) (?P<clientIpAddr>clientIpAddr=.*\S+) (?P<clientOS>clientOS=.*\S+) (?P<clientBrowser>clientBrowser=.*\S+) (?P<method>method=.*?\S+) (?P<Status>Status=.*?\S+) (?P<UserID>User=.*?\S+) (?P<HTTPRequestTime>HTTPRequestTime=.*?[millis]\S+)


https://regex101.com/r/QtXqOD/1


(?P<timestamp>[0-9]{4}-[0-9]{1,2}-[0-9]{1,2} [0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}\.[0-9]{1,6}[ \t]+) (?P<severity>\S+) .* fullURL=(?P<fullURL>(.*\S+)) (?P<clientIpAddr>clientIpAddr=.*\S+) (?P<clientOS>clientOS=.*\S+) (?P<clientBrowser>clientBrowser=.*\S+) (?P<method>method=.*?\S+) (?P<Status>Status=.*?\S+) (?P<UserID>User=.*?\S+) (?P<HTTPRequestTime>HTTPRequestTime=.*?.*\S+)


(?P<timestamp>[0-9]{4}-[0-9]{1,2}-[0-9]{1,2} [0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}\.[0-9]{1,6}[ \t]+) (?P<severity>\S+) (?P<fullURL>([^http].*\S+)) (?P<clientIpAddr>clientIpAddr=.*\S+) (?P<clientOS>clientOS=.*\S+) (?P<clientBrowser>clientBrowser=.*\S+) (?P<method>method=.*?\S+) (?P<Status>Status=.*?\S+) (?P<UserID>User=.*?\S+) (?P<HTTPRequestTime>HTTPRequestTime=.*?.*\S+)



(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+)









```
(http|ftp|https):\/\/([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:\/~+#-]*[\w@?^=%&\/~+#-])
```

(?P<fullURL>(http):\/\/([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:\/~+#-()]*[\w@?^=%&\/~+#-]))



(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+) (?P<fullURL>((http):\/\/([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:\/~+#-()]*[\w@?^=%&\/~+#-]))) 




(?P<clientIpAddr>=\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b)


(?P<clientOS>=(Mac|Windows|Linux|Android)\S+)

(?P<clientBrowser>(?i)(Chrome|Firefox|Safari)-\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\S+)

(?P<method>(GET|POST|PUT|DELETE|HEAD|CONNECT|OPTIONS|TRACE)+)

(?P<Status>(\d{3}))

(?P<User>\d{10})

(?P<HTTPRequestTime>\d{1,10} [millis]\S+)

```
2022-11-03 16:25:31.012  INFO 1 --- [nio-8080-exec-8] com.reshamandi.advisors.HttpLogger       : HttpDetails(referer=https://occ-dev.reshamandi.com/, fullURL=http://api-dev.reshamandi.com:8080/api/user/search/role?role=ADMINISTRATOR,COperationsAgent,COCOON_PROCUREMENT_EXEC,COCOON_SALES_EXEC,COperationsManager,COCOON_PROCUREMENT_MANAGER,COCOON_SALES_MANAGER,CCenterAgent,CCenterManager,FarmInputAgent,FarmInputManager,CottonAgent,CottonManager,PupaeAgent,PupaeManager&sort=createdDate,desc, clientIpAddr=103.5.135.109, clientOS=Mac, clientBrowser=Chrome-107.0.0.0, userAgent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36, method=GET), Status=200, User=8342456758, HTTPRequestTime=51 millis
```














(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+) .*(?P<fullURL>(http:\/\/([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:\/~+#-()]*))\S+) .*(?P<clientIpAddr>=\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b\S+) .*(?P<clientOS>=(Mac|Windows|Linux|Android)\S+) .*(?P<clientBrowser>(Chrome|Firefox|Safari)-\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\S+) .*(?P<method>(GET|POST|PUT|DELETE|HEAD|CONNECT|OPTIONS|TRACE)\S+) (?P<Status>Status=.*?\S+) .*(?P<User>\d{10}\S+) .*(?P<HTTPRequestTime>\d{1,9} [millis]\S+)




(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+) .*(?P<fullURL>(http:\/\/([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:\/~+#-()]*))\S+) .*(?P<clientIpAddr>=\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b\S+) .*(?P<clientOS>=(Mac|Windows|Linux|Android)\S+) .*(?P<clientBrowser>(Chrome|Firefox|Safari)-\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\S+) .*(?P<method>(GET|POST|PUT|DELETE|HEAD|CONNECT|OPTIONS|TRACE)\S+) (?P<Status>Status=.*?\S+) .*(?P<User>\d{10}\S+) .*(?P<HTTPRequestTime>\d{1,9} [millis]\S+)






https://regex101.com/r/9RJMFO/1

https://regex101.com/delete/ctP1potU14KioAnhQxzzfVMg












(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+)


Finale
(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+) referer=(?P<referer>[^ ]+), fullURL=(?P<fullURL>[^ ]+), clientIpAddr=(?P<clientIpAddr>[^ ]+), clientOS=(?P<clientOS>[^ ]+), clientBrowser=(?P<clientBrowser>[^ ]+), userAgent=(?P<userAgent>(([a-zA-Z]+/[0-9]+[\.]*[0-9]+ )(\(.+\))? ([a-zA-Z]+/[0-9]+[\.]+[0-9]+[\.]+[0-9]+[\.]+[0-9]+ [a-zA-Z]+/[0-9]+[\.]+[0-9]{2})?)), method=(?P<method>([A-Z]{3,4}))[)], Status=(?P<Status>[0-9]{3}), User=(?P<User>([0-9]{10})), HTTPRequestTime=(?P<HTTPRequestTime>([0-9]{1,10} [a-z]{6}))





(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+).*referer=(?P<referer>[^ ]+), fullURL=(?P<fullURL>[^ ]+), clientIpAddr=(?P<clientIpAddr>[^ ]+), clientOS=(?P<clientOS>[^ ]+), clientBrowser=(?P<clientBrowser>[^ ]+), userAgent=(?P<userAgent>([a-zA-Z]+/[0-9]+[\.]+[0-9]+ \(.+\)? [a-zA-Z]+/[0-9]+[\.]+[0-9]+[\.]+[0-9]+[\.]+[0-9]+ [a-zA-Z]+/[0-9]+[\.]+[0-9]+?)), method=(?P<method>([A-Z]+))[)], Status=(?P<Status>[0-9]+), User=(?P<User>([0-9]+)), HTTPRequestTime=(?P<HTTPRequestTime>([0-9]+ [a-z]+))





finale - https://regex101.com/r/U2Qhqd/1
delete - https://regex101.com/delete/b81aEsCNzO9UYHDoh6VCwQnp





> Replaced `{...}` with `+`, worked perfectly.


---

url - (?P<fullURL>\S+)
method - (?P<method>\S+)
response time - (?P<HTTPRequestTime>\S+)
status code - (?P<Status>\S+) || (?P<statuscode>\S+)
client IP addr - (?P<clientIpAddr>\S+)
user ID - (?P<User>\S+)

(?P<fullURL>\S+) (?P<method>\S+) (?P<HTTPRequestTime>\S+) (?P<Status>\S+)

Name
Group
Description
Namespace
ApplicationMatch
Pattern




kinds of single-character expressions 

any character, possibly including newline (s=true) : .          
character class: [xyz]
negated character class: [^xyz]
ASCII character class: [[:alpha:]] 
Unicode char class (one-letter name): \pN
Unicode char class: \p{Greek}

Composites

xy : x followed by y
x|y : x or y (prefer x)

---
REGEX

HTTP: 

```
(?:http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+)
```


IP addresses: 

```
(\d+\.\d+\.\d+\.\d)
```







(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+).*referer=(?P<referer>[^ ]+), fullURL=(?P<fullURL>[^ ]+), clientIpAddr=(?P<clientIpAddr>[^ ]+), clientOS=(?P<clientOS>[^ ]+), clientBrowser=(?P<clientBrowser>[^ ]+), userAgent=(?P<userAgent>([a-zA-Z]+/[0-9]+[\.]+[0-9]+ \(.+\)? [a-zA-Z]+/[0-9]+[\.]+[0-9]+[\.]+[0-9]+[\.]+[0-9]+ [a-zA-Z]+/[0-9]+[\.]+[0-9]+?)), method=(?P<method>([A-Z]+))[)], Status=(?P<Status>[0-9]+), User=(?P<User>([0-9]+)), HTTPRequestTime=(?P<HTTPRequestTime>([0-9]+ [a-z]+))




[a-z]{4}-[a-z]{5}\/\d+\.\d+\+
---





I did a simpler rule for the 3 fields we need - 
".*fullURL=(?P<full_url>[^ ]+).*method=(?P<method>([A-Z]+))[)], Status=(?P<status_code>[0-9]+), User=(?P<user>([^ ,]+)), HTTPRequestTime=(?P<http_request_time>([0-9]+))"

[09/11/2022 5:07 AM] Ranjan Parthasarathy: gets url, method request time, and status



----

Name: API_Extract_1 and 2

applicationMatch: .*

description: Example Rule to parse API trace

condition: (Namespace=='rm_development:resha-platform') && (AppName=~'.*')

patternLabels: 









