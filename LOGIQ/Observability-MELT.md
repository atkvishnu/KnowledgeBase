[LINK1](https://newrelic.com/sites/default/files/2022-03/melt-101-four-essential-telemetry-data-types.pdf)

## 1. METRICS

To put it simply, metrics are numeric measurements. Metrics can include: • A numeric status at a moment in time (like CPU % used) • Aggregated measurements (like a count of events over a one-minute time, or a rate of events-per-minute) The types of metric aggregation are diverse (for example, average, total, minimum, maximum, sum-of-squares), but all metrics generally share the following traits: • A name • A timestamp • One or more numeric values A specific example of a metric might look like this: For the minute of 3:34-3:35pm on 2/21/2019, there were three purchases totaling $2.75. This metric would be represented in a database as a single row of data.

## 2. EVENTS

Conceptually, an event can be defined as a discrete action happening at a moment in time. So, to start with our vending machine analogy, we could define an event to capture the moment when someone makes a purchase from the machine: At 3:34pm on 2/21/2019, a bag of BBQ chips was purchased for $1.

We could also define events for actions that do not include a customer, such as when a vendor refilled the machine, or for states that are derived from other events, such as an item becoming “sold out” after a purchase. You can choose which attributes are important to send when defining an event. There’s no hard- -and-fast rule about what data an event can contain—you define an event as you see fit.

**How are events used?** Events are valuable, because you can use them to confirm that a particular action occurred at a particular time. For example, we may want to know the last time our machine was refilled. Using events, we can look at the most recent timestamp from the Refilled event type and answer this question immediately. Because events are basically a history of every individual thing that happened in your system, you can roll them up into aggregates to answer more advanced questions on the fly.

# 3. LOGS

It’s not a stretch to say that logs are the original data type. In their most fundamental form, logs are essentially just lines of text a system produces when certain code blocks get executed. Developers rely on them heavily in order to troubleshoot their code and to retroactively verify and interrogate the code’s execution. In fact, logs are incredibly valuable for troubleshooting databases, caches, load balancers, or older proprietary systems that aren’t friendly to inprocess instrumentation, to name a few. Similar to events, log data is discrete—it’s not aggregated—and can occur at irregular time intervals. Logs are also usually much more granular than events. In fact, one event can correlate to many log lines.

Log data is sometimes unstructured, and therefore hard to parse in a systematic way; however, these days you’re more likely to encounter “structured log data” that is formatted specifically to be parsed by a machine. Structured log data makes it easier and faster to search the data and derive events or metrics from the data.

# 4. TRACES

Traces—or more precisely, “distributed traces”—are samples of causal chains of events (or transactions) between different components in a microservices ecosystem. And like events and logs, traces are discrete and irregular in occurrence.

Let’s say our vending machine accepts cash and credit cards. If a user makes a purchase with a credit card, the transaction has to flow through the vending machine via a backend connection, contact the credit card company, and then contact the issuing bank.

How do traces work? Traces that are stitched together form special events called “spans”; spans help you track a causal chain through a microservices ecosystem for a single transaction. To accomplish this, each service passes correlation identifiers, known as “trace context,” to each other; this trace context is used to add attributes on the span.

**When should you use traces?** Trace data is needed when you care about the relationships between services/entities. If you only had raw events for each service in isolation, you’d have no way of reconstructing a single chain between services for a particular transaction. Additionally, applications often call multiple other applications depending on the task they’re trying to accomplish; they also often process data in parallel, so the call-chain can be inconsistent and timing can be unreliable for correlation. The only way to ensure a consistent call-chain is to pass trace context between each service to uniquely identify a single transaction through the entire chain.























