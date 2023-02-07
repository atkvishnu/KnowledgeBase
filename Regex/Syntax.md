
(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6}[ \t]+) (?P<severity>\S+).*referer=(?P<referer>[^ ]+), fullURL=(?P<fullURL>[^ ]+), clientIpAddr=(?P<clientIpAddr>[^ ]+), clientOS=(?P<clientOS>[^ ]+), clientBrowser=(?P<clientBrowser>[^ ]+), userAgent=(?P<userAgent>([a-zA-Z]+/[0-9]+[\.]+[0-9]+ \(.+\)? [a-zA-Z]+/[0-9]+[\.]+[0-9]+[\.]+[0-9]+[\.]+[0-9]+ [a-zA-Z]+/[0-9]+[\.]+[0-9]+?)), method=(?P<method>([A-Z]+))[)], Status=(?P<Status>[0-9]+), User=(?P<User>([0-9]+)), HTTPRequestTime=(?P<HTTPRequestTime>([0-9]+ [a-z]+))


(?P<timestamp>\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{1,6} \+\d{2}:\d{2}) \[(?P<status>\S+)\] User : (?P<userid>[^ ]+) 
