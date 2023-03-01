> Each flow log line in OCI VCN flow logs contains a set of data fields that provide information about the network traffic for a particular flow. These fields include the source and destination IP addresses, the protocol used, the source and destination ports, the number of bytes transferred, and the number of packets transferred.

1.  Flow Logs Overview Graph: This graph provides an overview of the network traffic in your VCN, including the number of flows, packets, and bytes for both inbound and outbound traffic.
2. Top Talkers Graph: This graph identifies the top talkers in your VCN, showing the source and destination IP addresses that have the most traffic. This graph identifies the top talkers in your VCN, showing the source and destination IP addresses that have the most traffic. To create the Top Talkers graph, OCI analyzes the flow logs to identify the source and destination IP addresses for each flow. Then, it aggregates the flows by IP address and calculates the total number of packets and bytes transferred between each pair of IP addresses. Finally, it sorts the results by the amount of traffic and displays the top talkers in descending order. The Top Talkers graph provides valuable insights into the behavior of your applications and services, allowing you to identify which IP addresses are generating the most traffic in your VCN. This information can be used to optimize network performance, troubleshoot issues, and identify potential security threats. For example, if you notice an unusual amount of traffic coming from a particular IP address, it could indicate a compromised system or a potential DDoS attack, and you may need to investigate further.
3. Traffic by Protocol Graph: This graph shows the breakdown of traffic by protocol, such as TCP, UDP, or ICMP. OCI analyzes the flow logs to identify the protocol used for each flow. It then aggregates the flows by protocol and calculates the total number of packets and bytes transferred for each protocol. Finally, it displays the results in a bar chart, with each bar representing a different protocol and the height of the bar indicating the amount of traffic. The Traffic by Protocol graph provides valuable insights into the types of traffic that are flowing in and out of your VCN. For example, if you notice that a large percentage of the traffic is using the TCP protocol, it could indicate that a lot of data is being transferred between applications, while a high number of ICMP packets could indicate network connectivity issues. This information can be used to optimize network performance, troubleshoot issues, and identify potential security threats, such as an unusual amount of traffic using an uncommon or unauthorized protocol.
4. Traffic by Port Graph: This graph shows the breakdown of traffic by port, allowing you to identify which ports are being used the most.
5. Security Rule Effectiveness Graph: This graph shows the effectiveness of your security rules by displaying the number of allowed and denied flows.
6. Time Series Graph: This graph displays the network traffic over time, allowing you to identify trends and patterns.
These dashboard graphs provide a comprehensive view of your VCN network traffic and allow you to quickly identify potential security issues, optimize network performance, and gain insights into the behavior of your applications and services.

---

## data.packets

"data.packets": This field provides the number of packets transmitted in the flow, which can be used as the y-axis for a counter.
You could use this value to track overall network activity, or to monitor the behavior of specific hosts or applications.
The "packets" field refers to the number of packets that were transferred in the flow. A packet is a unit of data that is transmitted over a network, and it contains information such as the source and destination IP addresses, the protocol used, and the payload data.
By analyzing the number of packets transferred in a flow, you can gain insights into the amount of data that was transferred and the behavior of your applications and services. For example, if you notice an unusually high number of packets for a particular flow, it could indicate a potential DDoS attack or a misconfigured application that is generating excessive network traffic.
you could plot the number of packets transmitted over a given time period to track the overall volume of network traffic


---

## data.bytesout

-   "data.bytesOut": This field provides the number of bytes sent out by the source in the flow, which can also be used as the y-axis for a counter.
refers to the number of bytes that were sent out (or transmitted) by the source in the flow.
The "bytesout" field refers to the number of bytes that were sent out by the source in the flow. This information can be used to determine the amount of data that was transmitted by a particular source in the network flow.
By analyzing the number of bytes transferred in a flow, you can gain insights into the amount of data that was transferred and the behavior of your applications and services. For example, if you notice a high number of bytes transferred in a particular flow, it could indicate a data-intensive application or service that is generating significant network traffic. This information can be used to optimize network performance, troubleshoot issues, and identify potential security threats.
plot the number of bytes sent out by the source to track the bandwidth usage of a particular application or service.

---

## data

"data" field contains information about the network traffic for a particular flow.

---

## data.status

This field represents the status of the flow, such as "OK" or "REJECT". You could use this value to monitor the number of rejected flows over time.

---

## data.action
represents the action taken on the flow by a network security rule or policy. This field is a string value that can be one of the following values:

-   "ACCEPT": The flow was allowed to proceed.
-   "DROP": The flow was silently dropped, with no notification sent to either the source or destination of the flow.
-   "REJECT": The flow was rejected, and a notification was sent to the source of the flow indicating that the flow was not allowed to proceed.
-   "LOG": The flow was logged, but no action was taken on it.
This field can be useful for monitoring security policy violations and identifying potential security threats. For example, if you see a large number of flows being rejected by a security policy, you may want to investigate the source of those flows to determine whether they represent a potential security threat.

---

## data.protocolName

represents the protocol used by the flow.
For example, the following values are commonly used for different protocols:

-   1: ICMP (Internet Control Message Protocol)
-   6: TCP (Transmission Control Protocol)
-   17: UDP (User Datagram Protocol)

By analyzing the `data.protocol` field, you can gain insight into the types of traffic that are flowing through your network. This information can be useful for troubleshooting network issues, identifying potential security threats, and optimizing network performance.