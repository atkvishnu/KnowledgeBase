# Microservices

**Microservice** is a small, loosely coupled distributed service.

Microservices, or microservices architecture, is **an approach to application development in which a large application is built from modular components or services**.

A **microservice** architecture – a variant of the [service-oriented architecture](https://en.wikipedia.org/wiki/Service-oriented_architecture "Service-oriented architecture") (SOA) structural style – arranges an application as a collection of [loosely-coupled](https://en.wikipedia.org/wiki/Loose_coupling "Loose coupling") services. In a microservices architecture, services are fine-grained and the protocols are [lightweight](https://en.wikipedia.org/wiki/Lightweight_protocol "Lightweight protocol"). The goal is that teams can bring their services to life independent of others. Loose coupling reduces all types of dependencies and the complexities around it, as service developers do not need to care about the users of the service, they do not force their changes onto users of the service.
Therefore it allows organizations developing software to grow fast and big, as well as use off-the-shelf services easier. Communication requirements are reduced. These benefits come at a cost to maintaining the decoupling. Interfaces need to be designed carefully and treated as a public API. One technique that is used is having multiple interfaces on the same service, or multiple versions of the same service, so as to not disrupt existing users of the code.

Microservice architecture evolved as a solution to the scalability, independently deployable, and innovation challenges with Monolithic architecture (Monolithic applications are typically huge – more than 100,000 lines of code).
Microservices allows you to take a large application and decompose or break it into easily manageable small components with narrowly defined responsibilities.

-   Services in a microservice architecture are often [processes](https://en.wikipedia.org/wiki/Process_(computing) "Process (computing)") that communicate over a [network](https://en.wikipedia.org/wiki/Computer_network "Computer network") to fulfill a goal using technology-agnostic [protocols](https://en.wikipedia.org/wiki/Communications_protocol "Communications protocol") such as HTTP.
-   Services are organized around business capabilities.
-   Services can be implemented using different [programming languages](https://en.wikipedia.org/wiki/Programming_language "Programming language"), [databases](https://en.wikipedia.org/wiki/Database "Database"), hardware and software environments, depending on what fits best.
-   Services are small in size, messaging-enabled, bounded by contexts, autonomously developed, independently deployable, decentralized and [built](https://en.wikipedia.org/wiki/Build_automation "Build automation") and [released with automated processes](https://en.wikipedia.org/wiki/Application_release_automation "Application release automation").
Lends itself to a [continuous delivery](https://en.wikipedia.org/wiki/Continuous_delivery "Continuous delivery") software development process. A change to a small part of the application only requires rebuilding and redeploying only one or a small number of services.


A microservice is not a layer within a monolithic application (example, the web controller, or the backend-for-frontend)

Adheres to principles such as [fine-grained](https://en.wikipedia.org/wiki/Service_granularity_principle "Service granularity principle") [interfaces](https://en.wikipedia.org/wiki/Software_interface "Software interface") (to independently deployable services), business-driven development (e.g. [domain-driven design](https://en.wikipedia.org/wiki/Domain-driven_design "Domain-driven design"))

Applications: 
- cloud-native applications
- serverless computing
- applications using lightweight container deployment.
- 